 #include <IRremote.h>
 #include "BluetoothSerial.h"
 
int RECV_PIN = 15;

 BluetoothSerial ESP_BT;
IRrecv irrecv(RECV_PIN);
decode_results results;
int trigger = 0;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const long interval = 400;  
 
void setup()
{
  ESP_BT.begin("Lap_Timer_ESP32");
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
}
 
void loop()
{
  currentMillis = millis();
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    if (results.value == 632192736){
          //sendTrigger();
          ESP_BT.println(1);
          //delay (interval);
    }

    irrecv.resume();
  }
}

void sendTrigger()
{
  /**
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
            previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:**/
          if (trigger == 0) {
                 trigger = 1;
          } else {
                 trigger = 0;
          }

  ESP_BT.println(trigger);
   Serial.println(trigger);

}
