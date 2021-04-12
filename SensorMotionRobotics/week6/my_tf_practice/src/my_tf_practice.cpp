#include <my_tf_practice.hpp>

namespace my_tf_practice{
    MyTfPractice::MyTfPractice(){
        angular_velocity_ = 2.0;
        current_theta_ = 0.0;
        yaw_ = 0.0;
    }

    MyTfPractice::~MyTfPractice(){

    }

    void MyTfPractice::pubTF(){
        ros::Time now = ros::Time::now();
        double dt = (now-last).toSec();

        current_theta_ += angular_velocity_ * dt;
        last = now;

        // calculate child frame - translation
        double x = cos(current_theta_);
        double y = sin(current_theta_);

        // calculate child frame - rotation
        yaw_ += 2.0 * dt;

        // generate tf msg
        tf::Transform transform;
        transform.setOrigin(tf::Vector3(x, y, 0.0));
        tf::Quaternion q;
        q.setRPY(0, 0, yaw_);
        transform.setRotation(q);

        // publish tf
        br.sendTransform(tf::StampedTransform(transform, now, "parent_link", "child_link"));
    }
}

int main(int argc, char** argv){
    ros::init(argc, argv, "my_tf_practice");

    my_tf_practice::MyTfPractice MTP;

    ros::Rate loop_rate(100);

    while(ros::ok()){
        MTP.pubTF();
        loop_rate.sleep();
    }

    return 0;
}