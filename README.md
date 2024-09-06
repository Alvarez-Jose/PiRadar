#PiRadar

This is a guide and instructions on building a Mini Radar using Raspberry PI 4.
Below are all the hardware used and also a set-guide for using CLion and using Remote Toolchain to connect to your PI device.

##Hardware

Radar Sensor: HC-SR04 Ultrasonic Module Distance Sensor

Microcontroller: Raspberry PI 4 + 64GB SSD

Power supply: 5V USB Power Supply (2.5A or more)

Display: Hosyond 0.96 inch OLED l2C ll Display Module

Cables: Solderless Flexible Breadboard Jumper wires Male to Male & Male to Female

Connectors: Breadboard, GIPO kit, Resistor kit

Mirco Servo motor: This was added to make simulate a Marine Radar Scanner which rotates 360 degrees.

Tools: Precision Screwdriver Set, Digital Multimeter, Wire Cutter/Stripper, Soldering Kit (Optional), Hot Glue Gun (Optional)

##Remote setup from PC to Raspberry Pi using Clion
1. Run sudo raspi-config to Enable SSH for remote connections
2. Navigate to interfacing Options
3. Select SSH and enable it

##Setting up Remote Development in CLion
1. Go to File > Settings > Build, Excution, Deployment > Toolchains.
2. Click the + button to add a new toolchain
3. Choose Remote Host as the toolchain type

##Configing SSH settings. 
1. To obtain your host id use hostname -I

   Example: 192.168.1.101 2001:db8:abcd:0012:3456:789a:bcde:f012

2. credentials username@192.168.1.101 port 22

3. Specify CMake, C Compiler, and C++ Compiler Paths

   Set the CMake and compiler paths to those on your Raspberry Pi.

   CMake path: /usr/bin/cmake

   C Compiler path: /usr/bin/gcc

   C++ Compiler path: /usr/bin/g++

4. Test the Connection once toolchain is configured.