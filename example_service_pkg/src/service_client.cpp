#include "ros/ros.h"
#include "example_service_pkg/examplesrv.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "service_client_node");

    if (argc != 2) {
        ROS_INFO("Usage: service_client_node <input_string>");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<example_service_pkg::examplesrv>("test_service");
    example_service_pkg::examplesrv srv;
    srv.request.in = argv[1];

    if (client.call(srv)) {
        ROS_INFO("Response from server: %s", srv.response.out.c_str());
    } else {
        ROS_ERROR("Failed to call service test_service");
        return 1;
    }

    return 0;
}
