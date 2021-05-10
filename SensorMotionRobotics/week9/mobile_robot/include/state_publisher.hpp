#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>


namespace state_publisher{
    class StatePublisher{
        public:
            StatePublisher();
            ~StatePublisher();

            void run();

        private:
            ros::NodeHandle nh;

            //int argc_;
            //char** argv_;

            ros::Publisher joint_pub_;
            sensor_msgs::JointState joint_state_;

            float temp1, temp2, temp3, temp4;

    };
}