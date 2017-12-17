# robot-lib (sonar untested but should work fine)
https://github.com/jaj58/robot-lib
 a simple library for usage with robot's using a arduino....
 free to edit and modify as you see fit but give credit where credit is due /s
  
# summary

simple constructor which takes in the pins you have your motor's connected to and if wanted possibility to define the time one rotation takes in ms

example usage:

easiest constructor this means you have to use the set functions provided to set pins and everything else needed to actually use
our functions
c_robot robot();

c_robot robot(13,11,12,3);

or if you want to define the rotation time in ms:
c_robot robot(13,11,12,3,1500);

c_robot::c_robot(byte left_direction_pin, byte left_speed_pin, byte right_direction_pin,
  byte right_speed_pin, const float time_taken_one_rotation = 1200);
   
more advanced constructor which allows the setup of sonar functions if wanted + set roation time if wanted.
c_robot(const byte left_direction_pin, const byte left_speed_pin, const byte right_direction_pin,
		const byte right_speed_pin, const byte sonar_trigger_pin,
		const byte sonar_echo_pin, const float time_taken_one_rotation);

setup function to be used in the arduino setup function robot.setup();

void setup();

self explanitory functions to make the robot forward easy usage : robot.forwards();

void forwards();

void reverse();

void left();

void right();

right and left turning with a more precise accuracy using degrees and a formula to convert from deg to time to turn for..

deg * (time_taken_for_one_rotation_in_ms / 360)

void right(float deg);

void left(float deg);

just stops the robot completely.

void stop();

getters and setters -> these functions let you set or check what our class variables are set to, not really needed but just in case.

outputs the duration till sonar hits an object and gets back.
float sonar_duration(const bool print_debug);

outputs the distance to the object that the sonar is detecting in milimetres  
float sonar_distance(const bool print_debug); 

