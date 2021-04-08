#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <my_publisher_class/class_msg.h>

namespace my_subscriber_class{
    class MySubscriberClass{
        public : 
            MySubscriberClass();
            ~MySubscriberClass();

            void callbackRandInt(const std_msgs::Int32::ConstPtr &msg);
            void callbackClassMsg(const my_publisher_class::class_msg::ConstPtr &msg);

            void run();
            
        private:
            ros::NodeHandle nh;

            ros::Subscriber sub_rand_int_;
            ros::Subscriber sub_class_msg_;

            int value_int_;
            float value_float_;
            std::string str_;
    };
}