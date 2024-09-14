cmake_minimum_required(VERSION 3.28)
project(PiRadar)

set(CMAKE_CXX_STANDARD 17)

# Include pigpio
find_package(PkgConfig REQUIRED)
pkg_check_modules(PIGPIO REQUIRED libpigpio)

include_directories(${PIGPIO_INCLUDE_DIRS})
link_directories(${PIGPIO_LIBRARY_DIRS})

# Add your executable and include all source files
add_executable(PiRadar main.cpp Radar.cpp Sensor.cpp Servo.cpp)

# Link pigpio
target_link_libraries(PiRadar ${PIGPIO_LIBRARIES})
