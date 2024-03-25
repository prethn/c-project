# -*- coding: utf-8 -*-
from __future__ import print_function

import os
import stat
import sys

# find the import for catkin's python package - either from source space or from an installed underlay
if os.path.exists(os.path.join('/opt/ros/noetic/share/catkin/cmake', 'catkinConfig.cmake.in')):
    sys.path.insert(0, os.path.join('/opt/ros/noetic/share/catkin/cmake', '..', 'python'))
try:
    from catkin.environment_cache import generate_environment_script
except ImportError:
    # search for catkin package in all workspaces and prepend to path
    for workspace in '/home/szu/User/Project_A/Test_F/ROS_IN/devel;/home/szu/User/Other_F/mvs_ros_pkg/build/devel;/home/szu/User/Project_A/Mix/R3live_ws/devel;/home/szu/User/Package_installOfROS/devel;/home/szu/User/Project_A/Lidar/srlivo_ws/devel;/home/szu/User/Project_A/Test_F/rosdemo1/devel;/home/szu/User/Project_A/Lidar/FastliVo_wp/devel;/home/szu/User/Project_A/Lidar/Sfastlio_wp/devel;/opt/ros/noetic'.split(';'):
        python_path = os.path.join(workspace, 'lib/python3/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/szu/User/Project_A/Test_F/ROS_IN/devel/env.sh')

output_filename = '/home/szu/User/Project_A/Test_F/ROS_IN/build/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    # print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)
