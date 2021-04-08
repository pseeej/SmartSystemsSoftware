#include "ros/ros.h"
#include "my_server_class/add_two_ints.h"

namespace my_server_class{
    class MyServerClass{
        public:
            MyServerClass();
            ~MyServerClass();

            bool callbackAdd(my_server_class::add_two_ints::Request &req, my_server_class::add_two_ints::Response &res);

        private:
            ros::NodeHandle nh;

            ros::ServiceServer service_; 
    };
}