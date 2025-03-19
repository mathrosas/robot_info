#pragma once
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/ros.h"

class RobotInfo {
protected:
  ros::NodeHandle nh;
  ros::Publisher info_pub;
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

public:
  RobotInfo();
  virtual ~RobotInfo();
  virtual void publish_data();
};