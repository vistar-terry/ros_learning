/**
 * 该例程将发布chatter话题，消息类型String
 */
 
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  // ROS节点初始化
  ros::init(argc, argv, "talker");
  
  // 创建节点句柄
  ros::NodeHandle n;
  
  // 创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
  // 1000为消息队列的大小，当发布的消息实际速度较慢时，Publisher会将消息存储在一个固定大小的消息队列中，
  // 如果消息队列大小超过所设置的值时，ROS会自动删除队列中最早入队的消息
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  // 设置循环的频率，单位是Hz
  ros::Rate loop_rate(10);

  // 循环部分
  int count = 0;

  // node的主循环
  // 在node未发生异常时，将一直在循环中运行，否则ros::ok()会返回false，跳出循环
  // 异常包括：
  //    1. 收到SIGINT信号（Ctrl+C）
  //    2. 被另外一个相同名称的node踢掉线
  //    3. 节点调用了关闭函数ros::shutdown()
  //    4. 所有ros::NodeHandles句柄被销毁
  while (ros::ok())
  {
	  // 初始化std_msgs::String类型的消息
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

	  // 发布消息
    chatter_pub.publish(msg);

    // 打印日志信息
    ROS_INFO("%s", msg.data.c_str());

	  // 消息回调处理函数
    // node在后台订阅的消息到这里才被执行
    // 虽然此node没有订阅消息，建议所有node加入该函数
    ros::spinOnce();
	
	  // 按照ros::Rate loop_rate(10)设置的循环频率休眠
    // 10Hz，1s执行10次，1次就是100ms
    // 在这里休眠100ms后，进入下一个循环的工作
    loop_rate.sleep();
    ++count;
  }

  return 0;
}