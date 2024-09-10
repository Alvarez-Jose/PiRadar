//
// Created by Antonio Alvarez on 9/9/2024.
//

#include "Sensor.h"
#include <wiringPi.h>
#include <chrono>
#include <thread>

void Sensor::initialize() {
    wiringPiSetupGpio();
    //setting up GPIO pins for TRIG and ECHO
}

double Sensor::getDistance() {
    //Implement ultrasonic sensor reading logic
    return 0.0; // placeholder
}

