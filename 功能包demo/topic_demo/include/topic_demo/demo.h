#include "ros/ros.h"
#include "std_msgs/String.h"

class Demo
{
public:
    void print_msgs(const std_msgs::String::ConstPtr& msg);

};
  