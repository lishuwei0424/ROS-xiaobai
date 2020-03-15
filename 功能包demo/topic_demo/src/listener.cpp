#include "ros/ros.h"
#include "std_msgs/String.h"
#include <topic_demo/demo.h>

// 接收到订阅的消息后，会进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  //将接收到的消息打印出来
  Demo *demo;
  demo->print_msgs(msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");//初始化ROS节点

  ros::NodeHandle n;//创建节点句柄

  // 创建一个Subscriber，订阅名为chatter的topic，注册回调函数chatterCallback
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  //循环等待回调函数
  ros::spin();

  return 0;
}