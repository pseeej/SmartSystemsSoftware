#include "state_publisher.hpp"

namespace state_publisher{
    StatePublisher::StatePublisher(){
        joint_pub_ = nh.advertise<sensor_msgs::JointState>("joint_states_", 1);

        nh.setParam("joint1", -1);
        nh.setParam("joint2", -1);
        nh.setParam("joint3", -1);
        nh.setParam("joint4", -1);
    }

    StatePublisher::~StatePublisher(){

    }

    void StatePublisher::run(){

            //update joint_state
        joint_state_.header.stamp = ros::Time::now();

        nh.getParam("joint1", temp1);
        nh.getParam("joint2", temp2);
        nh.getParam("joint2", temp3);
        nh.getParam("joint2", temp4);

        joint_state.name.push_back("joint1");
        joint_state.position.push_back(temp1);
        joint_state.name.push_back("joint2");
        joint_state.position.push_back(temp2);
        joint_state.name.push_back("joint3");
        joint_state.position.push_back(temp3);
        joint_state.name.push_back("joint4");
        joint_state.position.push_back(temp4);


        joint_pub_.publish(joint_state_);

    }
}

int main(int argc, char** argv){
    ros::init(argc, argv, "custom_joint_state_publisher");

    state_publisher::StatePublisher SP;

    ros::Rate loop_rate(10);

    while(ros::ok()){
        SP.run();
        loop_rate.sleep();
    }

    return 1;
}