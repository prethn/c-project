#include<ros/ros.h>
#include<std_msgs/String.h>
#include<nav_msgs/OccupancyGrid.h>


int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"map_pub_node");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<nav_msgs::OccupancyGrid>("/map",10);
    nav_msgs::OccupancyGrid msg;
    ros::Rate r(1);
    ROS_INFO("地图数据正在发送……");
    while (ros::ok())
    {
        msg.header.frame_id = "map";
        msg.header.stamp = ros::Time::now();
        msg.info.origin.position.x = 1.0;
        msg.info.origin.position.y = 0;
        msg.info.resolution = 1.0;// 分辨率为 1 米
        msg.info.height = 2; // 高为2个格子
        msg.info.width = 4; // 宽为4个格子
        msg.data.resize(4*2);
        msg.data[0] = 100;
        msg.data[1] = 100;
        msg.data[2] = 0;
        msg.data[3] = -1;
        pub.publish(msg);
        r.sleep();
    }
    return 0;
}
