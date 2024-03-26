#include<ros/ros.h>
#include<std_msgs/String.h>
#include<qq_msgs/Carry.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"chao_node");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<qq_msgs::Carry>("xiaoheizi",10);
    ros::Rate r(10);
    qq_msgs::Carry msg;
    ROS_INFO("启动……");
    while (ros::ok())
    {
        msg.data = "快下班！";
        msg.star = 100;
        msg.grade = "王者";
        pub.publish(msg);
        r.sleep();
    }
    return 0;
}