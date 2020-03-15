#include <cstdlib>
#include "ros/ros.h"
#include "service_demo/AddTwoInts.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client"); // ROS节点初始化
  
  //从终端命令行获取两个加数
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;   // 创建节点句柄

  //创建一个client，请求add_two_int service，service消息类型是learning_communication::AddTwoInts
  ros::ServiceClient client = n.serviceClient<service_demo::AddTwoInts>("add_two_ints");
  
  service_demo::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  
  //发布service请求，等待加法运算的应答结果

  if (client.call(srv))
  {
    long int count=(long int)srv.response.sum;
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
