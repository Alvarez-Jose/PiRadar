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

##Trouble shooting

Since WiringPi is not supported anymore, the other alternative was using PigPio. Which should be installed using this Link: https://github.com/joan2937/pigpio.git

For me, Clion is unable to run this directly due to an Admin issue of not having permission to use pigpio, from what I have gather this has to do with how fundamentally you can only run pigpio with root access, because some of the processor registers accessed by pigpio require it.

##Below I will add the steps I took to get to this run. 

1. update your package list
   sudo apt update

2. Install necessary build tools
   sudo apt install git build-essential cmake

3. close the pigpio repository
   git clone https://github.com/joan2937/pigpio.git

4. Build and install pigpio
   cd pigpio
   make
   sudo make install

5. Verify the installation
   pkg-config --libs --cflags libpigpio

6. Start the pigpio daemon
   sudo systemctl start pigpiod

7. Now make sure to run this on powershell but remote connect to your raspberry pi and run this command.
   /usr/local/bin/cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -G "CodeBlocks - Unix Makefiles" -S /tmp/tmp.KZun9wkH1P -B /tmp/tmp.KZun9wkH1P/cmake-build-release-raspberrypi

8. Then try running your program
   sudo /tmp/tmp.KZun9wkH1P/cmake-build-release-raspberrypi/PiRadar
