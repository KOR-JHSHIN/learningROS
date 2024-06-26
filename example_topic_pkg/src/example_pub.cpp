#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cpp_pub_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("cpp_counter", 10);
    ros::Rate rate(2); // 2 Hz

    int count = 0;

    while (ros::ok())
    {
        std_msgs::Int32 msg;
        msg.data = count;
        pub.publish(msg);
        count++;
        rate.sleep();
    }

    return 0;
}
