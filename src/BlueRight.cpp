#include "vex.h"
#include "robot-config.h"

void BlueRight(){
RightMotor1.spinFor(forward, 34.697, degrees, 275, rpm, false); 
RightMotor2.spinFor(forward, 34.697, degrees, 275, rpm, false); 
LeftMotor1.spinFor(forward, 34.697, degrees, 275, rpm, false); 
LeftMotor2.spinFor(forward, 34.697, degrees, 275, rpm, false); 

//conveyor.spinFor(forward, 2000, degrees, 100, rpm, true);

RightMotor1.spinFor(forward, 534.697, degrees, 275, rpm, false); 
RightMotor2.spinFor(forward, 534.697, degrees, 275, rpm, false); 
LeftMotor1.spinFor(forward, 534.697, degrees, 275, rpm, false); 
LeftMotor2.spinFor(forward, 534.697, degrees, 275, rpm, false); 

//conveyor.spinFor(forward, 2000, degrees, 100, rpm, true);

//RightMotor1.spinFor(forward, 334.697, degrees, 275, rpm, false); 
//RightMotor2.spinFor(forward, 334.697, degrees, 275, rpm, false); 
//RightMotor3.spinFor(reverse, 334.697, degrees, 275, rpm, false); 
//LeftMotor1.spinFor(reverse, 334.697, degrees, 275, rpm, false); 
//LeftMotor2.spinFor(reverse, 334.697, degrees, 275, rpm, false); 
//LeftMotor3.spinFor(forward, 334.697, degrees, 275, rpm, true); 

//Rightmotorgroup.spinToPosition(180, degrees, 275, rpm, false);
//Leftmotorgroup.spinToPosition(90, degrees, 275, rpm, false);

//conveyor.spinFor(forward, 400, degrees, 360, rpm, true);

//wait(25, msec);

}

