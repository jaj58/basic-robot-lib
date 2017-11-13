#ifndef ROBOT_LIB_HPP
#define ROBOT_LIB_HPP

#include "Arduino.h"

/*
	robot-lib.hpp - a simple library for usage with robot's using a arduino....
	created by jac jones (github.com/jaj58)
	free to edit and modify as you see fit but give credit where credit is due /s
*/
class c_robot{
  byte left_dir_pin, right_dir_pin, left_speed_pin, right_speed_pin;
  float time_taken_one_rotation_ms;

public:
	c_robot(byte left_direction_pin, byte left_speed_pin, byte right_direction_pin, byte right_speed_pin, const float time_taken_one_rotation);

	void setup();

	void forwards();

	void reverse();

	void left();

	void right();

	void right(float deg);

	void left(float deg);

	void stop();

};
#endif // ROBOT_LIB_HPP
