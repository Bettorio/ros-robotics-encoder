# ros-robotics-encoder

![ROSVersion](https://img.shields.io/badge/ROS-melodic-blue)
![build](https://img.shields.io/badge/build-passed-success)

Implemented with [ROS (Robot Operating System)](http://wiki.ros.org/) and C++.  
___
# The task
The following is the task for which this repository was developed.

> Implement a publisher that simulates a set of sensors for encoder readings - *position of 6 joints* -
> and a subscriber that simulates a set of controllers that prints such readings to stdout.
___
# The packages
The implemented packages are now described, including the operations and files created within them.

This was possible thanks to the command provided by the ```catkin``` environment for creating packages and the specific dependencies for each of them.

```shell
catkin create pkg pkg_name --catkin-deps deps_list
```

### 1 - Encoder_msgs
This package is dedicated to generating customized messages for the task to be performed. In particular, inside the /msg directory it contains two files with the extension .msg created specifically to perform this exercise.
```shell
ls /src/encoder_msgs/msg
> EncoderDataArray.msg  EncoderData.msg
```
The **EncoderData.msg** deals with the message related to the single joint, which is then managed by the publisher. In fact, it contains three ```float32``` values ​​that represent the triple (x, y, z). Here what it contains:
```shell
float32 x
float32 y
float32 z
```
The **EncoderDataArray.msg**, on the other hand, manages the entire group of joints, which is why it is declared as an array of EncoderData, as we can see from its contents:
```shell
EncoderData[] data
```

### 2 - Encoder_read
This package manages the arrival of messages on the topic where the messages are published by the publisher and interprets them so that it can show them on the screen through stdout. In this case it was necessary to specify the dependency on the ```encoder_msgs``` package since the messages handled by this node are in that format. So to create the package it was necessary to send a command as follows:
```shell
catkin create pkg encoder_read --catkin-deps roscpp std_msgs encoder_msgs
```

### 3 - Encoder_write
This package acts as a publisher of the joint information passed as input, in groups of three. A package with dependencies on ```encoder_msgs``` has been created, since the messages to be published are contained in that package. So to create the package it was necessary to send a command as follows:
```shell
catkin create pkg encoder_write --catkin-deps roscpp std_msgs encoder_msgs
```
___
# The build
To build the developed architecture it was first necessary to modify the relative CMakeLists.txt of the three nodes above so that the compiler can recognize any executables and, in our case, messages to be generated.

In particular, what has been changed for the node containing the two .msg files is the message generation method, as reported in the following code excerpt:
```txt
add_message_files(
  FILES
  EncoderData.msg
  EncoderDataArray.msg
)
```
For the two publisher / subscriber nodes, on the other hand, it is necessary to specify the executable and the folder in which it is contained and to specify in particular the node to which the catkin libraries are to be connected:
```txt
add_executable(${NODE_NAME} src/main.cpp)
---
target_link_libraries(${NODE_NAME}
  ${catkin_LIBRARIES}
)
```

After all these necessary changes it is possible to run the build command to verify that everything is compiled correctly.
```shell
cd ros-robotics-encoder/
catkin build
```
___
###### Vittorio Fina