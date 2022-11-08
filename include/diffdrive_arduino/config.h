#ifndef DIFFDRIVE_ARDUINO_CONFIG_H
#define DIFFDRIVE_ARDUINO_CONFIG_H

#include <string>


struct Config
{
  //Front wheels
  std::string left_wheel_name = "left_wheel";
  std::string right_wheel_name = "right_wheel";
  //Rear wheels
  std::string rear_left_wheel_name = "rear_left_wheel"; 
  std::string rear_right_wheel_name = "rear_right_wheel"; 
  //Turning joints
  //TODO

  //arduino params for connection
  float loop_rate = 30;
  std::string device = "/dev/ttyUSB0";
  int baud_rate = 57600;
  int timeout = 1000;
  int enc_counts_per_rev = 1920;

  //MQTT Params
  //TODO
};


#endif // DIFFDRIVE_ARDUINO_CONFIG_H