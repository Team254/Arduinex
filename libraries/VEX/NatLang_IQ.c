/*------------------------------------------*\
|*	- Natural Language for VEX IQ		 -			*|
\*------------------------------------------*/
#pragma once
#pragma systemFile            	// eliminates warning for "unreferenced" functions

//#include "JoystickDriver.c"

/*
--------------- Enumerations and Defines ----------------------
*/

#define VexIQClawbot 0
const tMotor noMotorOnPort     = (tMotor) -1;
const tMotor noMotor     = (tMotor) -1;
#define nMaxJoyScaleValue 100

#ifndef NLMovementUnits_H_Blocker
#define NLMovementUnits_H_Blocker
// enum for units
typedef enum tMovementUnits
{
	degrees							= 0,
	rotations						= 1,
	milliseconds				= 2,
	seconds							= 3,
	minutes							= 4
} tMovementUnits;
#endif

typedef enum tIQLCDLine
{
	line1				= 0,
	line2				= 1,
	line3				= 2,
	line4				= 3,
	line5				= 4
} tIQLCDLine;

bool bPopulatedMotorDriveSides = false;
TMotorList internalLeftMotors;
TMotorList internalRightMotors;
short nGlobalJoyScaledValue = nMaxJoyScaleValue;

/*
------------------- Utility Commands --------------------------
*/

void setJoystickScale(short nScaledPercentage = nMaxJoyScaleValue)
{
	if(nScaledPercentage > nMaxJoyScaleValue)
	{
		nGlobalJoyScaledValue = nMaxJoyScaleValue;
	}
	else if(nScaledPercentage < 0)
	{
		nGlobalJoyScaledValue = 0;
	}
	else
	{
		nGlobalJoyScaledValue = nScaledPercentage;
	}
}

void updateMotorDriveTrain()
{
	if(!bPopulatedMotorDriveSides)
	{
		getMotorsWithDriveSideType(driveRight, internalRightMotors);
		getMotorsWithDriveSideType(driveLeft,	 internalLeftMotors);
		bPopulatedMotorDriveSides = true;
	}
}

//This command is here only for LEGACY reasons (to prevent compiler errors)
void setRobotType(short robotType)
{
	return;
}

void displayControllerValues(tIQLCDLine lineNumber = line1, const TVexJoysticks nJoystickValue = ChA)
{
	string sOutputString;
	string sJoystickTemp;

	switch(nJoystickValue)
	{
	case ChA:		sJoystickTemp = "Channel A:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case ChB:		sJoystickTemp = "Channel B:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case ChC:		sJoystickTemp = "Channel C:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case ChD:		sJoystickTemp = "Channel D:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case BtnEUp:	sJoystickTemp = "Btn EUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released" );
					break;
	case BtnEDown:	sJoystickTemp = "Btn EDown:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnFUp:	sJoystickTemp = "Btn FUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnFDown:	sJoystickTemp = "Btn FDown:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnLUp:	sJoystickTemp = "Btn LUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnLDown:	sJoystickTemp = "Btn LDown:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnRUp:	sJoystickTemp = "Btn RUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnRDown:	sJoystickTemp = "Btn RDown";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	}

	int nLineNumber = lineNumber;
	displayTextLine(nLineNumber, sOutputString);
}

void displayMotorValues(tIQLCDLine lineNumber = line1, const tMotor nDeviceIndex = motor1)
{
	TVexIQDeviceTypes nDeviceType;
	TDeviceStatus nDeviceStatus;
	short nDeviceVersion;

	getVexIqDeviceInfo(nDeviceIndex, nDeviceType, nDeviceStatus, nDeviceVersion);
	string sOutputString;

	//No device found.
	if (nDeviceType != vexIQ_SensorMOTOR)
		return;

	sprintf(sOutputString, "Motor(%d) %d deg", nDeviceIndex + 1 , getMotorEncoder((tMotor)nDeviceIndex));
	int nLineNumber = lineNumber;
	displayTextLine(nLineNumber, sOutputString);
}

