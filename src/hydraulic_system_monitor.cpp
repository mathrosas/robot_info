#include <string>

class HydraulicSystemMonitor {
public:
  HydraulicSystemMonitor();
  virtual ~HydraulicSystemMonitor();

  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;

  std::string getHydraulicOilTemperature();
  std::string getHydraulicOilTankFillLevel();
  std::string getHydraulicOilPressure();
};

HydraulicSystemMonitor::HydraulicSystemMonitor() {
  hydraulic_oil_temperature = "45C";
  hydraulic_oil_tank_fill_level = "100%";
  hydraulic_oil_pressure = "250 bar";
}

HydraulicSystemMonitor::~HydraulicSystemMonitor() {
  // No special cleanup needed
}

std::string HydraulicSystemMonitor::getHydraulicOilTemperature() {
  return hydraulic_oil_temperature;
}

std::string HydraulicSystemMonitor::getHydraulicOilTankFillLevel() {
  return hydraulic_oil_tank_fill_level;
}

std::string HydraulicSystemMonitor::getHydraulicOilPressure() {
  return hydraulic_oil_pressure;
}