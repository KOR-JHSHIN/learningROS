#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32

def callback(msg):
    print(msg.data)

rospy.init_node('py_sub_node')
sub = rospy.Subscriber('py_counter', Int32, callback)

rospy.spin()
