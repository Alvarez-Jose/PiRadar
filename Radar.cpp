#include "Radar.h"
#include "Sensor.h"
#include "Servo.h"
#include <iostream>
#include <chrono>
#include <thread>
void Radar::initialize() {
    Sensor::initialize();
    Servo::initialize();
    std::cout << "Radar System initialized." << std::endl;
}

void Radar::run() {
    while (true) {
        double distance = Sensor::getDistance();
        double angle = Servo::getAngle();
        std::cout << "Distance: " << distance << "Cm At Angle: " << angle << " Degrees" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Adjust delay as needed
    }
}
