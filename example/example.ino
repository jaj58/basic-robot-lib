#include <basic-robot-lib.hpp>

c_robot robot(13,11,12,3,1200);
void setup() {
  // put your setup code here, to run once:
  robot.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
    robot.forwards(); //simple code which will make the robot go forwards forever in this loop...
}
