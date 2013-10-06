/*
    Arduino Pedestrian Traffic Light v1.0
    
    This version of the pedestrian traffic light loops through the traffic
    light pattern continuously.
    
    Author: Claus Niesen
    https://github.com/cniesen/ArduinoPedestrianTrafficLight
*/

#include "TrafficLight.h"
#include "Arduino.h"

TrafficLight::TrafficLight(int redLightInputPin, int greenLightInputPin, Signal signalState) {
    this->redLightInputPin = redLightInputPin;
    this->yellowLightInputPin = NULL;
    this->greenLightInputPin = greenLightInputPin;
    if ((signalState == YELLOW) || (signalState == RED_YELLOW)) {
        this->signalState = RED;
    } 
    else {
        this->signalState = signalState;
    }

    pinMode(redLightInputPin, OUTPUT);     
    pinMode(greenLightInputPin, OUTPUT);    
}

TrafficLight::TrafficLight(int redLightInputPin, int yellowLightInputPin, int greenLightInputPin, Signal signalState) {
    this->redLightInputPin = redLightInputPin;
    this->yellowLightInputPin = yellowLightInputPin;
    this->greenLightInputPin = greenLightInputPin;
    this->signalState = signalState;

    pinMode(redLightInputPin, OUTPUT);     
    pinMode(yellowLightInputPin, OUTPUT);     
    pinMode(greenLightInputPin, OUTPUT);    
}

void TrafficLight::switchSignalToRedYellow() {
    if ((yellowLightInputPin == NULL) || (signalStandard == USA)) {
        switchSignalToRed();
        return;
    }

    digitalWrite(redLightInputPin, HIGH);
    digitalWrite(yellowLightInputPin, HIGH);
    digitalWrite(greenLightInputPin, LOW);
}

void TrafficLight::switchSignalToGreen() {
    digitalWrite(redLightInputPin, LOW);
    digitalWrite(yellowLightInputPin, LOW);
    digitalWrite(greenLightInputPin, HIGH);
}

void TrafficLight::switchSignalToYellow() {
    if (yellowLightInputPin == NULL) {
        switchSignalToRed();
        return;
    }

    digitalWrite(redLightInputPin, LOW);
    digitalWrite(yellowLightInputPin, HIGH);
    digitalWrite(greenLightInputPin, LOW);
}

void TrafficLight::switchSignalToRed() {
    digitalWrite(redLightInputPin, HIGH);
    digitalWrite(yellowLightInputPin, LOW);
    digitalWrite(greenLightInputPin, LOW);
}

void TrafficLight::switchSignal() {
    switch(signalState) {
    case RED :
        switchSignalToRedYellow();
        signalState = RED_YELLOW;
        break;
    case RED_YELLOW :
        switchSignalToGreen();
        signalState = GREEN;
        break;
    case GREEN :
        switchSignalToYellow();
        signalState = YELLOW;
        break;
    case YELLOW :
        switchSignalToRed();
        signalState = RED;
        break;
    }
}


