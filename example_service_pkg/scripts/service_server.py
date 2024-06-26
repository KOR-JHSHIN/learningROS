#!/usr/bin/env python3

import rospy
from example_service_pkg.srv import examplesrv, examplesrvResponse

def service_request_callback(req):
    rospy.loginfo("Request from client: [%s]", req.in_)
    response = "Service request received"
    rospy.loginfo("Response to client: [%s]", response)
    return examplesrvResponse(response)

def service_server():
    rospy.init_node('service_server_node')
    s = rospy.Service('test_service', examplesrv, service_request_callback)
    rospy.loginfo("Service server is ready to receive requests from clients.")
    rospy.spin()

if __name__ == "__main__":
    service_server()
