#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include <Servo.h>

RH_ASK driver;
Servo servo;

void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init()){
      Serial.println("init failed");
    }
    pinMode(8, OUTPUT);
    servo.attach(7);
      
}

int recData(){
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
//      Serial.print("Message: ");
//      Serial.println(atoi((char *)buf));  
//      servo.write(atoi((char *)buf));
//      digitalWrite(8, 1); 
      delay(500);
      digitalWrite(8, 0);
      return atoi((char *)buf);
    }
    
}

void loop()
{
    servo.write(recData());
    delay(100);
}
