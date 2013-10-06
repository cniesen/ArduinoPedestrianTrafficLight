/*
    Arduino Pedestrian Traffic Light v2.0
    
    This version of the pedestrian traffic light is triggered by
    a push button and sounds a continuous beep for blind pedestrians.
    
    Author: Claus Niesen
    https://github.com/cniesen/ArduinoPedestrianTrafficLight
*/

#include "TrafficLight.h";

int autoRed = 1;
int autoYellow = 2;
int autoGreen = 3;
TrafficLight* autoTrafficLight;

int pedestrianRed = 4;
int pedestrianGreen = 5; 
int pedestrianAlert = 6;
TrafficLight* pedestrianTrafficLight;

int pedestrianButton = 7;

// Germany uses a red-yellow pattern before turning green. To disable this use
// the TrafficLight::USA pattern
TrafficLight::SignalStandard TrafficLight::signalStandard = TrafficLight::GERMANY;

void setup() {                
    autoTrafficLight = new TrafficLight(autoRed, autoYellow, autoGreen, TrafficLight::GREEN);
    pedestrianTrafficLight = new TrafficLight(pedestrianRed, NULL, pedestrianGreen, TrafficLight::RED);
    pinMode(pedestrianButton, INPUT);
    digitalWrite(pedestrianButton, HIGH);
    pedestrianTrafficLight->enableAlert(pedestrianAlert);
}

void loop() {
    if(digitalRead(pedestrianButton) == LOW) {
        autoTrafficLight->switchSignal();
        pedestrianTrafficLight->switchSignal();
        delay(2000);           
        autoTrafficLight->switchSignal();
        delay(1000);           
        pedestrianTrafficLight->switchSignal();
        delay(10000);           
        pedestrianTrafficLight->switchSignal();
        delay(1000);           
        autoTrafficLight->switchSignal();
        delay(2000);           
        autoTrafficLight->switchSignal();
        pedestrianTrafficLight->switchSignal();
        delay(10000);          
    } 
}

