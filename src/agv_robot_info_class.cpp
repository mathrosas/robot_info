#include "hydraulic_system_monitor.cpp"
#include "robot_info/CustomRobotInfo.h"
#include "robot_info/robot_info_class.h"
#include "ros/ros.h"
#include <string>

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo();
  virtual ~AGVRobotInfo();
  std::string maximum_payload;
  HydraulicSystemMonitor hydraulic_monitor;
  void publish_data() override;
};

AGVRobotInfo::AGVRobotInfo() : RobotInfo() { maximum_payload = "100 Kg"; }

AGVRobotInfo::~AGVRobotInfo() {
  // No special cleanup needed
}

void AGVRobotInfo::publish_data() {
  robot_info::CustomRobotInfo msg;
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  msg.data_field_05 = "maximum_payload: " + maximum_payload;
  msg.data_field_06 = "hydraulic_oil_temperature: " +
                      hydraulic_monitor.getHydraulicOilTemperature();
  msg.data_field_07 = "hydraulic_oil_tank_fill_level: " +
                      hydraulic_monitor.getHydraulicOilTankFillLevel();
  msg.data_field_08 =
      "hydraulic_oil_pressure: " + hydraulic_monitor.getHydraulicOilPressure();
  // Fields data_field_06 to data_field_10 remain empty
  info_pub.publish(msg);
  ROS_INFO("AGVRobotInfo: Data published.");
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  AGVRobotInfo agv_robot;
  ros::Rate loop_rate(1); // Publish at 1 Hz

  while (ros::ok()) {
    agv_robot.publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}