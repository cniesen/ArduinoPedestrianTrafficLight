/*
    Arduino Pedestrian Traffic Light v1.0
    
    This version of the pedestrian traffic light loops through the traffic
    light pattern continuously.
    
    Author: Claus Niesen
    https://github.com/cniesen/ArduinoPedestrianTrafficLight
*/

class TrafficLight {
    public:
        enum Signal {RED=0, RED_YELLOW, GREEN, YELLOW};
        enum SignalStandard {GERMANY=0, USA};
        static SignalStandard signalStandard;
        TrafficLight(int redLightInputPin, int greenLightinputPin, Signal signalState);
        TrafficLight(int redLightInputPin, int yellowLightInputPin, int greenLightinputPin, Signal signalState);
        void switchSignal();

    private:
        int redLightInputPin;  // make uint8_t
        int yellowLightInputPin;
        int greenLightInputPin;
        Signal signalState;
        void switchSignalToRedYellow();
        void switchSignalToGreen();
        void switchSignalToYellow();
        void switchSignalToRed();
};
