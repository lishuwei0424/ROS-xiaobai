#include <topic_demo/demo.h>

void Demo::print_msgs(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
    
}
