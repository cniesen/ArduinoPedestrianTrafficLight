/*
    Arduino Pedestrian Traffic Light v2.0
    
    This version of the pedestrian traffic light is triggered by
    a push button and sounds a continuous beep for blind pedestrians.
    
    Author: Claus Niesen
    https://github.com/cniesen/ArduinoPedestrianTrafficLight
*/

#include "TrafficLight.h"
#include "Arduino.h"

TrafficLight::TrafficLight(int redLightPin, int yellowLightPin, int greenLightPin, Signal signalState) {
    this->redLightPin = redLightPin;
    this->yellowLightPin = yellowLightPin;
    this->greenLightPin = greenLightPin;
    if (yellowLightPin == NULL
        && ((signalState == YELLOW) || (signalState == RED_YELLOW))) {
        this->signalState = RED;
    } else {
        this->signalState = signalState;
    }
    this->buzzerPin = NULL;

    pinMode(redLightPin, OUTPUT); 
    if (yellowLightPin != NULL) {
        pinMode(yellowLightPin, OUTPUT);     
    }
    pinMode(greenLightPin, OUTPUT);    


    switch(signalState) {
        case RED :
            switchSignalToRed();
            break;
        case RED_YELLOW :
            switchSignalToRedYellow();
            break;
        case GREEN :
            switchSignalToGreen();
            break;
        case YELLOW :
            switchSignalToYellow();
            break;
    }
}

void TrafficLight::enableAlert(int buzzerPin) {
    this->buzzerPin = buzzerPin;
    pinMode(buzzerPin, OUTPUT);
}

void TrafficLight::switchSignalToRedYellow() {
    if ((yellowLightPin == NULL) || (signalStandard == USA)) {
        switchSignalToRed();
        return;
    }

    digitalWrite(redLightPin, HIGH);
    digitalWrite(yellowLightPin, HIGH);
    digitalWrite(greenLightPin, LOW);
    if (buzzerPin != NULL) {
        digitalWrite(buzzerPin, LOW);
    }
}

void TrafficLight::switchSignalToGreen() {
    digitalWrite(redLightPin, LOW);
    if (yellowLightPin != NULL) {
        digitalWrite(yellowLightPin, LOW);
    }
    digitalWrite(greenLightPin, HIGH);
    if (buzzerPin != NULL) {
        digitalWrite(buzzerPin, HIGH);
    }
}

void TrafficLight::switchSignalToYellow() {
    if (yellowLightPin == NULL) {
        switchSignalToRed();
        return;
    }

    digitalWrite(redLightPin, LOW);
    digitalWrite(yellowLightPin, HIGH);
    digitalWrite(greenLightPin, LOW);
    if (buzzerPin != NULL) {
        digitalWrite(buzzerPin, LOW);
    }
}

void TrafficLight::switchSignalToRed() {
    digitalWrite(redLightPin, HIGH);
    if (yellowLightPin != NULL) {
        digitalWrite(yellowLightPin, LOW);
    }
    digitalWrite(greenLightPin, LOW);
    if (buzzerPin != NULL) {
        digitalWrite(buzzerPin, LOW);
    }
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


