#!/usr/bin/env python
import rosbag

bag = rosbag.Bag('infrared.bag')
for topic, msg, t in bag.read_messages(topics=['/hikrobot_camera/camera_info']):
    print(msg)
bag.close()