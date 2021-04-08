#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Float64.h>
#include <cstdlib>
#include <ctime>
#include <random_gen_x/control_msg.h>

namespace random_generator_y{
    class RandomGeneratorY{
        public :
            RandomGeneratorY();
            ~RandomGeneratorY();

            void callbackPrevMsg(const random_gen_x::control_msg::ConstPtr &ptr);
            float genY();

        private :
            ros::NodeHandle nh;

            ros::Publisher pub_random_y_;
            ros::Subscriber sub_prev_msg_;

            random_gen_x::control_msg prev_cm_;
    };
}