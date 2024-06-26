#include "ros/ros.h"
#include "example_service_pkg/examplesrv.h"
#include <sstream>

bool service_callback(example_service_pkg::examplesrv::Request &req,
                      example_service_pkg::examplesrv::Response &res) {
    std::stringstream ss;
    ss << "Service request received";
    res.out = ss.str();
    ROS_INFO("Request from client: [%s]", req.in.c_str());
    ROS_INFO("Response to client: [%s]", res.out.c_str());
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "service_server_node");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("test_service", service_callback);
    ROS_INFO("Service server is ready to receive requests from clients.");
    ros::spin();
    return 0;
}

