#ifndef ROBOT_LIB_HPP
#define ROBOT_LIB_HPP

#include "Arduino.h"

/*
	robot-lib.hpp - a simple library for usage with robot's using a arduino....
	created by jac jones (github.com/jaj58)
	free to edit and modify as you see fit but give credit where credit is due /s
*/
class c_robot{
	byte left_dir_pin, right_dir_pin, left_speed_pin, right_speed_pin, sonar_trigger_pin, sonar_echo_pin;
  float time_taken_one_rotation_ms;

public:
	c_robot(const byte left_direction_pin, const byte left_speed_pin, const byte right_direction_pin,
		const byte right_speed_pin, const float time_taken_one_rotation);

	c_robot(const byte left_direction_pin, const byte left_speed_pin, const byte right_direction_pin,
		const byte right_speed_pin, const byte sonar_trigger_pin,
		const byte sonar_echo_pin, const float time_taken_one_rotation);

	//main setup function
	void setup();

	//robot controls
	void forwards();
	void reverse();
	void left();
	void right();
	void right(float deg);
	void left(float deg);
	void stop();

	//getters
	byte get_left_dir_pin() const;
	byte get_right_dir_pin() const;
	byte get_left_speed_pin() const;
	byte get_right_speed_pin() const;
	float get_time_taken_per_rot_ms() const;
	byte get_sonar_trigger_pin() const;
	byte get_sonar_echo_pin() const;

	//setters
	void set_left_dir_pin(const byte input);
	void set_right_dir_pin(const byte input);
	void set_left_speed_pin(const byte input);
	void set_right_speed_pin(const byte input);
	void set_time_taken_per_rot_ms(const float input);
	void set_sonar_trigger_pin(const byte input);
	void set_sonar_echo_pin(const byte input);

	//sonar funcs
private:
	static float sonar_to_distance(const float t);
	void print_sonar_debug(float duration);
public:
	float sonar_duration(const bool print_debug);
	float sonar_distance(const bool print_debug);
};
#endif // ROBOT_LIB_HPP
