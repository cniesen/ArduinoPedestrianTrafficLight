/*
    Arduino Pedestrian Traffic Light v2.0
    
    This version of the pedestrian traffic light is triggered by
    a push button and sounds a continuous beep for blind pedestrians.
    
    Author: Claus Niesen
    https://github.com/cniesen/ArduinoPedestrianTrafficLight
*/

class TrafficLight {
    public:
        enum Signal {RED=0, RED_YELLOW, GREEN, YELLOW};
        enum SignalStandard {GERMANY=0, USA};
        static SignalStandard signalStandard;
        TrafficLight(int redLightPin, int yellowLightPin, int greenLightPin, Signal signalState);
        void enableAlert(int buzzerPin);
        void switchSignal();
    private:
        int redLightPin;  // make uint8_t
        int yellowLightPin;
        int greenLightPin;
        int buzzerPin;
        Signal signalState;
        void switchSignalToRedYellow();
        void switchSignalToGreen();
        void switchSignalToYellow();
        void switchSignalToRed();
};
