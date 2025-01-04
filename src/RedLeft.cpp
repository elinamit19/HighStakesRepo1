#include "vex.h"
#include "robot-config.h"
void RedLeft(){
    hook.set(false);
    hook2.set(true);
RightMotor1.spinFor(reverse, 569.394, degrees, 100, rpm, false); 
RightMotor2.spinFor(reverse, 569.394, degrees, 100, rpm, false); 
LeftMotor1.spinFor(reverse, 569.394, degrees, 100, rpm, false); 
LeftMotor2.spinFor(reverse, 569.394, degrees, 100, rpm, false); 

wait(2000,msec);

hook.set(true);
hook2.set(false);

wait(1000,msec);

conveyor.spinFor(reverse, 2000, degrees, 150, rpm, true);






}