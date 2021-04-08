#include <my_subscriber_class.hpp>

namespace my_subscriber_class{
    MySubscriberClass::MySubscriberClass(){
        sub_rand_int_ = nh.subscribe("/my_first_topic", 100, &MySubscriberClass::callbackRandInt, this);
        sub_class_msg_ = nh.subscribe("/my_first_msg", 100, &MySubscriberClass::callbackClassMsg, this);

        value_int_ = 0;
        value_float_ = 0.0;
        str_ = "";
    }

    MySubscriberClass::~MySubscriberClass(){


    }

    void MySubscriberClass::callbackRandInt(const std_msgs::Int32::ConstPtr &msg){
        //std::cout << "my_subscriber node subscribes [ " << msg->data << " ] "<<std::endl;
        value_int_ = msg->data;
    }

    void MySubscriberClass::callbackClassMsg(const my_publisher_class::class_msg::ConstPtr &msg){
        //std::cout <<"my_subscriber node subscribes [ " << msg->float_data.data <<" , " << msg->string_data.data << " ] "<<std::endl;
        str_ = msg->string_data.data;
        value_float_ = msg->float_data.data;
    }

    void MySubscriberClass::run() {
        std::cout << "int     data : " << value_int_ << std::endl;
        std::cout << "float   data : " << value_float_ << std::endl;
        std::cout << "string  data : " << str_ << std::endl;
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "my_subscriber");

    my_subscriber_class::MySubscriberClass MSC;

    ros::Rate loop_rate(10);

    while(ros::ok()){
        MSC.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}