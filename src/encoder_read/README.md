# encoder_read package

![ROSVersion](https://img.shields.io/badge/ROS-melodic-blue)
![build](https://img.shields.io/badge/build-passed-success)

Implemented with [ROS (Robot Operating System)](http://wiki.ros.org/) and C++.  
___
# Interact with the node
The following package, once launched with the ```rosrun``` command, allows you to capture and manage to display the messages sent on the topic ```/encoder_read```. A typical output generated by this node is the following:
```bash
[ INFO] [1605637728.928077889]: Receiving info about joints: 
[ INFO] [1605637728.930402331]: Joint 0:
	x - 0.4
	y - 0.5
	z - 0.1
[ INFO] [1605637728.930454168]: Joint 1:
	x - 0.2
	y - 0.5
	z - 0.2
[ INFO] [1605637728.930493623]: Joint 2:
	x - 0.0
	y - 0.1
	z - 0.2
[ INFO] [1605637728.930526974]: Joint 3:
	x - 0.5
	y - 0.6
	z - 1.0
[ INFO] [1605637728.930556938]: Joint 4:
	x - 1.1
	y - 0.7
	z - 0.7
[ INFO] [1605637728.930583859]: Joint 5:
	x - 0.8
	y - 0.8
	z - 0.2
```
____
##### Vittorio Fina