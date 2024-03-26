#include<ros/ros.h>
#include<std_msgs/String.h>
#include<qq_msgs/Carry.h>

void macbk(const qq_msgs::Carry msg)
{
    ROS_INFO("星星： %ld",msg.star);
    ROS_INFO("等级： %s", msg.grade.c_str());
    ROS_INFO("消息： %s", msg.data.c_str());
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"ma_node");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("xiaoheizi",10,macbk);
    ros::spin();
    return 0;
}