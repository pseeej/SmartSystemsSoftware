#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

namespace my_tf_practice{
    class MyTfPractice{
        public:
            MyTfPractice();
            ~MyTfPractice();

            void pubTF();

        private:
            ros::NodeHandle nh;
            
            ros::Time last;

            tf::TransformBroadcaster br;

            double pi_;
            double angular_velocity_;
            double current_theta_;
            double yaw_;
    };
}