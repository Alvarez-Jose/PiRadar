//
// Created by Antonio Alvarez on 9/9/2024.
//
#include "Radar.h"
#include "Sensor.h"
#include "Servo.h"
#include <iostream>

void Radar::initialize() {
    // Initialize sensors and servo
    Sensor::initialize();
    Servo::initialize();
    std::cout << "Radar System initalized." << std::endl;
}

void Radar::run() {
    while(true) {
        double distance = Sensor::getDistance();
        double angle = Servo::getAngle();
        std::cout << "Distance: " << distance << "cm at Angle" << angle << "degrees" << std::endl;
        // Add logic to update or display or process data
    }
}

