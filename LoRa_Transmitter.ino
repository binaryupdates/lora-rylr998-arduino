#include <SoftwareSerial.h>

#define button 5

SoftwareSerial lora(2, 3);

String lora_RX_address = "1";   //enter Lora RX address

void setup()
{
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  lora.begin(9600);
}

void loop()
{
  if (digitalRead(button) == LOW) {
    lora.println("AT+SEND=" + lora_RX_address + ",2,LO"); // AT+SEND=1,2,LO
    delay(1000);
  } 
  else {
    lora.println("AT+SEND=" + lora_RX_address + ",2,HI"); // AT+SEND=1,2,HI
    delay(1000);
  }
}
