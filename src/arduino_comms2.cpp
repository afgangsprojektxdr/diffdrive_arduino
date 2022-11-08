#include "diffdrive_arduino/arduino_comms.h"
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

namespace std

void ArduinoComms::setup()
{  
    sendMsg("hello",0);
}


void ArduinoComms::sendEmptyMsg()
{
    std::string response = sendMsg("\r");
}

void ArduinoComms::readEncoderValues(int &val_1, int &val_2)
{
    
}

void ArduinoComms::setMotorValues(int val_1, int val_2)
{
    
}

void ArduinoComms::setPidValues(float k_p, float k_d, float k_i, float k_o)
{

}

std::string ArduinoComms::sendMsg(const std::string &msg_to_send, bool print_output)
{


	string address = (argc > 1) ? string(argv[1]) : DFLT_SERVER_ADDRESS;

	cout << "Initializing for server '" << address << "'..." << endl;
	mqtt::async_client cli(address, "");

	cout << "  ...OK" << endl;

	try {
		cout << "\nConnecting..." << endl;
		cli.connect()->wait();
		cout << "  ...OK" << endl;

		cout << "\nPublishing messages..." << endl;

		mqtt::topic top(cli, TOPIC, QOS);
		mqtt::token_ptr tok;

		size_t i = 0;
		
		tok = top.publish(PAYLOAD1);
		
		tok->wait();	// Just wait for the last one to complete.
		cout << "OK" << endl;

		// Disconnect
		cout << "\nDisconnecting..." << endl;
		cli.disconnect()->wait();
		cout << "  ...OK" << endl;
	}
	catch (const mqtt::exception& exc) {
		cerr << exc << endl;
		return "nope";
	}

 	return "all good";

}