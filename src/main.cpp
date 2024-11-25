/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       inbox                                                     */
/*    Created:      10/22/2024, 7:07:11 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robot-config.h"

using namespace vex;

// A global instance of competition
competition Competition;



// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

}

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
extern void RedLeft(void);
void autonomous(void) {
 RedLeft();
 


 

}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
int deadband = 5;
  while (1) {
     // Deadband stops the motors when Axis values are close to zero.
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position()*100.0;
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position()*100.0;
   
    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      LeftMotor1.setVelocity(0, percent);
      LeftMotor2.setVelocity(0, percent);
      LeftMotor3.setVelocity(0, percent);
      
    } else {
      // Set the speed to leftMotorSpeed
      LeftMotor1.setVelocity(leftMotorSpeed, percent);
      LeftMotor2.setVelocity(leftMotorSpeed, percent);
    LeftMotor3.setVelocity(leftMotorSpeed, percent);
    }
     if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero.
      RightMotor1.setVelocity(0, percent);
      RightMotor2.setVelocity(0, percent);
      RightMotor3.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      RightMotor1.setVelocity(rightMotorSpeed, percent);
      RightMotor2.setVelocity(rightMotorSpeed, percent);
    RightMotor3.setVelocity(rightMotorSpeed, percent);
    }
    if (Controller1.ButtonR2.pressing()) {
      conveyor.setVelocity(-100, percent); 
    } else if(Controller1.ButtonR1.pressing()) {
      conveyor.setVelocity(100, percent);
    }
    else{
      conveyor.setVelocity(0, percent);
    }
    if(Controller1.ButtonL1.pressing()) {
      intake.setVelocity(60, percent);
    } else if(Controller1.ButtonL2.pressing()){
      intake.setVelocity(-60, percent);
    } else{
      intake.setVelocity(0, percent);
    }
    

  
    //Initalizes the button for pnuematics
    if(Controller1.ButtonY.pressing()){
      hook.set(false);
      hook2.set(true);
    }
    else if(Controller1.ButtonX.pressing()){
      hook.set(true);
      hook2.set(false);     
    }
    this_thread::sleep_for(10);

    LeftMotor1.spin(reverse);
    LeftMotor2.spin(reverse);
    LeftMotor3.spin(forward);
    RightMotor1.spin(forward);
    RightMotor2.spin(forward);
    RightMotor3.spin(reverse);
    conveyor.spin(forward);
    intake.spin(forward);
   wait(25, msec);

 }
  
   
}


 
  




//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();;

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
