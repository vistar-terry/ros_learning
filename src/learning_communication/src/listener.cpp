/**
 * 该例程将订阅chatter话题，消息类型String
 */
 
#include "ros/ros.h"
#include "std_msgs/String.h"

// 接收到订阅的消息后，会进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  // 将接收到的消息打印出来
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // 初始化ROS节点
  ros::init(argc, argv, "listener");

  // 创建节点句柄
  ros::NodeHandle n;

  ROS_INFO("hello");

  // 创建一个Subscriber，订阅名为chatter的topic，注册回调函数名称为chatterCallback
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ROS_INFO("spin");

  // 循环等待回调函数
  // 执行到这里不往下执行了，在这里循环
  ros::spin();

  ROS_INFO("end");

  return 0;
}