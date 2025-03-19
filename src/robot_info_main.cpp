#include "robot_info/robot_info_class.h"
#include "ros/init.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  RobotInfo robot;
  ros::Rate loop_rate(1);

  while (ros::ok()) {
    robot.publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}