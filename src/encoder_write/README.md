# encoder-write package

![ROSVersion](https://img.shields.io/badge/ROS-melodic-blue)
![build](https://img.shields.io/badge/build-passed-success)

Implemented with [ROS (Robot Operating System)](http://wiki.ros.org/) and C++.
___
# Interact with the node
The node design, once launched, allows you to enter the joint values ​​to be broadcast on the topic ```/encoder_read``` as a float which are then managed and put together to transmit the EncoderData array. A typical output for entering values ​​is the following:
```bash
[ INFO] [1605635857.166106742]: Intializing node /encoder_writer as a publisher
Insert x - y - z for joint 0 -> 1.2 2.0 2.1
Insert x - y - z for joint 1 -> 1.0 1.2 0.6
Insert x - y - z for joint 2 -> 2.0 1.5 0.4
Insert x - y - z for joint 3 -> 2.5 1.1 1.0
Insert x - y - z for joint 4 -> 0.6 0.2 0.5
Insert x - y - z for joint 5 -> 0.2 0.6 0.6
[ INFO] [1605635912.254110925]: Publishing encoder info on topic /encoder_read ...
```
___
##### Vittorio Fina