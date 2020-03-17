#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

#define SERIAL_PORT "/dev/cu.esp-ESP32SPP"
//#define SERIAL_PORT "/dev/rfcomm0"

void wait10ms()
{
    auto start = std::chrono::system_clock::now();
    while((std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start)).count() < 10){
    }
}

boost::asio::io_service io;
// ポートは /dev/ttyACM0
boost::asio::serial_port serial(io, SERIAL_PORT);

int Command;

void setup(){
	Command = 0;   //initialize
	
    // 速度は 9600bps
    serial.set_option(boost::asio::serial_port_base::baud_rate(115200));

    // テキトウに1秒待つ
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

auto main() -> int
{
	setup();	

	std::cout << "ready" << std::endl;   
	
	std::thread esp([&Command](){
	while(true){
		if(Command){
			boost::asio::write(serial, boost::asio::buffer(std::to_string(Command)));
		    wait10ms();

			Command = 0;
		}
	}});

	std::thread sio([&Command]() {
		while(true){
			std::cin >> Command;
			//std::cout << "Command = "  << Command << std::endl; 
		}
	});

	esp.join();
	sio.join();


    return 0;
}
