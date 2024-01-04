#include "HomeSpan.h" 
#include "LED.h"
#include "DEV_RELAY.h"

//Remember to pair your esp32 board with your wifi before adding the device into the Apple Home app

void setup() {
  Serial.begin(115200);

  homeSpan.setPairingCode("11122333"); //Default
  homeSpan.setQRID("111-22-333");
  homeSpan.begin(Category::Bridges, "HomeSpan Bridge");
  
  //Accessory 2: LED Switch
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new LED(15); 
   
  //Accessory 2: Relay Switch
  new SpanAccessory();
  new Service::AccessoryInformation();    
  new Characteristic::Identify();                       
  new DEV_RELAY(17);
}

void loop() {
  homeSpan.poll();
}