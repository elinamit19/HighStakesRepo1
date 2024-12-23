#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotor1 = motor(PORT1, ratio18_1, true);
motor LeftMotor2 = motor(PORT10, ratio18_1, true);
motor RightMotor1 = motor(PORT9, ratio18_1, false);
motor RightMotor2 = motor(PORT12, ratio18_1, false);
motor conveyor = motor(PORT6, ratio18_1, false);
motor intake = motor(PORT3, ratio18_1, false);
inertial interialSensor = inertial(PORT8);
motor_group Rightmotorgroup = motor_group(RightMotor1, RightMotor2);
motor_group Leftmotorgroup = motor_group(LeftMotor1, LeftMotor2);
digital_out hook = digital_out(Brain.ThreeWirePort.A);
digital_out hook2 = digital_out(Brain.ThreeWirePort.B);
// VEXcode generated functions 

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // nothing to initialize)
}