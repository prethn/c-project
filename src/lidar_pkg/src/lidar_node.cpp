#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>

ros::Publisher vel_pub;
int count = 0;

void lidar_cbk(const sensor_msgs::LaserScan msg)
{
    float mid = msg.ranges[180];
    ROS_INFO("前方距离 ranges[180] =  %f 米",mid);
    if (count > 0)
    {
        count--;
    }
    
    geometry_msgs::Twist vel;
    if (mid < 1)
    {
        vel.angular.z = 0.05;
        count = 20;
    }
    else
    {
        vel.linear.x = 0.5;
    }
        vel_pub.publish(vel);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"lidar_node");

    ros::NodeHandle n;
    ros::Subscriber  lidar_sub = n.subscribe("/scan",10,&lidar_cbk);
    vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel",10);
    ros::spin();
    return 0;
}
