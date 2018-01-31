#include "ros/ros.h"
#include "diagnostic_msgs/KeyValue.h"

ros::Publisher chatter_pub;

void callback(const diagnostic_msgs::KeyValue& msg)
{
  if(msg.key!="0"){
      return;
  }
  ROS_INFO("got msg: [%s]: %s", msg.key.c_str(), msg.value.c_str());
  diagnostic_msgs::KeyValue msg1;
  msg1.key = "1";
  msg1.value = msg.value + " <-- WHAT?!";

  ROS_INFO("Sending: [%s]: %s", msg1.key.c_str(), msg1.value.c_str());

  chatter_pub.publish(msg1);

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "adder");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 100, callback);
  chatter_pub = n.advertise<diagnostic_msgs::KeyValue>("chatter", 100);

  ros::spin();

  return 0;
}
