#include "diffdrive_arduino/arduino_comms2.h"
// #include <ros/console.h>
#include <rclcpp/rclcpp.hpp>
#include <sstream>


#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>	// For sleep
#include <atomic>
#include <chrono>
#include <cstring>
#include "mqtt/async_client.h"


void ArduinoComms::setup(const std::string &serial_device, int32_t baud_rate, int32_t timeout_ms)
{  
    std::cout << baud_rate<<timeout_ms<< std::endl;
	sendMsg(serial_device,40);
}


void ArduinoComms::sendEmptyMsg()
{
    std::string response = sendMsg("nt");
}

void ArduinoComms::readEncoderValues(int &val_1, int &val_2)
{	
	val_1 = 2;
	val_2 = 3;
    std::cout <<val_1<<val_2<<std::endl;
}

void ArduinoComms::setMotorValues(int val_1, int val_2)
{
    std::cout <<val_1<<val_2<<std::endl;
}

void ArduinoComms::setPidValues(float k_p, float k_d, float k_i, float k_o)
{
std::cout <<k_p<<k_d<<k_i<<k_o<<std::endl;
}

std::string ArduinoComms::sendMsg(const std::string &msg_to_send, bool print_output)
{

	std::cout <<msg_to_send<< print_output << std::endl;
	std::string address = DFLT_SERVER_ADDRESS;

	std::cout << "Initializing for server '" << address << "'..." << std::endl;
	mqtt::async_client cli(address, "");

	std::cout << "  ...OK" << std::endl;

	try {
		std::cout << "\nConnecting..." << std::endl;
		cli.connect()->wait();
		std::cout << "  ...OK" << std::endl;

		std::cout << "\nPublishing messages..." << std::endl;

		mqtt::topic top(cli, TOPIC, QOS);
		mqtt::token_ptr tok;

		//size_t i = 0;
		
		tok = top.publish(PAYLOAD1);
		
		tok->wait();	// Just wait for the last one to complete.
		std::cout << "OK" << std::endl;

		// Disconnect
		std::cout << "\nDisconnecting..." << std::endl;
		cli.disconnect()->wait();
		std::cout << "  ...OK" << std::endl;
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc << std::endl;
		return "nope";
	}

 	return "all good";

}