void displaySensorValues(tIQLCDLine lineNumber = line1, const tSensors nDeviceIndex = port1)
{
	TVexIQDeviceTypes nDeviceType;
	TDeviceStatus nDeviceStatus;
	short nDeviceVersion = 0;
	string sOutputString;
	string sColorTemp;
	int tempValue = 0;

	getVexIqDeviceInfo(nDeviceIndex, nDeviceType, nDeviceStatus, nDeviceVersion);

	if (nDeviceType == vexIQ_SensorNone || nDeviceType == vexIQ_SensorMOTOR)
		return;

	switch (nDeviceType)
	{
	case vexIQ_SensorMOTOR:
		sprintf(sOutputString, "Motor(%d) %d deg", nDeviceIndex + 1 , getMotorEncoder((tMotor)nDeviceIndex));
		break;

	case vexIQ_SensorLED:
		sprintf(sOutputString, "LED(%d) %s", nDeviceIndex + 1, getTouchLEDValue(nDeviceIndex) ? "Pressed" : "Released");
		break;

	case vexIQ_SensorRGB:
		if(getColorMode(nDeviceIndex) == colorTypeGrayscale_Reflected)
		{
			tempValue = getColorGrayscale(nDeviceIndex);
			sprintf(sOutputString, "Color(%d) %d/%d", nDeviceIndex + 1, tempValue, getColorProximity(nDeviceIndex));
		}
		else if(getColorMode(nDeviceIndex) == colorTypeRGB_Hue_Ambient)
		{
			tempValue = getColorHue(nDeviceIndex);
			sprintf(sOutputString, "Color(%d) %d/%d", nDeviceIndex + 1, tempValue, getColorProximity(nDeviceIndex));
		}
		else if(getColorMode(nDeviceIndex) == colorTypeRGB_12Colors_Ambient)
		{
			switch(getColorName(nDeviceIndex))
			{
				case colorRedViolet:	sColorTemp = "RedViolet";	break;
				case colorRed:			sColorTemp = "Red";			break;
				case colorDarkOrange:	sColorTemp = "DarkOrange";	break;
				case colorOrange:		sColorTemp = "Orange";		break;
				case colorDarkYellow:	sColorTemp = "DarkYellow";	break;
				case colorYellow:		sColorTemp = "Yellow";		break;
				case colorLimeGreen:	sColorTemp = "LimeGreen";	break;
				case colorGreen:		sColorTemp = "Green";		break;
				case colorBlueGreen:	sColorTemp = "BlueGreen";	break;
				case colorBlue:			sColorTemp = "Blue";		break;
				case colorDarkBlue:		sColorTemp = "DarkBlue";	break;
				case colorViolet:		sColorTemp = "Violet";		break;

				case colorNone:
				default:				sColorTemp = "None";		break;
			}

			sprintf(sOutputString, "Color(%d) %s", nDeviceIndex + 1, sColorTemp);
		}
		else
		{
			sprintf(sOutputString, "Bad Color Mode (%d)", nDeviceIndex + 1);
		}
		break;

	case vexIQ_SensorGYRO:
		sprintf(sOutputString, "Gyro(%d) %d deg", nDeviceIndex + 1, getGyroDegrees(nDeviceIndex));
		break;

	case vexIQ_SensorSONAR:
			sprintf(sOutputString, "Dist(%d) %d mm", nDeviceIndex + 1, getDistanceValue(nDeviceIndex));
		break;

	case vexIQ_SensorBUMPER:
		sprintf(sOutputString, "Bumper(%d) %s", nDeviceIndex + 1, getBumperValue(nDeviceIndex) ? "Pressed" : "Released");
		break;
	}

	int nLineNumber = lineNumber;
	displayTextLine(nLineNumber, sOutputString);
}

