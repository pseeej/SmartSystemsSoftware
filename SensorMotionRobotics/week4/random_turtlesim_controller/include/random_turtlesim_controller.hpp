#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Float64.h>
#include <cstdlib>
#include <ctime>
#include <random_gen_x/control_msg.h>
#include <geometry_msgs/Twist.h>

namespace random_turtlesim_controller{
    class RandomTurtlesimController{
        public :
            RandomTurtlesimController();
            ~RandomTurtlesimController();

            void callbackPrevMsg(const random_gen_x::control_msg::ConstPtr &ptr);

        private :
            ros::NodeHandle nh;

            ros::Publisher pub_cmd_vel_;
            ros::Subscriber sub_prev_msg_;

    };
}