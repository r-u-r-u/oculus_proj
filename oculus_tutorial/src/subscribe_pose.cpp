#include<ros/ros.h>
#include<oculus_msgs/OculusHmdPoseMsg.h>

void poseCallback(const oculus_msgs::OculusHmdPoseMsg::ConstPtr& msg){
    ROS_INFO("position x:[%f]",msg->position.x);
}

int main(int argc,char *argv[]){
    ros::init(argc,argv,"subscribe_oculus_pose");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/oculus/pose",1000,poseCallback);

    ros::Rate loop_rate(10);
    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}