#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Float64.h>
#include <cstdlib>
#include <ctime>
#include <random_gen_x/control_msg.h>

namespace random_generator_x{
    class RandomGeneratorX{
        public :
            RandomGeneratorX();
            ~RandomGeneratorX();

            void run();
            float genX();

        private :
            ros::NodeHandle nh;

            ros::Publisher pub_random_x_;
    };
}