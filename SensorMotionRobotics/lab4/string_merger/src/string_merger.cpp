#include <string_merger.hpp>

namespace string_merger
{
    StringMerger::StringMerger()
    {
        //todo
        sub_department_number_ = nh.subscribe("/my_department_number", 100, &StringMerger::callbackDepartmentNumber, this);
        sub_subject_ = nh.subscribe("/my_subject", 100, &StringMerger::callbackSubject, this);
        sub_name_ = nh.subscribe("/my_name", 100, &StringMerger::callbackName, this);
        sub_major_ = nh.subscribe("/my_major", 100, &StringMerger::callbackMajor, this);

        pub_my_msg_ = nh.advertise<std_msgs::String>("/my_information", 100);

        value_department_number_ = "";
        value_major_ = "";
        value_name_ = "";
        value_subject_ = "";

        major_ok_ = false;
        subject_ok_ = false;
        department_number_ok_ = false;
        name_ok_ = false;
    }

    StringMerger::~StringMerger()
    {   

    }

    void StringMerger::callbackDepartmentNumber(const std_msgs::String::ConstPtr &ptr)
    {
        //todo

        value_department_number_ = ptr->data;

        department_number_ok_ = true;
    }

    void StringMerger::callbackMajor(const std_msgs::String::ConstPtr &ptr)
    {
        //todo

        value_major_ = ptr->data;

        major_ok_ = true;
    }

    void StringMerger::callbackName(const std_msgs::String::ConstPtr &ptr)
    {
        //todo
        value_name_ = ptr->data;

        name_ok_ = true;
    }

    void StringMerger::callbackSubject(const std_msgs::String::ConstPtr &ptr)
    {
        //todo
        value_subject_ = ptr->data;

        subject_ok_ = true;
    }

    // std::string StringMerger::makeString(){
    //     std::string ss;
    //     ss = value_major_ + " / " + value_subject_ + " / " + value_department_number_ + " / " + value_name_;

    //     return ss;
    // }

    void StringMerger::run()
    {
        if( !(department_number_ok_ && major_ok_ && name_ok_ && subject_ok_) ) return;

        //todo

        std_msgs::String my_information;

        std::string ss;
        ss = value_major_ + " / " + value_subject_ + " / " + value_department_number_ + " / " + value_name_;

        my_information.data = ss;

        pub_my_msg_.publish(my_information);

        std::cout << my_information.data << std::endl;

    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "string_merger");

    string_merger::StringMerger SM;

    ros::Rate loop_rate(10);

    //todo
    while(ros::ok()){
        SM.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}