/* 
------------------- display variables ------------------------
*/

// Special enum that allows "Select variable" drop down to be displayed
typedef enum _tSelectVariable {
	kSelectVariableNone = 0
} tSelectVariable;

// Function used in graphical only
void displayVariableValues(tIQLCDLine lineNumber = line1, const tSelectVariable value )
{
}

// We use a macro so the variable can be accessed by name and value
#define displayVariableValues( line, name ) _displayVariableValues( line, #name, name )

// Function that actually displays the value
void _displayVariableValues(tIQLCDLine lineNumber = line1, char *name, float floatValue = 0 )
{
	const int kMaxVariableNameLength = 10;
	char tmpName[kMaxVariableNameLength + 1];
	char sOutputString[kMaxVariableNameLength + 16];

	// name has pre and post " as in "value"
	// we need to strip those off
	if( strlen(name) > 2 ) {
		memset(tmpName, 0, sizeof(tmpName));
		strncpy(tmpName, &(name[1]), kMaxVariableNameLength);
		if( strlen(name)-2 < kMaxVariableNameLength )
			tmpName[strlen(tmpName)-1] = '\0';
		sprintf(sOutputString, "%s = %.2f", &(tmpName[0]), floatValue );
	}
	else
		strcpy(sOutputString, "No variable");

	int nLineNumber = lineNumber;
	displayTextLine(nLineNumber, sOutputString);
}

// Wrapper for displayTextLine to give menu for line number
void displayText(tIQLCDLine lineNumber = line1, const string sString )
{
		int nLineNumber = lineNumber;
		displayTextLine( nLineNumber, "%s", sString);
}

/*
------------------- Low Level Commands ------------------------
*/

void lowLevelMoveDistance(const float quantity, short nLeftSpeed, short nRightSpeed, const tMovementUnits nUnitType)
{
	long nConvertedUnitsLeft = 0;
	long nConvertedUnitsRight = 0;

	if(nUnitType == degrees)
	{
		nConvertedUnitsLeft = quantity;
		nConvertedUnitsRight = quantity;
	}
	else if(nUnitType == rotations)
	{
		nConvertedUnitsLeft = quantity * 360.0;
		nConvertedUnitsRight = quantity * 360.0;
	}
	else
	{
		return;
	}

	updateMotorDriveTrain();

	if(nLeftSpeed < 0)
	{
		nConvertedUnitsLeft *= -1;
		//nLeftSpeed *= -1;
	}

	if(nRightSpeed < 0)
	{
		nConvertedUnitsRight *= -1;
		//nRightSpeed *= -1;
	}

	if(internalLeftMotors[0] != noMotor)	moveMotorTarget(internalLeftMotors[0], nConvertedUnitsLeft, nLeftSpeed);
	if(internalLeftMotors[1] != noMotor)	moveMotorTarget(internalLeftMotors[1], nConvertedUnitsLeft, nLeftSpeed);
	if(internalLeftMotors[2] != noMotor)	moveMotorTarget(internalLeftMotors[2], nConvertedUnitsLeft, nLeftSpeed);
	if(internalLeftMotors[3] != noMotor)	moveMotorTarget(internalLeftMotors[3], nConvertedUnitsLeft, nLeftSpeed);

	if(internalRightMotors[0] != noMotor)	moveMotorTarget(internalRightMotors[0], nConvertedUnitsRight, nRightSpeed);
	if(internalRightMotors[1] != noMotor)	moveMotorTarget(internalRightMotors[1], nConvertedUnitsRight, nRightSpeed);
	if(internalRightMotors[2] != noMotor)	moveMotorTarget(internalRightMotors[2], nConvertedUnitsRight, nRightSpeed);
	if(internalRightMotors[3] != noMotor)	moveMotorTarget(internalRightMotors[3], nConvertedUnitsRight, nRightSpeed);

	sleep(100);

	while(getMotorDriveTrainMoving())
		sleep(5);

	sleep(25);
}

