#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("esp"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

int cnt = 0;

void loop() {

//  SerialBT.write(cnt);
  SerialBT.println(cnt);       //bluetoothを通じてMacのプログラムに送られる
  
  //  Serial.write(cnt);
//    Serial.println("Serial");  //ArduinoIDEのシリアルポートに出力

  cnt++;
  if (SerialBT.available()) {
        char buf = SerialBT.read();
        Serial.println({buf});
//      SerialBT.println("Hello");
  }
  if (SerialBT.available()) {
//    Serial.write(SerialBT.read());
//    Serial.print(SerialBT.read());
  }
  delay(1000);
}
