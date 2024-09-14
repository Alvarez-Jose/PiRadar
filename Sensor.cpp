#include "Sensor.h"
#include <pigpio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include "Pins.h" // Assuming this contains TRIG_PIN and ECHO_PIN

#define TRIG_PIN 23 // You can define the pins used for the sensor here
#define ECHO_PIN 24

void Sensor::initialize() {
    if (gpioInitialise() < 0) {
        std::cerr << "Pigpio initialization failed!" << std::endl;
    } else {
        std::cout << "Pigpio initialized successfully." << std::endl;
        gpioSetMode(TRIG_PIN, PI_OUTPUT);
        gpioSetMode(ECHO_PIN, PI_INPUT);
    }
}

double Sensor::getDistance() {
    // Send a 10us pulse to trigger the ultrasonic sensor
    gpioWrite(TRIG_PIN, PI_OFF);
    gpioDelay(2); // Ensure a clean low pulse
    gpioWrite(TRIG_PIN, PI_ON);
    gpioDelay(10); // 10us pulse to TRIG_PIN
    gpioWrite(TRIG_PIN, PI_OFF);

    // Wait for ECHO_PIN to go high
    while (gpioRead(ECHO_PIN) == PI_OFF);

    // Record the start time
    uint32_t startTime = gpioTick();

    // Wait for ECHO_PIN to go low
    while (gpioRead(ECHO_PIN) == PI_ON);

    // Record the end time
    uint32_t endTime = gpioTick();

    // Calculate the duration in microseconds
    uint32_t duration = endTime - startTime;

    // Calculate the distance in cm (speed of sound = 34300 cm/s)
    double distance = (duration / 2.0) * 0.0343;

    return distance;
}
