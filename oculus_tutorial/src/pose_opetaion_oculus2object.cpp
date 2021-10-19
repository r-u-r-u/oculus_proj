#include<ros/ros.h>
#include<oculus_msgs/OculusHmdPoseMsg.h>
#include<geometry_msgs/Pose.h>

class Operator
{
    private:
    ros::NodeHandle _nh;
    ros::Publisher _pub;
    ros::Subscriber _sub;

    public:
    void callback(const oculus_msgs::OculusHmdPoseMsg::ConstPtr& msg_sub);
    Operator()
    {
        _sub = _nh.subscribe("/oculus/pose",1000,&Operator::callback,this);
        _pub = _nh.advertise<geometry_msgs::Pose>("/unity/cube/pose",1000);
    }

    ~Operator()
    {

    }

};

void Operator::callback(const oculus_msgs::OculusHmdPoseMsg::ConstPtr& msg_sub){
    geometry_msgs::Pose msg_pub;
    msg_pub.position = msg_sub->position;
    msg_pub.orientation = msg_sub->orientation;

    _pub.publish(msg_pub);
}

int main(int argc,char *argv[])
{
    ros::init(argc,argv,"pose_operator");
    Operator op;

    ros::spin();
}