void setMotorSpeeds(short nRightSideSpeed, short nLeftSideSpeed)
{
	if(internalRightMotors[0] != noMotor)	setMotorSpeed(internalRightMotors[0], nRightSideSpeed);
	if(internalRightMotors[1] != noMotor)	setMotorSpeed(internalRightMotors[1], nRightSideSpeed);
	if(internalRightMotors[2] != noMotor)	setMotorSpeed(internalRightMotors[2], nRightSideSpeed);
	if(internalRightMotors[3] != noMotor)	setMotorSpeed(internalRightMotors[3], nRightSideSpeed);

	if(internalLeftMotors[0] != noMotor)	setMotorSpeed(internalLeftMotors[0], nLeftSideSpeed);
	if(internalLeftMotors[1] != noMotor)	setMotorSpeed(internalLeftMotors[1], nLeftSideSpeed);
	if(internalLeftMotors[2] != noMotor)	setMotorSpeed(internalLeftMotors[2], nLeftSideSpeed);
	if(internalLeftMotors[3] != noMotor)	setMotorSpeed(internalLeftMotors[3], nLeftSideSpeed);
}

void lowLevelMoveTiming(float quantity, const short nLeftSpeed, const short nRightSpeed, const tMovementUnits nUnitType)
{
	updateMotorDriveTrain();

	setMotorSpeeds(nRightSpeed, nLeftSpeed);

	if(nUnitType == milliseconds)
		sleep(quantity);
	else if(nUnitType == seconds)
		sleep(quantity * 1000);
	else if(nUnitType == minutes)
		sleep(quantity * 1000 * 60);
	else
		sleep(5);

	setMotorSpeeds(0, 0);

	sleep(25);
}

/*
------------------- Wait Commands -------------------------
*/
void wait(const float quantity = 1.0, const tMovementUnits unitType = seconds)
{
	if(unitType == seconds)
		sleep(quantity * 1000.0);
	else if(unitType == minutes)
		sleep(quantity * 1000.0 * 60.0);
	else if(unitType == milliseconds)
		sleep(quantity);
}



/*
------------------- Discrete Movement -------------------------
*/

#if defined(KioskMode)

	//Blank for now - put it in a different library file.

#else

void forward(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = fabs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;
	}
}

void backward(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed) * -1;
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;
	}
}

void turnLeft(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, -adjustedSpeed, adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, -adjustedSpeed, adjustedSpeed, unitType);
		break;
	}
}

void turnRight(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, adjustedSpeed, -adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, adjustedSpeed, -adjustedSpeed, unitType);
		break;
	}
}

void moveMotor(const tMotor motorPort = motor10, const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	//Rotations - moves in reverse if speed and/or quantity are set negative
	case rotations:
		if(speed < 0 || quantity < 0)
			moveMotorTarget(motorPort, -(adjustedQuantity * 360.0), -adjustedSpeed);
		else
			moveMotorTarget(motorPort, (adjustedQuantity * 360.0), adjustedSpeed);
		waitUntilMotorStop(motorPort);
		break;

	//Degrees - moves in reverse if speed and/or quantity are set negative
	case degrees:
		if(speed < 0 || quantity < 0)
			moveMotorTarget(motorPort, -adjustedQuantity, -adjustedSpeed);
		else
			moveMotorTarget(motorPort, adjustedQuantity, adjustedSpeed);
		waitUntilMotorStop(motorPort);
		break;

	//Milliseconds
	case milliseconds:
		setMotorSpeed(motorPort, speed);
		sleep(adjustedQuantity);
		setMotorSpeed(motorPort, 0);
		break;

	//Seconds
	case seconds:
		setMotorSpeed(motorPort, speed);
		sleep(adjustedQuantity * 1000.0);
		setMotorSpeed(motorPort, 0);
		break;

	//Minutes
	case minutes:
		setMotorSpeed(motorPort, speed);
		sleep(adjustedQuantity * 1000.0 * 60.0);
		setMotorSpeed(motorPort, 0);
		break;
	}

	sleep(25);
}
#endif

