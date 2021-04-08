#include "ros/ros.h"
#include <cstdlib>
#include <ctime>
#include <my_server_class/add_two_ints.h>

namespace my_client_class{
    class MyClientClass{
        public:
            MyClientClass();
            ~MyClientClass();

            void run();

            void setParam(int argc, char** argv);

        private:
            ros::NodeHandle nh;
            
            ros::ServiceClient client_;

            int argc_;
            char** argv_;
    };
}