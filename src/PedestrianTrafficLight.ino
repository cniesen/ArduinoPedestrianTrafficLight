/*
    Arduino Pedestrian Traffic Light v1.0
    
    This version of the pedestrian traffic light loops through the traffic
    light pattern continuously.
    
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
TrafficLight* pedestrianTrafficLight;

// Germany uses a red-yellow pattern before turning green. To disable this use
// the TrafficLight::USA pattern
TrafficLight::SignalStandard TrafficLight::signalStandard = TrafficLight::GERMANY;

void setup() {                
autoTrafficLight = new TrafficLight(autoRed, autoYellow, autoGreen, TrafficLight::GREEN);
    pedestrianTrafficLight = new TrafficLight(pedestrianRed, pedestrianGreen, TrafficLight::RED);
}

void loop() {
    autoTrafficLight->switchSignal();
    pedestrianTrafficLight->switchSignal();
    delay(1000);           
    autoTrafficLight->switchSignal();
    pedestrianTrafficLight->switchSignal();
    delay(5000);           
}

