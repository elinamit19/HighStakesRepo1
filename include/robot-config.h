using namespace vex;
extern brain Brain;
// VEXcode devices

extern controller Controller1;
extern motor LeftMotor1;
extern motor LeftMotor2;
extern motor LeftMotor3;
extern motor RightMotor1;
extern motor RightMotor2;
extern motor RightMotor3; 
extern motor conveyor; 
extern motor_group Rightmotorgroup;
extern motor_group Leftmotorgroup;
extern digital_out hook;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);