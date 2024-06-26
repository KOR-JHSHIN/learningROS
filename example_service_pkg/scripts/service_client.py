#!/usr/bin/env python3

import sys
import rospy
from example_service_pkg.srv import examplesrv

def service_client():
    rospy.init_node('service_client_node')
    if len(sys.argv) != 2:
        rospy.loginfo("Usage: service_client_node <input_string>")
        return

    rospy.wait_for_service('test_service')
    try:
        test_service = rospy.ServiceProxy('test_service', examplesrv)
        response = test_service(sys.argv[1])
        rospy.loginfo("Response from server: %s", response.out)
    except rospy.ServiceException as e:
        rospy.logerr("Failed to call service test_service: %s", str(e))

if __name__ == "__main__":
    service_client()
