#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

int val = 0;
int send_val = 0;

void setup(){
  Serial.begin(9600);
  if (!driver.init()){
    Serial.println("Initialization failed");
  }
  pinMode(8, OUTPUT);
}

void sendData(const char data[sizeof(int)]){
  driver.send((uint8_t *)data, strlen(data));
  driver.waitPacketSent();
  digitalWrite(8, 1);
  delay(100);
  digitalWrite(8, 0);
}

void loop(){
  val = analogRead(A0);
  send_val = map(val, 0, 1023, 0, 180);
  const char data[sizeof(int)];
  itoa(send_val, data, 10);
  Serial.println(data);
  sendData(data);
  delay(100);
    
}
