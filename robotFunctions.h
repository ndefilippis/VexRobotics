#include <unistd.h>
#ifndef ROBOT_F
#define ROBOT_F
int hey;


int servoIn = 0;
int servoOut = 0;
int motor[2];
int motorIndex = 0;

void startUltraSonic( int in, int out )
{
	servoIn = in;
	servoOut = out;
	printf("Servo Connected on port %d and %d\n", servoIn, servoOut);
}
int distance = 0;
float getUltraSonicCm(int in, int out){
	if(in == servoIn && out == servoOut){
		printf("Scanning distance...");
	}
	float returnValue = 300*sin(20*distance++);
	printf("%f\n", returnValue);
	return returnValue;
}

void startMotor(int in, int speed){
	motor[motorIndex++] = in;
	printf("Motor connected on port %d started at speed %d\n", in, speed);
}
void stopMotor(int in){
	printf("Stopped motor %d\n", in);
}
void wait(int n){
	sleep(n);
}
void startSensor(int port){
	printf("Started sensor on port %d\n", port);	
}

int t = 0;
int readSensor(int sensor){
	float result = sin(400000*t++);
	printf("Scanning lower color: %f\n", result);
	if(result < 0.5){
		return 1;
	}
	return 0;
}
#endif