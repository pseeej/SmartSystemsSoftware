#include <random_gen_x.hpp>

namespace random_generator_x{
    RandomGeneratorX::RandomGeneratorX(){
        pub_random_x_ = nh.advertise<random_gen_x::control_msg>("/first", 100);

        srand((unsigned int)time(NULL));
    }

    RandomGeneratorX::~RandomGeneratorX(){

    }

    void RandomGeneratorX::run(){
        random_gen_x::control_msg cm;
        cm.rand_x.data = genX();

        pub_random_x_.publish(cm);
    }

    float RandomGeneratorX::genX(){
        float result;

        result = (rand()%300) / 100.0;  // 0 < result < 3

        return result;
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "random_gen_x");

    random_generator_x::RandomGeneratorX RGX;

    ros::Rate loop_rate(10);

    while(ros::ok()){
        RGX.run();

        ros::spinOnce();
        loop_rate.sleep();
        
    }
}