/*
------------------- Constant Movements -------------------------
*/

void setMotor(const tMotor motorPort = motor1, const short speed = 50)
{
	setMotorSpeed(motorPort, speed);
}

void stopMotor(const tMotor motorPort = motor1)
{
	setMotorSpeed(motorPort, 0);
}

void stopAllMotors()
{
	TVexIQDeviceTypes nDeviceType;
	TDeviceStatus nDeviceStatus;
	short nDeviceVersion;

	for (short nPortIndex = 0; nPortIndex < 12; ++nPortIndex)
	{
		getVexIqDeviceInfo(nPortIndex, nDeviceType, nDeviceStatus, nDeviceVersion);

		if (nDeviceType != vexIQ_SensorMOTOR)
			continue;

		setMotorSpeed(nPortIndex, 0);
	}
}

void setMultipleMotors(const short speed = 50, const tMotor firstMotor = motor1, const tMotor secondMotor = noMotor, const tMotor thirdMotor = noMotor, const tMotor fourthMotor = noMotor)
{
	if(firstMotor != noMotor) 		setMotorSpeed(firstMotor, speed);
	if(secondMotor != noMotor) 	setMotorSpeed(secondMotor, speed);
	if(thirdMotor != noMotor) 		setMotorSpeed(thirdMotor, speed);
	if(fourthMotor != noMotor) 	setMotorSpeed(fourthMotor, speed);
}

void stopMultipleMotors(const tMotor firstMotor = motor1, const tMotor secondMotor = noMotor, const tMotor thirdMotor = noMotor, const tMotor fourthMotor = noMotor)
{
	if(firstMotor != noMotor) 		setMotorSpeed(firstMotor, 0);
	if(secondMotor != noMotor) 	setMotorSpeed(secondMotor, 0);
	if(thirdMotor != noMotor) 		setMotorSpeed(thirdMotor, 0);
	if(fourthMotor != noMotor) 	setMotorSpeed(fourthMotor, 0);
}

/*
------------------- Timer Commands -------------------------
*/

void resetTimer(TTimers currentTimer = T1)
{
	clearTimer(currentTimer);
}

float getTimer(TTimers currentTimer = T1, const tMovementUnits unitType = seconds)
{
	if(unitType == milliseconds)
		return (time1[currentTimer]);
	else if(unitType == seconds)
		return ((float) time1[currentTimer]) / 1000.0;
	else if(unitType == minutes)
		return ((float) time1[currentTimer]) / (1000.0 * 60.0);

	return 0.0;
}

void lineTrackLeft(const tSensors sensorName = port1, const short threshold = 50, const short speedPrimary = 50, const short speedSecondary = 0)
{
	if(getColorMode(sensorName) != colorTypeGrayscale_Reflected)
		setColorMode(sensorName, colorTypeGrayscale_Reflected);

	updateMotorDriveTrain();

	if(getColorGrayscale(sensorName) > threshold)
		setMotorSpeeds(speedSecondary, speedPrimary);
	else
		setMotorSpeeds(speedPrimary, speedSecondary);
}

void lineTrackRight(const tSensors sensorName = port1, const short threshold = 50, const short speedPrimary = 50, const short speedSecondary = 0)
{
	if(getColorMode(sensorName) != colorTypeGrayscale_Reflected)
		setColorMode(sensorName, colorTypeGrayscale_Reflected);

	updateMotorDriveTrain();

	if(getColorGrayscale(sensorName) < threshold)
		setMotorSpeeds(speedSecondary, speedPrimary);
	else
		setMotorSpeeds(speedPrimary, speedSecondary);
}

/*
------------------- Remote Control Movements -------------------------
*/

