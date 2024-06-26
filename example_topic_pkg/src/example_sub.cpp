#include <ros/ros.h>
#include <std_msgs/Int32.h>

void callback(const std_msgs::Int32::ConstPtr& msg)
{
    ROS_INFO("%d", msg->data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cpp_sub_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("cpp_counter", 10, callback);

    ros::spin();

    return 0;
}
