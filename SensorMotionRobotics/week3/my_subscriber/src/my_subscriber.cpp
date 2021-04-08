#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <my_publisher/my_msg.h>

void callbackRandInt(const std_msgs::Int32::ConstPtr &msg){
    std::cout << "my_subscriber node subscribes [ " << msg->data << " ] " << std::endl;
}

void callbackMyMsg(const my_publisher::my_msg::ConstPtr &msg){
    std::cout << "my_subscriber node subscribes [ " << msg->float_data.data << " , " << msg->string_data.data <<" ] " << std::endl;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "my_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub_rand_int = nh.subscribe("/my_first_topic", 100, callbackRandInt);
    ros::Subscriber sub_my_msg = nh.subscribe("/my_first_msg", 100, callbackMyMsg);

    ros::spin();

    return 0;
}