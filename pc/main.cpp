#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

//#define SERIAL_PORT "/dev/cu.esp-ESP32SPP"
#define SERIAL_PORT "/dev/rfcomm0"

auto main() -> int {
    boost::asio::io_service io;

    // ポートは /dev/ttyACM0
    boost::asio::serial_port serial(io, SERIAL_PORT);

      // 速度は 9600bps
    serial.set_option(boost::asio::serial_port_base::baud_rate(115200));

    // テキトウに1秒待つ
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // "ping" を送信
    // boost::asio::write(serial, boost::asio::buffer("11"));

    for (int i = 0; i < 2;i++){
        // serial から response_buf に '\n' まで読み込む

        boost::asio::write(serial, boost::asio::buffer("a"));



        boost::asio::streambuf response_buf;
        boost::asio::read_until(serial, response_buf, '0');

        // boost::asio::write(serial, response_buf);


        //**************************************************//

        // boost::asio::SyncReadStream *s;


        // 表示して終わり
        const std::string result = boost::asio::buffer_cast<const char*>(response_buf.data());
        std::cout << result;
    }
}
