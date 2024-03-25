#!/usr/bin/env python3
# coding=utf-8

import rospy
from geometry_msgs.msg import Twist

if __name__ == "__main__":
    rospy.init_node("vel_node")
    
    vel_pub = rospy.Publisher("cmd_vel",Twist,queue_size=10)
    vel_msg = Twist();
    vel_msg.linear.x = 0
    vel_msg.linear.y = 0
    vel_msg.linear.z = 0
    vel_msg.angular.x = 0
    vel_msg.angular.y = 0
    vel_msg.angular.z = 0.3
    # 频率30
    r = rospy.Rate(30) 
    rospy.loginfo("开始启动……")
    while not rospy.is_shutdown():
        vel_pub.publish(vel_msg)
        r.sleep()
    