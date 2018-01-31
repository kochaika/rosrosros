#include "ros/ros.h"
#include "diagnostic_msgs/KeyValue.h"

void callback(const diagnostic_msgs::KeyValue& msg)
{
    if(msg.key!="1"){
        return;
    }
  ROS_INFO("got msg: [%s]: %s", msg.key.c_str(), msg.value.c_str());

  std::cout<<"Printing message: "<< msg.value << std::endl;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "writer");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 100, callback);

  ros::spin();

  return 0;
}
