#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>

namespace string_merger
{
    class StringMerger
    {
        public:
            StringMerger();
            ~StringMerger();

            void callbackMajor(const std_msgs::String::ConstPtr &ptr);
            void callbackSubject(const std_msgs::String::ConstPtr &ptr);
            void callbackDepartmentNumber(const std_msgs::String::ConstPtr &ptr);
            void callbackName(const std_msgs::String::ConstPtr &ptr);
            
            void run();

        private:

            //todo

            ros::NodeHandle nh;

            ros::Subscriber sub_department_number_;
            ros::Subscriber sub_major_;
            ros::Subscriber sub_name_;
            ros::Subscriber sub_subject_;

            std::string value_department_number_;
            std::string value_major_;
            std::string value_name_;
            std::string value_subject_;

            ros::Publisher pub_my_msg_;


            bool major_ok_;
            bool subject_ok_;
            bool department_number_ok_;
            bool name_ok_;
    };
}