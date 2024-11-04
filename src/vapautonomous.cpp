#include "robot-config.h"
#include "vex.h"
float vap_kP[1], vap_kI[1], vap_kD[1], vap_kL[1];
long vap_tolerance[1];
long vap_ticksPerRotation, vap_ticksPerFoot, vap_waitBetweenPID;

void vap_init() {

    vap_kP[0] = 0.0; // Proportional Constant for Drive
    vap_kI[0] = 0.0; // Integral Constant for Drive
    vap_kD[0] = 0.0; // Derivative Constant for Drive
    vap_kL[0] = 0.0; // Integral Limit for Drive
    vap_tolerance[0] = 0; // Tolerance for Drive

    vap_ticksPerRotation = 0; // Number of ticks per full rotation
    vap_ticksPerFoot = 0; // Number of ticks per foot traveled
    vap_waitBetweenPID = 0; // Number of milliseconds to wait after each PID move

}

long vap_target[5] = {0, 0, 0, 0, 0};

task vap_pid() {

    long error[2] = {0, 0};
    long pError[2] = {0, 0};
    long p[2] = {0, 0};
    long i[2] = {0, 0};
    long d[2] = {0, 0};

    while(true) {

        error[0] = vap_target[0] - conveyor.position(vex::degrees);
        error[1] = vap_target[1] - sensorValue[dgtl1];
        p[0] = error[0];
        p[1] = error[1];
        i[0] = abs(i[0] + error[0]) < vap_kL[0] ? i[0] + error[0] : sgn(i[0] + error[0])*vap_kL[0];
        i[1] = abs(i[1] + error[1]) < vap_kL[0] ? i[1] + error[1] : sgn(i[1] + error[1])*vap_kL[0];
        d[0] = error[0] - pError[0];
        d[1] = error[1] - pError[1];
        motor[port1] = p[0]*vap_kP[0] + i[0]*vap_kI[0] + d[0]*vap_kD[0];
        motor[port1] = p[0]*vap_kP[0] + i[0]*vap_kI[0] + d[0]*vap_kD[0];
        motor[port1] = p[0]*vap_kP[0] + i[0]*vap_kI[0] + d[0]*vap_kD[0];
        motor[port10] = p[1]*vap_kP[0] + i[1]*vap_kI[0] + d[1]*vap_kD[0];
        motor[port10] = p[1]*vap_kP[0] + i[1]*vap_kI[0] + d[1]*vap_kD[0];
        motor[port10] = p[1]*vap_kP[0] + i[1]*vap_kI[0] + d[1]*vap_kD[0];

        sensorValue[dgtl1] = vap_target[2];

        motor[port8] = vap_target[3];

        motor[port9] = vap_target[4];

        wait1Msec(25);

    }

}

void vap_autonomous() {

    vap_init();

    startTask(vap_pid);

    vap_target[0] += 20*vap_ticksPerFoot/12;
    vap_target[1] += 20*vap_ticksPerFoot/12;
    while(abs(sensorValue[dgtl1] - vap_target[0]) > vap_tolerance[0] && abs(sensorValue[dgtl1] - vap_target[1]) > vap_tolerance[0]);
    wait1Msec(vap_waitBetweenPID);
    vap_target[3] = 127;
    wait1Msec(1500);
    vap_target[4] = 300;
    wait1Msec(1500);
    vap_target[0] += 30*vap_ticksPerFoot/12;
    vap_target[1] += 30*vap_ticksPerFoot/12;
    while(abs(sensorValue[dgtl1] - vap_target[0]) > vap_tolerance[0] && abs(sensorValue[dgtl1] - vap_target[1]) > vap_tolerance[0]);
    wait1Msec(vap_waitBetweenPID);
    vap_target[3] = 127;
    wait1Msec(1500);
    vap_target[4] = 300;
    wait1Msec(1500);
    vap_target[0] += 10*vap_ticksPerFoot/12;
    vap_target[1] += 10*vap_ticksPerFoot/12;
    while(abs(sensorValue[dgtl1] - vap_target[0]) > vap_tolerance[0] && abs(sensorValue[dgtl1] - vap_target[1]) > vap_tolerance[0]);
    wait1Msec(vap_waitBetweenPID);
    vap_target[0] += 0.5*vap_ticksPerRotation*vap_ticksPerFoot/12;
    vap_target[1] -= 0.5*vap_ticksPerRotation*vap_ticksPerFoot/12;
    while(abs(sensorValue[dgtl1] - vap_target[0]) > vap_tolerance[0] && abs(sensorValue[dgtl1] - vap_target[1]) > vap_tolerance[0]);
    wait1Msec(vap_waitBetweenPID);
    vap_target[2] = 1;
    wait1Msec(1500);
    vap_target[2] = 0;
    wait1Msec(1500);
    vap_target[4] = 127;
    wait1Msec(3000);

    stopTask(vap_pid);

}