int rightMotor	= 9;
int leftMotor	= 8;
int sensorIn	= 1;
int sensorOut	= 3;
int leftSensor 	= 7;
int rightSensor = 5;

void autoControl( void ){
	printf("Starting userControl\n");
	startUltraSonic(sensorIn, sensorOut);
	startSensor(leftSensor);
	startSensor(rightSensor);
	//startMotor(leftMotor);
	//startMotor(rightMotor);
	while( 1 ){
		//start turning until we find something
		startMotor(leftMotor, -1);
		startMotor(rightMotor, 1);
		int distance = getUltraSonicCm(sensorIn, sensorOut);
		int count = 0;
		//if the absoute value of the origianl distance we foun d and the time now is greater than 100 cm,
		//or we've spent more than ten seconds looking, continue;
		while(fabs(distance-getUltraSonicCm(sensorIn, sensorOut)) < 100 && count <= 10){
			count++;
			wait(1);
		}
		stopMotor(leftMotor);
		stopMotor(rightMotor);
		//if we started looking at a block, rotate in the other direction for a little bit
		if(distance < getUltraSonicCm(sensorIn, sensorOut)){
			startMotor(leftMotor,   1);
			startMotor(rightMotor, -1);
			wait(1);
		}
		startMotor(leftMotor, 127);
		startMotor(rightMotor, 127);
		//I just assme readSensor retrns 1 when it sees black. I have no idea how it actually works, so replace 1
		//with whatever it actually returns when it sees black
		while(readSensor(leftSensor) != 1 && readSensor(rightSensor) != 1){
			wait(0); // should be an actual number, but I just wrote wait to accept an int. 
		}
		printf("\n");
	}
}