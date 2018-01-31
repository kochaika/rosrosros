#include "ros/ros.h"
#include "diagnostic_msgs/KeyValue.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "reader");

  ros::NodeHandle n;


  ros::Publisher chatter_pub = n.advertise<diagnostic_msgs::KeyValue>("chatter", 100);

  while (ros::ok())
  {
    diagnostic_msgs::KeyValue msg;
    msg.key = "0";
    std::cout<<">: ";
    std::cin>>msg.value;


    ROS_INFO("Sending: [%s]: %s", msg.key.c_str(), msg.value.c_str());


    chatter_pub.publish(msg);

    ros::spinOnce();

  }


  return 0;
}
