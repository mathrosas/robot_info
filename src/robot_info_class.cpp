#include "robot_info/robot_info_class.h"
#include "robot_info/CustomRobotInfo.h"

RobotInfo::RobotInfo() {
  robot_description = "Mi100";
  serial_number = "567A359";
  ip_address = "169.254.5.180";
  firmware_version = "3.5.8";

  info_pub = nh.advertise<robot_info::CustomRobotInfo>("robot_info", 10);
}

RobotInfo::~RobotInfo() {
  // No special cleanup needed
}

void RobotInfo::publish_data() {
  robot_info::CustomRobotInfo msg;
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  // Fields data_field_05 to data_field_10 are left empty
  info_pub.publish(msg);
  ROS_INFO("RobotInfo: Data published.");
}