void tankControl(TVexJoysticks rightJoystick = ChD, TVexJoysticks leftJoystick = ChA, short threshold = 10)
{
	short nRightSideSpeed;
	short nLeftSideSpeed;

	updateMotorDriveTrain();

	nRightSideSpeed = getJoystickValue(rightJoystick);
	nLeftSideSpeed = getJoystickValue(leftJoystick);

	if(nGlobalJoyScaledValue != nMaxJoyScaleValue)
	{
		nRightSideSpeed = nRightSideSpeed * (nGlobalJoyScaledValue / 100.0);
		nLeftSideSpeed 	= nLeftSideSpeed * (nGlobalJoyScaledValue / 100.0);
	}

	if (abs(getJoystickValue(rightJoystick)) <= abs(threshold))
		nRightSideSpeed = 0;

	if (abs(getJoystickValue(leftJoystick)) <= abs(threshold))
		nLeftSideSpeed = 0;

	setMotorSpeeds(nRightSideSpeed, nLeftSideSpeed);
}

void arcadeControl(TVexJoysticks verticalJoystick = ChA, TVexJoysticks horizontalJoystick = ChB, short threshold = 10)
{
	short nRightSideSpeed;
	short nLeftSideSpeed;

	updateMotorDriveTrain();

	if(abs(vexRT[verticalJoystick]) <= abs(threshold) && abs(vexRT[horizontalJoystick]) <= abs(threshold))
	{
		nRightSideSpeed = 0;
		nLeftSideSpeed 	= 0;
	}
	else
	{
	 	nRightSideSpeed = ((getJoystickValue(verticalJoystick) - getJoystickValue(horizontalJoystick))/2);
		nLeftSideSpeed = ((getJoystickValue(verticalJoystick) + getJoystickValue(horizontalJoystick))/2);

		if(nGlobalJoyScaledValue != nMaxJoyScaleValue)
		{
			nRightSideSpeed = nRightSideSpeed * (nGlobalJoyScaledValue / 100.0);
			nLeftSideSpeed 	= nLeftSideSpeed * (nGlobalJoyScaledValue / 100.0);
		}
	}

	setMotorSpeeds(nRightSideSpeed, nLeftSideSpeed);
}

void armControl(tMotor armMotorPort = motor10, TVexJoysticks upButton = BtnLUp, TVexJoysticks downButton = BtnLDown, short armSpeed = 75)
{
	if(vexRT[upButton])
	{
		setMotorSpeed(armMotorPort, armSpeed);
	}
	else if(vexRT[downButton])
	{
		setMotorSpeed(armMotorPort, -armSpeed);
	}
	else
	{
		setMotorSpeed(armMotorPort, 0);
	}
}

/*
------------------- Datalog wrappers -------------------------
*/

// These globals are used by a task included in the NatLang_Datalog.c
// file
static long								  _datalogUpdateInterval = 50;
static long 								_datalogUpdatePeriod   = 0;

void
datalogRate( const float quantity = 50.0, const tMovementUnits unitType = milliseconds)
{
	long	tmpPeriod;
	
	if(unitType == seconds)
		tmpPeriod = quantity * 1000.0;
	else if(unitType == minutes)
		tmpPeriod = quantity * 1000.0 * 60.0;
	else if(unitType == milliseconds)
		tmpPeriod = quantity;
		
	if( tmpPeriod >= 10 )
		_datalogUpdateInterval = tmpPeriod;
	else
		_datalogUpdateInterval = 10;
}

void 
datalogStart(const float quantity = 5.0, const tMovementUnits unitType = seconds)
{
	if(unitType == seconds)
		_datalogUpdatePeriod = quantity * 1000.0;
	else if(unitType == minutes)
		_datalogUpdatePeriod = quantity * 1000.0 * 60.0;
	else if(unitType == milliseconds)
		_datalogUpdatePeriod = quantity;
}

void
datalogStop()
{
	_datalogUpdatePeriod = 0;
}
