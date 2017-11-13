#include <basic-robot-lib.hpp>

byte left_dir_pin = 13;
byte left_speed_pin = 11;
byte right_dir_pin = 12;
byte right_speed_pin = 3;
const float time_taken_one_rot_ms = 1200

c_robot robot(left_dir_pin, left_speed_pin, right_dir_pin, right_speed_pin, time_taken_one_rot_ms);
void setup() {
  // put your setup code here, to run once:
  robot.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
    robot.forwards(); //simple code which will make the robot go forwards forever in this loop...
}
