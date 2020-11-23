/* 
 * -------------------------------------------------------------------
 * This module has been developed as an exercise for Robotics course
 * @ UniSa.
 *
 * Title:   main.cpp
 * Author:  Vittorio Fina
 * Date:    Nov 23, 2020
 *
 * This module implements a chatter (publisher) that publishes messages
 * to the topic "encoder_read" in order to simulate a set of sensors for 
 * encoder readings, that is position of 6 joints.
 *
 * -------------------------------------------------------------------
 */

#include "ros/ros.h"
#include "encoder_msgs/EncoderDataArray.h"
#include "encoder_msgs/EncoderData.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {

    /*
     * The ros::init() function need to see argc and argv in order 
     * to take eventually argoments from command line.
     * The third argument of the init() is the name of the node.
     * 
     * NodeHandle is the main access point to communication with ROS system.
     */
    ROS_INFO("Intializing node /encoder_writer as a publisher");
    ros::init(argc, argv, "encoder_writer");
    ros::NodeHandle n;

    /*
     * The advertise() function is how you tell ROS that you want to publish on a given
     * topic name. It returns a publisher object which allows you to publish on that topic
     * through the publish() call
     */
    ros::Publisher encoder_pub = n.advertise<encoder_msgs::EncoderDataArray>("encoder_read", 1);

    ros::Rate loop_rate(10);

    float x, y, z;

    int i = 0, joint_num = 6;

    while(ros::ok()) {
        /*
         * Declare the message to be published and its data type.
         */
        encoder_msgs::EncoderData data;
        encoder_msgs::EncoderDataArray msg;

        for(i = 0; i < joint_num; i++) {
            /*
             * Taking from stdin the values.
             */ 
            printf("Insert x - y - z for joint %d -> ", i);
            cin >> x >> y >> z;
            data.x = x;
            data.y = y;
            data.z = z;
            msg.data.push_back(data);
        }

        ROS_INFO("Publishing encoder info on topic /encoder_read ...");
        encoder_pub.publish(msg);

        ros::spinOnce();
    }
    return 0;
}
