#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>
#include <vector>
/* #include <comms.h> */
/* #include <BLDCControllerClient.cpp> */
#include <koko_hardware_drivers/BLDCControllerClient.h>
//#include <unistd.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const unsigned int ENCODER_ANGLE_PERIOD = 1 << 14;
int main(int argc, char** argv) {
  if (argc < 2) {
    return 0;
  }

  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  BLDCControllerClient client(argv[1], 1000000, serial::Timeout::simpleTimeout(20));

  // client.setDuty(3, 6.0);
  // uint8_t r1 = 0;
  // uint8_t r2 = 1;
  // client.writeRegisters(3, 0x102, 1, &r1, 1);
  // client.writeRegisters(3, 0x109, 1, &r2, 1);

  int id = 3;
  // client.leaveBootloader(3, 0);

  for(int i = 0; i < 10; i++) {
    float angle = client.getEncoderRadians(3);
    std::cout << angle << "\n";
    ros::Duration(0.1).sleep();
  }

  return 0;
}
