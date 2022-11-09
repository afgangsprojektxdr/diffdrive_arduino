#ifndef DIFFDRIVE_ARDUINO_ARDUINO_COMMS_H
#define DIFFDRIVE_ARDUINO_ARDUINO_COMMS_H
#include <atomic>
#include <cstring>
#include <string>
#include <chrono>
#include "mqtt/async_client.h"
class ArduinoComms
{


public:

  ArduinoComms()
  {  }

  ArduinoComms(const std::string &serial_device, int32_t baud_rate, int32_t timeout_ms)
  {  
    std::string test = serial_device;
    int test2 = baud_rate;
    int test3 = timeout_ms;
    std::cout<< test << test2 <<test3<<std::endl;
    setup(serial_device, baud_rate, timeout_ms);}

  void setup(const std::string &serial_device, int32_t baud_rate, int32_t timeout_ms);
  void sendEmptyMsg();
  void readEncoderValues(int &val_1, int &val_2);
  void setMotorValues(int val_1, int val_2);
  void setPidValues(float k_p, float k_d, float k_i, float k_o);

  bool connected() const { return true; }

  std::string sendMsg(const std::string &msg_to_send, bool print_output = false);


private:
  const std::string DFLT_SERVER_ADDRESS	{ "tcp://localhost:1883" };
  const std::string CLIENT_ID				{ "paho_cpp_async_publish" };
  const std::string PERSIST_DIR			{ "./persist" };

  const std::string TOPIC { "hello" };
  const char* LWT_PAYLOAD = "Last will and testament.";
  const char* PAYLOAD1 = "Hello World!";
  const char* PAYLOAD2 = "Hi there!";
  const char* PAYLOAD3 = "Is anyone listening?";
  const char* PAYLOAD4 = "Someone is always listening.";
  const int  QOS = 1;

  const double TIMEOUT = 10.0;
};



#endif // DIFFDRIVE_ARDUINO_ARDUINO_COMMS_H