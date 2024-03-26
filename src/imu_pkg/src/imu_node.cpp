#include<ros/ros.h>
#include "sensor_msgs/Imu.h"
#include"tf/tf.h"
#include<geometry_msgs/Twist.h>

ros::Publisher vel_pub;

// sensor_msgs::Imu中的四元数主要用于消息传递，比如从传感器节点发布到处理节点，
// 而不提供tf::Quaternion那样丰富的数学运算方法。   
// 两边分量分别对应
void imucbk(const sensor_msgs::Imu msg)
{
    if (msg.orientation_covariance[0] < 0)
    {
        return;
    }

    // tf（transformation）库
    // 一个tf::Quaternion对象被创建并初始化
    tf::Quaternion quaternion(
        msg.orientation.x,
        msg.orientation.y,
        msg.orientation.z,
        msg.orientation.w
    );
    // tf::Matrix3x3(quaternion) 四元数直接表示旋转，而欧拉角是旋转另一种表示方式，两者需要通过旋转矩阵作为中介来转换
    // getRPY（） 用于从旋转矩阵中提取出欧拉角
    double roll,pitch,yaw;
    tf::Matrix3x3(quaternion).getRPY(roll,pitch,yaw);
    roll = roll*180/M_PI;
    pitch = pitch*180/M_PI;
    yaw = yaw*180/M_PI;
    ROS_INFO("横滚角： %f , 俯仰角： %f , 航向角： %f ",roll,pitch,yaw);

    geometry_msgs::Twist mgs;
    double target_yaw = 90;
    double differ_angle = target_yaw - yaw;
    mgs.angular.z = differ_angle * 0.01;
    mgs.linear.x = 0.01;
    vel_pub.publish(mgs);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"imu_node");
    ros::NodeHandle n;
    ros::Subscriber imu_sub = n.subscribe("/imu/data",10,imucbk);
    vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    ros::spin();
    return 0;
}