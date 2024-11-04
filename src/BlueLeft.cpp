#include "vex.h"
#include "robot-config.h"

void BlueLeft()
{

while(1){
wait(25, msec);
}

conveyor.spinFor(forward, 400, degrees, 360, rpm, false);

RightMotor1.spinFor(fwd, 634.697, degrees, 360, rpm, false); 
RightMotor2.spinFor(fwd, 634.697, degrees, 360, rpm, false); 
RightMotor3.spinFor(fwd, 634.697, degrees, 360, rpm, false); 
LeftMotor1.spinFor(reverse, 634.697, degrees, 360, rpm, false); 
LeftMotor2.spinFor(reverse, 634.697, degrees, 360, rpm, false); 
LeftMotor3.spinFor(reverse, 634.697, degrees, 360, rpm, true); 

conveyor.spinFor(forward, 400, degrees, 360, rpm, false);

RightMotor1.spinFor(fwd, 634.697, degrees, 360, rpm, false); 
RightMotor2.spinFor(fwd, 634.697, degrees, 360, rpm, false); 
RightMotor3.spinFor(fwd, 634.697, degrees, 360, rpm, false); 
LeftMotor1.spinFor(reverse, 634.697, degrees, 360, rpm, false); 
LeftMotor2.spinFor(reverse, 634.697, degrees, 360, rpm, false); 
LeftMotor3.spinFor(reverse, 634.697, degrees, 360, rpm, true); 

Rightmotorgroup.spinToPosition(180, degrees, 360, rpm, false);
Leftmotorgroup.spinToPosition(90, degrees, 360, rpm, false);

conveyor.spinFor(forward, 400, degrees, 360, rpm, false);

wait(25, msec);

}