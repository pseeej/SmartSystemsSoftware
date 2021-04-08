#include <my_client_class.hpp>

namespace my_client_class{
    MyClientClass::MyClientClass(){
        client_ = nh.serviceClient<my_server_class::add_two_ints>("my_class_service");
        srand((unsigned int)time(NULL));
    }

    MyClientClass::~MyClientClass(){

    }

    void MyClientClass::setParam(int argc, char** argv){
        argc_ = argc;
        argv_ = argv;
    }

    void MyClientClass::run(){
        my_server_class::add_two_ints ati;

        if(argc_ == 3){
            std::cout << "user int version " << std::endl;
            //atoi : ASCII to int
            //atof : ASCII to float
            //atol : ASCII to long
            //atoll : ASCII to long long
            ati.request.a = atoi(argv_[1]);
            ati.request.b = atoi(argv_[2]);


            if(client_.call(ati)){
                std::cout << "request add : " << ati.request.a << " + " << ati.request.b << std::endl;
                std::cout << "receive sum from server : " << ati.response.sum << std::endl;
            }
        }

        else {
            std::cout << "random int version "  << std::endl;

            ati.request.a = rand()%100;
            ati.request.b = rand()%100;

            if(client_.call(ati)){
                std::cout << "request add : " << ati.request.a << " + " << ati.request.b << std::endl;
                std::cout << "receive sum from server : " << ati.response.sum << std::endl;
            }
        }
    }
}

int main(int argc, char** argv){
    ros::init(argc, argv, "my_client_class");

    my_client_class::MyClientClass MCC;

    MCC.setParam(argc, argv);

    MCC.run();
}