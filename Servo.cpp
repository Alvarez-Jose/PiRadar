#include "Servo.h"
#include <pigpio.h>
#include <iostream>
#include "Pins.h"
void Servo::initialize() {
    if (gpioInitialise() < 0) {
        std::cerr << "Pigpio initialization failed!" << std::endl;
        exit(1);
    }
    // Initialize PWM for servo control
    gpioSetMode(SERVO_PIN, PI_OUTPUT);
    gpioSetPWMrange(SERVO_PIN, 1000); // Adjust according to servo specs
    gpioSetPWMfrequency(SERVO_PIN, 50); // 50 Hz for servo
}

double Servo::getAngle() {
    // Implement the logic to return the current angle of the servo
    // Assuming you have feedback or know how to calculate it
    return 0.0; // Placeholder
}
