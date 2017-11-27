#include "basic-robot-lib.hpp"

const byte left_dir_pin = 13;
const byte left_speed_pin = 11;
const byte right_dir_pin = 12;
const byte right_speed_pin = 3;
const float time_taken_one_rot_ms = 1200;
const byte sonar_trigger_pin = 4;
const byte sonar_echo_pin = 2;
//example without using sonar...
//c_robot robot(left_dir_pin, left_speed_pin, right_dir_pin, right_speed_pin, time_taken_one_rot_ms);

c_robot robot(left_dir_pin, left_speed_pin, right_dir_pin, right_speed_pin, sonar_trigger_pin, sonar_echo_pin, time_taken_one_rot_ms);

void setup() {
  // put your setup code here, to run once:
  robot.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  robot.sonar_distance(true);
  robot.forwards(); //simple code which will make the robot go forwards forever in this loop...
  delay(2000);
}
