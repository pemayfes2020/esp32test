#include "BluetoothSerial.h"
#include <Servo.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

Servo myservo; //Servoオブジェクトを作成
BluetoothSerial SerialBT;

int servoPin = 13;

void setup() {
		  Serial.begin(115200);
		    SerialBT.begin("esp"); //Bluetooth device name
			  Serial.println("The device started, now you can pair it with bluetooth!");
			  //
			  //  pinMode(4, OUTPUT);
			  //  pinMode(5, OUTPUT);

			    myservo.attach(13); //13番ピンにサーボ制御線（オレンジ）を接続
				  
				  //  digitalWrite(4, HIGH);
}

void loop() {
		  
		    //  Serial.write(cnt);
			  //  Serial.println("Serial");  //ArduinoIDEのシリアルポートに出力

			    if (SerialBT.available()) {
						        char buf = SerialBT.read();
								        if(buf > '0' && buf <= '9'){
												          Serial.write(buf);
														    
															          int deg = (buf - '0') * 20;
																	    
																		          myservo.write(deg);

																				            delay(1000);
																							          
																									            myservo.write(0);
																												          
																														    
																															          delay(1000);

																																	          }
																																			    }

																																				        
																																						//        if(buf == 'l') {
																																								//            deg += 2;
																																								////          digitalWrite(4, LOW);
																																								//        }else if(buf == 'h'){
																																										//            deg -= 2;
																																										////          myservo.write(180); //180度へ回転 
																																										////          delay(1000);
																																										////          myservo.write(0); //元に戻る
																																										////          delay(1000);
																																										////          digitalWrite(4, HIGH);
																																										//        

																																										  
																																								}
																																								}
