/* 
 * -------------------------------------------------------------------
 * This module has been developed as an exercise for Robotics course
 * @ UniSa.
 *
 * Title:   main.cpp
 * Author:  Vittorio Fina
 * Date:    Nov 23, 2020
 *
 * This module implements a talker (subscriber) that heards messages
 * from the topic "/encoder" in order to simulate a set of controllers
 * for encoder readings.
 *
 * -------------------------------------------------------------------
 */

#include "ros/ros.h"
#include "encoder_msgs/EncoderDataArray.h"
#include "encoder_msgs/EncoderData.h"
#include <stdlib.h>

using namespace std;

/*
 * This callback provides a readable output of the messages captured, showing
 * joints coordinates in order.
 */
void chatterCallback(const encoder_msgs::EncoderDataArray::ConstPtr& msg);

int main (int argc, char **argv) {

    /*
     * The ros::init() function need to see argc and argv in order 
     * to take eventually argoments from command line.
     * The third argument of the init() is the name of the node
     * 
     * NodeHandle is the main access point to communication with ROS system.
     */
    ros::init(argc, argv, "encoder_reader");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("encoder_read", 1, chatterCallback);

    ros::spin();

    return 0;
}

void chatterCallback(const encoder_msgs::EncoderDataArray::ConstPtr& msg) {

    std::ostringstream ss;
    ss << std::endl << " ---------- Reading joints info ---------- " << std::endl;

    for (int i = 0; i < msg->data.size(); i++) {
        const encoder_msgs::EncoderData &data = msg->data[i];
        ss << "Joint " << i << std::endl;
        ss << "[" << data.x << " " << data.y << " " << data.z << "]" << std::endl << std::endl;
    }

    ROS_INFO_STREAM(ss.str());
}
