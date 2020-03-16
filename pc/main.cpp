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

auto main() -> int
{
    boost::asio::io_service io;

    // ポートは /dev/ttyACM0
    boost::asio::serial_port serial(io, SERIAL_PORT);

      // 速度は 9600bps
    serial.set_option(boost::asio::serial_port_base::baud_rate(115200));

    // テキトウに1秒待つ
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // "ping" を送信
    // boost::asio::write(serial, boost::asio::buffer("11"));

    char buf[32];

	std::cout << "ready" << std::endl;   

	int times = 90;

    while(true) {
        for(int i=0; i< times; ++i){
            boost::asio::write(serial, boost::asio::buffer("l"));
            wait10ms();
        }

        for(int i=0; i < times; ++i) {
            boost::asio::write(serial, boost::asio::buffer("h"));
            wait10ms();
        }
    }


    return 0;
}
