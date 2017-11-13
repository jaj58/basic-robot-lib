#include "robot-lib.hpp"

 /*
	robot-lib.cpp - a simple library for usage with robot's using a arduino....
	created by jac jones (github.com/jaj58)
	free to edit and modify as you see fit but give credit where credit is due /s
*/

c_robot::c_robot(byte left_direction_pin, byte left_speed_pin, byte right_direction_pin, byte right_speed_pin, const float time_taken_one_rotation):
left_dir_pin(left_direction_pin), right_dir_pin(right_direction_pin), left_speed_pin(left_speed_pin), right_speed_pin(right_speed_pin),
time_taken_one_rotation_ms(time_taken_one_rotation)
{
}

void c_robot::setup(){
	pinMode(left_dir_pin, OUTPUT);
	pinMode(right_dir_pin, OUTPUT);
	Serial.println("setup pins...");
}

void c_robot::forwards(){
	digitalWrite(left_dir_pin, LOW);
	analogWrite(left_speed_pin, 255);
	digitalWrite(right_dir_pin, LOW);
	analogWrite(right_speed_pin, 255);
}

void c_robot::reverse(){
	digitalWrite(left_dir_pin, HIGH);
	analogWrite(left_speed_pin, 255);
	digitalWrite(right_dir_pin, HIGH);
	analogWrite(right_speed_pin, 255);
}

void c_robot::left(){
	digitalWrite(left_dir_pin, LOW);
	analogWrite(left_speed_pin, 255);
	digitalWrite(right_dir_pin, HIGH);
	analogWrite(right_speed_pin, 255);
}

void c_robot::right(){
	digitalWrite(left_dir_pin, HIGH);
	analogWrite(left_speed_pin, 255);
	digitalWrite(right_dir_pin, LOW);
	analogWrite(right_speed_pin, 255);
}

void c_robot::right(const float deg){
	right();
	/*
	simple way to convert the degrees we want to turn
	into a time to actually turn for, this uses the defined
	variable of the time it takes to complete one whole rotation.
	*/
	auto time_to_delay = deg * (time_taken_one_rotation_ms / 360);
	delay(time_to_delay);
	stop();
}

void c_robot::left(const float deg){
	left();
	/*
	simple way to convert the degrees we want to turn
	into a time to actually turn for, this uses the defined
	variable of the time it takes to complete one whole rotation.
	*/
	auto time_to_delay = deg * (time_taken_one_rotation_ms / 360);
	delay(time_to_delay);
	stop();
}

void c_robot::stop(){
	digitalWrite(left_dir_pin, LOW);
	analogWrite(left_speed_pin, 0);
	digitalWrite(right_dir_pin, LOW);
	analogWrite(right_speed_pin, 0);
}
