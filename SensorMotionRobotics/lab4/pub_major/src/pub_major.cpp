#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv){

    ros::init(argc, argv, "my_major");

    ros::NodeHandle nh;

    ros::Publisher pub_my_msg = nh.advertise<std_msgs::String>("/my_major", 100);

    ros::Rate loop_rate(10);

    while(ros::ok()){

        std_msgs::String my_major;
        my_major.data = "AI Convergence";

        pub_my_msg.publish(my_major);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}