#include "basic-robot-lib.hpp"

 /*
	robot-lib.cpp - a simple library for usage with robot's using a arduino....
	created by jac jones (github.com/jaj58)
	free to edit and modify as you see fit but give credit where credit is due /s
*/

c_robot::c_robot(const byte left_direction_pin, const byte left_speed_pin, const byte right_direction_pin,
	const byte right_speed_pin, const float time_taken_one_rotation = 1200):
left_dir_pin(left_direction_pin), right_dir_pin(right_direction_pin), left_speed_pin(left_speed_pin),
right_speed_pin(right_speed_pin), time_taken_one_rotation_ms(time_taken_one_rotation){
	sonar_trigger_pin = -1;
	sonar_echo_pin = -1;
}

c_robot::c_robot(const byte left_direction_pin, const byte left_speed_pin, const byte right_direction_pin,
	const byte right_speed_pin, const byte sonar_trigger_pin,
	const byte sonar_echo_pin, const float time_taken_one_rotation):
left_dir_pin(left_direction_pin), right_dir_pin(right_direction_pin), left_speed_pin(left_speed_pin),
right_speed_pin(right_speed_pin),sonar_trigger_pin(sonar_trigger_pin),
sonar_echo_pin(sonar_echo_pin), time_taken_one_rotation_ms(time_taken_one_rotation){
}

void c_robot::setup(){
	pinMode(left_dir_pin, OUTPUT);
	pinMode(right_dir_pin, OUTPUT);

	if (sonar_trigger_pin != -1 && sonar_echo_pin != -1) {
		Serial.begin(9600);
		pinMode(sonar_trigger_pin, OUTPUT);
		pinMode(sonar_echo_pin, INPUT);
	}

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

byte c_robot::get_left_dir_pin() const {
	return left_dir_pin;
}
byte c_robot::get_right_dir_pin() const {
	return right_dir_pin;
}
byte c_robot::get_left_speed_pin() const {
	return left_speed_pin;
}
byte c_robot::get_right_speed_pin() const {
	return right_speed_pin;
}
float c_robot::get_time_taken_per_rot_ms() const {
	return time_taken_one_rotation_ms;
}
byte c_robot::get_sonar_trigger_pin() const{
	return sonar_trigger_pin;
}
byte c_robot::get_sonar_echo_pin() const{
	return sonar_echo_pin;
}

void c_robot::set_left_dir_pin(const byte input) {
	left_dir_pin = input;
}
void c_robot::set_right_dir_pin(const byte input) {
	right_dir_pin = input;
}
void c_robot::set_left_speed_pin(const byte input) {
	left_speed_pin = input;
}
void c_robot::set_right_speed_pin(const byte input) {
	right_speed_pin = input;
}
void c_robot::set_time_taken_per_rot_ms(const float input) {
	time_taken_one_rotation_ms = input;
}
void c_robot::set_sonar_trigger_pin(const byte input){
	sonar_trigger_pin = input;
}
void c_robot::set_sonar_echo_pin(const byte input){
	sonar_echo_pin = input;
}

float c_robot::sonar_to_distance(const float t){
	static float speed_of_sound = 343;
	return (((t / 2) * speed_of_sound) / 1000);
}

void c_robot::print_sonar_debug(float duration){
	Serial.print("duration : ");
	Serial.println(duration);
	Serial.print("distance : ");
	Serial.println(sonar_to_distance(duration));
}

float c_robot::sonar_duration(const bool print_debug){
	digitalWrite(sonar_trigger_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(sonar_trigger_pin, LOW);
	auto duration = pulseIn(sonar_echo_pin, HIGH);
	if (print_debug){
		print_sonar_debug(duration);
	}
	return duration;
}

float c_robot::sonar_distance(const bool print_debug){
	return sonar_to_distance(sonar_duration(print_debug));
}
