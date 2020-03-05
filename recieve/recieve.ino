#include <Servo.h>

#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
#include <Servo.h>
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

int servoPin1 = 5;
int servoPin2 = 6;

Servo Servo1;
Servo Servo2;
void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
    Servo1.attach(servoPin1);
    Servo2.attach(servoPin2);
}
 
void loop()
{
    digitalWrite(13,1);
    int x = digitalRead(9);
    // Set buffer to size of expected message
    uint8_t buf[2];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char*)buf); 
        if(buf[0]=='f')
        {
            Servo1.write(-45);
            Servo2.write(-45);
            delay(100);
        }
        else if(buf[0]=='b')
        {
            Servo1.write(45);
            Servo2.write(45);
         delay(100); 
         }
         else if(buf[0]=='r'&&buf[1]=='z')
         {
            Servo1.write(-45);
            Servo2.write(-45);
         delay(2540);
         }
         else  if(buf[0]=='l'&&buf[1]=='z')
         {
         digitalWrite(2,1);
         digitalWrite(3,0);
         digitalWrite(4,0);
         digitalWrite(5,0);
         delay(2540);
         }
         else  if(buf[0]=='r'&&buf[1]=='b')
         {      
         digitalWrite(2,0);
         digitalWrite(3,0);
         digitalWrite(4,1);
         digitalWrite(5,0);
         delay(2540);
         digitalWrite(2,1);
         digitalWrite(3,0);
         digitalWrite(4,1);
         digitalWrite(5,0);      
         delay(100);
         }       
         else  if(buf[0]=='l'&&buf[1]=='f')
         {      
         digitalWrite(2,1);
         digitalWrite(3,0);
         digitalWrite(4,0);
         digitalWrite(5,0);
         delay(2540);
         digitalWrite(2,1);
         digitalWrite(3,0);
         digitalWrite(4,1);
         digitalWrite(5,0);      
         
         delay(100);
         }       
          else  if(buf[0]=='r'&&buf[1]=='f')
         {
         digitalWrite(2,0);
         digitalWrite(3,0);
         digitalWrite(4,1);
         digitalWrite(5,0);
         delay(2540);
         digitalWrite(2,0);
         digitalWrite(3,1);
         digitalWrite(4,0);
         digitalWrite(5,1);
         delay(100);
         }       
          else  if(buf[0]=='l'&&buf[1]=='b')
         {
         digitalWrite(2,1);
         digitalWrite(3,0);
         digitalWrite(4,0);
         digitalWrite(5,0);
         delay(2540);
         digitalWrite(2,0);
         digitalWrite(3,1);
         digitalWrite(4,0);
         digitalWrite(5,1);
         delay(100);
         }       
    }
}
