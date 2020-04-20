#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init()){
      Serial.println("init failed");
    }
    pinMode(8, OUTPUT);
      
}

void recData(){
  uint8_t buf[3];
    uint8_t buflen = sizeof(RH_ASK_MAX_MESSAGE_LEN);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);         
    }
    digitalWrite(8, 1);
    delay(1000);
    digitalWrite(8, 0);
}

void loop()
{
    recData();
    delay(1000);
}
