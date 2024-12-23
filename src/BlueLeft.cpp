#include "vex.h"
#include "robot-config.h"
//PD control variables
double kP = 0.5;
double kD = 0.05;
//PD control variables 
double preverror = 0;
double setPoint = 0; //Target Position 
double currentposition = 0; //Current motor position 

double pdControl(double currentposition){
    //Calculate error 
    double error = setPoint - currentposition;
    //Calculate the derivative 
    double derivative = error - preverror;
    //PD output 
    double output = kP * error + kD * derivative;
    //Update previous error for next loop 
    preverror = error;

    return output;
}
void moveWithPD(double targetPosition, int rpm) {
    setPoint = targetPosition; //set Target Position 

    //clear previous errors 
    preverror = 0;

    while (fabs(setPoint - currentposition) > 1 ) {
        //Get the current position of all 6 motors 
        double rigthtPosition = (RightMotor1.position(degrees) + RightMotor2.position(degrees)) / 3.0;
        double leftPosition = (LeftMotor1.position(degrees) + LeftMotor2.position(degrees)) / 3.0;
        //get the average of both sides 
        currentposition = (rigthtPosition + leftPosition) / 2.0;

        //compute PD output 
        double speedAdjustment = pdControl(currentposition);

        //adjust motor speeds 
        RightMotor1.spin(forward, 100 + speedAdjustment, voltageUnits::volt);
        RightMotor2.spin(forward, 100 + speedAdjustment, voltageUnits::volt);
        LeftMotor1.spin(reverse, 100 - speedAdjustment, voltageUnits::volt);
        LeftMotor2.spin(reverse, 100 - speedAdjustment, voltageUnits::volt);
         
        wait(20, msec); // Allow time for the motors to adjust and the PD loop to run
    }

    // Stop motors once target position is reached
    RightMotor1.stop();
    RightMotor2.stop();
    LeftMotor1.stop();
    LeftMotor2.stop();
}

// Autonomous routine for Blue Left
void BlueLeft() {
    // Move forward (34.697 degrees) using PD control
    moveWithPD(34.697, 275);  // Adjust target distance and speed (RPM) as needed
    hook.set(true);
    hook2.set(true);

    // Move backward (534.697 degrees) using PD control
    moveWithPD(534.697, 275);  // Adjust target and speed for accurate movement
    conveyor.spinFor(forward, 2000, degrees, 100, rpm, true);

    // Move forward again (334.697 degrees) using PD control
    moveWithPD(334.697, 275);

    // Turn motors to specific positions (for turning or adjusting orientation)
    Rightmotorgroup.spinToPosition(180, degrees, 275, rpm, false);
    Leftmotorgroup.spinToPosition(90, degrees, 275, rpm, false);

    hook.set(true);
    hook2.set(true);


}

















