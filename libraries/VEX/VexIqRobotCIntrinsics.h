#pragma once
//////////////////////////////////////////////////////////////////////////////////////////////////
//
//													VEX IQ Low Level I2C Bus Transactions
//
//////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
	i2cRsltUndefined,							// Undefined
	i2cRsltNoDeviceOnPort,				// Device index not provisioned
	i2cRsltNotAvailable,					// Bus broken. Device in bootload mode. Etc
	i2cRsltBusy,									// I2C currently busy with previous command
	i2cRsltTimedOut,							// I2C message timed out before response.
	i2cRsltInvalidBufferStatus,		// Invalid data found in I2C record. i.e. 'read' and 'write' counts both zero
	i2cRsltIdleAndOK,							// I2C idle. Last transaction completed successfully
	i2cRsltIdleAndFailed					// I2c idle. Last transaction failed.
} TVexIqI2CResults;

//The Virtual Device Table Uses the portName enumerations for event processing
typedef enum portName {PORT1=0, PORT2, PORT3, PORT4, PORT5, PORT6, PORT7, PORT8,
  PORT9, PORT10, PORT11, PORT12, PORT_CTRLR_A, PORT_CTRLR_B, PORT_CTRLR_C, PORT_CTRLR_D,
  PORT_CTRLR_E_UP, PORT_CTRLR_E_DWN, PORT_CTRLR_F_UP, PORT_CTRLR_F_DWN, PORT_CTRLR_L_UP,
  PORT_CTRLR_L_DWN, PORT_CTRLR_R_UP, PORT_CTRLR_R_DWN, BUTN_CHECK, BUTN_UP,
  BUTN_DOWN, BUTN_X} portName;

intrinsic TVexIqI2CResults vexIqGetI2CStatus(portName port)
				asm(opcdVexIqFunctions, byte(vexIqFcn_getI2CStatus), variable(port), functionReturn);

intrinsic bool StartI2CDeviceBytesWrite(portName port, int nRegisterIndex, const char *pToBuffer, int nNumbOfBytes) // Starts I2C read of bytes
				asm(opcdVexIqFunctions, byte(vexIqFcn_StartI2CDeviceBytesWrite), variable(port), variable(nRegisterIndex), variable(pToBuffer), variable(nNumbOfBytes), functionReturn);

intrinsic bool StartI2CDeviceBytesRead(portName port, int nRegisterIndex, int nNumbOfBytes) // Starts I2C read of bytes into I2CPort read buffer
				asm(opcdVexIqFunctions, byte(vexIqFcn_StartI2CDeviceBytesRead), variable(port), variable(nRegisterIndex), variable(nNumbOfBytes), functionReturn);

intrinsic void StoreI2CDeviceBytesReadFromPortBuffer(portName port, char *pToBuffer, int nNumbOfBytes) // Reads bytes from I2CPort read buffer
				asm(opcdVexIqFunctions, byte(vexIqFcn_StoreI2CDeviceBytesReadFromPortBuffer), variable(port), variable(pToBuffer), variable(nNumbOfBytes));


// LED Sensor

typedef enum
{
	colorFadeNone								= 0x00,
	colorFade72ms								= 0x01,
	colorFade170ms							= 0x02,
	colorFade370ms							= 0x03,
	colorFade770ms							= 0x04,
	colorFade1570ms							= 0x05,
	colorFade3240ms							= 0x06,
	colorFade6480ms							= 0x07,
	colorFade13sec							= 0x08,
	colorFade26sec							= 0x09,
} TI2CLedFadeType;

typedef enum
{
	colorNone				= 0,
	colorRedViolet,
	colorRed,
	colorDarkOrange,
	colorOrange,
	colorDarkYellow,
	colorYellow,
	colorLimeGreen,
	colorGreen,
	colorBlueGreen,
	colorBlue,
	colorDarkBlue,
	colorViolet,
	#define colorLastColor   colorViolet
} TSimpleColors;


intrinsic bool getBumperValue(tSensors nDeviceIndex)																					asm(opcdVexIqFunctions, byte(vexIqFcn_BumperSwitchValue), variable(nDeviceIndex), functionReturn);

intrinsic bool getTouchLEDValue(tSensors nDeviceIndex)																				asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDevicePressed), variable(nDeviceIndex), functionReturn);
intrinsic void setTouchLEDRGB(tSensors nDeviceIndex, const unsigned short red, const unsigned short green, const unsigned short blue) asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceSetColor), variable(nDeviceIndex), variable(red), variable(green), variable(blue));
intrinsic void setTouchLEDBrightness(tSensors nDeviceIndex, const unsigned short brightness)	asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceSetBrightness), variable(nDeviceIndex), variable(brightness));
intrinsic void setTouchLEDFade(tSensors nDeviceIndex, TI2CLedFadeType fadeSetting)						asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceSetFade), variable(nDeviceIndex), variable(fadeSetting));
intrinsic void setTouchLEDColor(tSensors nDeviceIndex, TSimpleColors nColor)									asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceSet12Color), variable(nDeviceIndex), variable(nColor));
intrinsic void setTouchLEDHue(tSensors nDeviceIndex, const unsigned short nHueValue)					asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceSetHue), variable(nDeviceIndex), variable(nHueValue));
intrinsic void setTouchLEDBlinkTime(tSensors nDeviceIndex, const unsigned short nBlinkOnTime, const unsigned short nBlinkOffTime)
																																		asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceSetBlinkMode), variable(nDeviceIndex), variable(nBlinkOnTime), variable(nBlinkOffTime));
intrinsic long getTouchLEDRed(tSensors nDeviceIndex)								asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceGetRed),	variable(nDeviceIndex), functionReturn);
intrinsic long getTouchLEDGreen(tSensors nDeviceIndex)							asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceGetGreen),	variable(nDeviceIndex), functionReturn);
intrinsic long getTouchLEDBlue(tSensors nDeviceIndex)								asm(opcdVexIqFunctions, byte(vexIqFcn_LedCDeviceGetBlue),	variable(nDeviceIndex), functionReturn);


typedef enum
{
	gyroLowSensitivity					= 1,			// 62.5  degrees per second
	gyroNormalSensitivity				= 3,			//  250	 degrees per second
	gyroHighSensitivity					= 6,			// 2000	 degrees per second
} TI2CGyroSensitivity;

typedef enum
{
	gyroCalibrateSamplesOff 		= 0,
	gyroCalibrateSamples64 			= 6,
	gyroCalibrateSamples128 		= 7,
	gyroCalibrateSamples256 		= 8,
	gyroCalibrateSamples512 		= 9,
	gyroCalibrateSamples1024 		= 10,
	gyroCalibrateSamples2048 		= 11,
	gyroCalibrateSamples4096 		= 12,
	gyroCalibrateSamples8192 		= 13,
	gyroCalibrateSamples16384 	= 14,
	gyroCalibrateSamples32768 	= 15
} TI2CGyroCalibrateSamples;

typedef enum
{
	colorTypeUninitialized,
	colorTypeGrayscale_Ambient,
	colorTypeGrayscale_Reflected,
	colorTypeRGB_12Colors_Ambient,
	colorTypeRGB_12Colors_Reflected,
	colorTypeRGB_Hue_Ambient,
	colorTypeRGB_Hue_Reflected,
	colorTypeRGB_Raw_Ambient,
	colorTypeRGB_Raw_Reflected
} TVexIQColorTypes;

typedef struct
{
	uword			nClear;
	uword			nRed;
	uword			nGreen;
	uword			nBlue;
	ubyte			nHue;
	ubyte			nSaturation;
	ubyte			nAssistLED;
	ubyte			nATime;
	ubyte			nControl;
} TColorInfo;

intrinsic void 						 	setColorMode(tSensors nDeviceIndex, TVexIQColorTypes nColorMode)				 					asm(opcdVexIqFunctions, byte(vexIqFcn_ColorSetType),	variable(nDeviceIndex), variable(nColorMode));
intrinsic TVexIQColorTypes 	getColorMode(tSensors nDeviceIndex)																								asm(opcdVexIqFunctions, byte(vexIqFcn_ColorGetType),	variable(nDeviceIndex), functionReturn);
intrinsic long							getColorValue(tSensors nDeviceIndex)																							asm(opcdVexIqFunctions, byte(vexIqFcn_GetColorValue),	variable(nDeviceIndex), functionReturn);

intrinsic long							getColorRedChannel(tSensors nDeviceIndex)																					asm(opcdVexIqFunctions, byte(vexIqFcn_GetColorRawRed),	variable(nDeviceIndex), functionReturn);
intrinsic long							getColorGreenChannel(tSensors nDeviceIndex)																				asm(opcdVexIqFunctions, byte(vexIqFcn_GetColorRawGreen),	variable(nDeviceIndex), functionReturn);
intrinsic long							getColorBlueChannel(tSensors nDeviceIndex)																				asm(opcdVexIqFunctions, byte(vexIqFcn_GetColorRawBlue),	variable(nDeviceIndex), functionReturn);

intrinsic void						 	getColorAdvanced(tSensors nDeviceIndex, TColorInfo *pInfo) 												asm(opcdVexIqFunctions, byte(vexIqFcn_GetColorInfo),	variable(nDeviceIndex), variable(pInfo));
intrinsic TSimpleColors		 	getColorName(tSensors nDeviceIndex)																								asm(opcdVexIqFunctions, byte(vexIqFcn_GetColor12),		variable(nDeviceIndex), functionReturn);
intrinsic unsigned short		getColorGrayscale(tSensors nDeviceIndex)																					asm(opcdVexIqFunctions, byte(vexIqFcn_GetColorGray),		variable(nDeviceIndex), functionReturn);
intrinsic unsigned short		getColorProximity(tSensors nDeviceIndex)																					asm(opcdVexIqFunctions, byte(vexIqFcn_ColorGetProximityRawValue),	variable(nDeviceIndex), functionReturn);

intrinsic long 							getColorSaturation(tSensors nDeviceIndex)																					asm(opcdVexIqFunctions, byte(vexIqFcn_ColorGetSaturation),	variable(nDeviceIndex), functionReturn);
intrinsic long 							getColorHue(tSensors nDeviceIndex)																								asm(opcdVexIqFunctions, byte(vexIqFcn_GetColorHue),	variable(nDeviceIndex), functionReturn);

/*
intrinsic ubyte getColorRed(tSensors nDeviceIndex)
intrinsic ubyte getColorGreen(tSensors nDeviceIndex)
intrinsic ubyte getColorBlue(tSensors nDeviceIndex)
*/

intrinsic void 								resetGyro(tSensors nDeviceIndex)																									asm(opcdVexIqFunctions, byte(vexIqFcn_GyroZeroAngle), variable(nDeviceIndex));

intrinsic long 								getGyroDegrees(tSensors nDeviceIndex)																							asm(opcdVexIqFunctions, byte(vexIqFcn_GyroGetTotalDegrees),	variable(nDeviceIndex), functionReturn);
intrinsic long 								getGyroHeading(tSensors nDeviceIndex)																							asm(opcdVexIqFunctions, byte(vexIqFcn_GyroGetDegrees),variable(nDeviceIndex), functionReturn);
intrinsic long 								getGyroRate(tSensors nDeviceIndex)																								asm(opcdVexIqFunctions, byte(vexIqFcn_GyroGetRate),		variable(nDeviceIndex), functionReturn);

intrinsic float								getGyroDegreesFloat(tSensors nDeviceIndex)																				asm(opcdVexIqFunctions, byte(vexIqFcn_GyroGetTotalDegreesFloat),	variable(nDeviceIndex), functionReturn);
intrinsic float								getGyroHeadingFloat(tSensors nDeviceIndex)																				asm(opcdVexIqFunctions, byte(vexIqFcn_GyroGetDegreesFloat),	variable(nDeviceIndex), functionReturn);
intrinsic float								getGyroRateFloat(tSensors nDeviceIndex)																						asm(opcdVexIqFunctions, byte(vexIqFcn_GyroGetRateFloat),		variable(nDeviceIndex), functionReturn);

intrinsic TI2CGyroSensitivity getGyroSensitivity(tSensors nDeviceIndex)																					asm(opcdVexIqFunctions, byte(vexIqFcn_GyroGetRange),	variable(nDeviceIndex), functionReturn);
intrinsic void 								setGyroSensitivity(tSensors nDeviceIndex, TI2CGyroSensitivity range)							asm(opcdVexIqFunctions, byte(vexIqFcn_GyroSetRange),	variable(nDeviceIndex), variable(range));

intrinsic void								startGyroCalibration(tSensors nDeviceIndex, TI2CGyroCalibrateSamples nCalibrationSetting)		asm(opcdVexIqFunctions, byte(vexIqFcn_GyroStartCalibration),		variable(nDeviceIndex), variable(nCalibrationSetting));
intrinsic bool								getGyroCalibrationFlag(tSensors nDeviceIndex)																								asm(opcdVexIqFunctions, byte(vexIqFcn_GyroReadCalibrationFlag),	variable(nDeviceIndex), functionReturn);
intrinsic bool								getGyroOverRangeFlag(tSensors nDeviceIndex)																									asm(opcdVexIqFunctions, byte(vexIqFcn_GyroReadOverRangeFlag),		variable(nDeviceIndex), functionReturn);

typedef struct
{
	uword			nMinimumDistance;
	uword			nMaximumDistance;
	ubyte			nSNRThreshold;
	ubyte			nBrightnessThreshold;
	ubyte			nFilterFactor;
	ubyte			nTransmitPower;
	uword			nBrightestTargetDistance;
	ubyte			nBrightestTargetSNR;
	ubyte			nBrightestTargetBrightness;
	uword			n1stStrongestTargetDistance;
	ubyte			n1stStrongestTargetSNR;
	ubyte			n1stStrongestTargetBrightness;
	uword			n2ndStrongestTargetDistance;
	ubyte			n2ndStrongestTargetSNR;
	ubyte			n2ndStrongestTargetBrightness;
} TDistanceInfo;


typedef enum
{
	strongestSignal       = 0,
	secondStrongestSignal = 1,
	mostReflective        = 2
} TDistanceFilterMode;

intrinsic void setDistanceSNRThreshold(tSensors nDeviceIndex, const unsigned short nSNRValue)									asm(opcdVexIqFunctions, byte(vexIqFcn_SetDistanceSNRThreshold),	variable(nDeviceIndex), variable(nSNRValue));
intrinsic void setDistanceBrightnessThreshold(tSensors nDeviceIndex, const unsigned short nBrightnessValue)		asm(opcdVexIqFunctions, byte(vexIqFcn_SetDistanceBrightnessThreshold),	variable(nDeviceIndex), variable(nBrightnessValue));
intrinsic void setDistanceFilterFactor(tSensors nDeviceIndex, const unsigned short nFilterFactor)							asm(opcdVexIqFunctions, byte(vexIqFcn_SetDistanceFilterFactor),	variable(nDeviceIndex), variable(nFilterFactor));
intrinsic void setDistanceTransmitPower(tSensors nDeviceIndex, const unsigned short nTransmitPower) 					asm(opcdVexIqFunctions, byte(vexIqFcn_SetDistanceTransmitPower),	variable(nDeviceIndex), variable(nTransmitPower));
intrinsic void setDistanceMinRange(tSensors nDeviceIndex, const unsigned short nMinDistanceInMM)							asm(opcdVexIqFunctions, byte(vexIqFcn_SetDistanceMinRange),	variable(nDeviceIndex), variable(nMinDistanceInMM));
intrinsic void setDistanceMaxRange(tSensors nDeviceIndex, const unsigned short nMaxDistanceInMM)							asm(opcdVexIqFunctions, byte(vexIqFcn_SetDistanceMaxRange),	variable(nDeviceIndex), variable(nMaxDistanceInMM));
intrinsic void setDistanceObjectFilterMode(tSensors nDeviceIndex, TDistanceFilterMode nFilterMode)						asm(opcdVexIqFunctions, byte(vexIqFcn_SetDistanceObjectFilterMode),	variable(nDeviceIndex), variable(nFilterMode));

intrinsic unsigned short getDistanceValue(tSensors nDeviceIndex)																							asm(opcdVexIqFunctions, byte(vexIqFcn_GetDistanceValue),	variable(nDeviceIndex), functionReturn);
intrinsic unsigned short getDistanceStrongest(tSensors nDeviceIndex)																					asm(opcdVexIqFunctions, byte(vexIqFcn_GetDistanceStrongest),	variable(nDeviceIndex), functionReturn);
intrinsic unsigned short getDistanceSecondStrongest(tSensors nDeviceIndex)																		asm(opcdVexIqFunctions, byte(vexIqFcn_GetDistanceSecondStrongest),	variable(nDeviceIndex), functionReturn);
intrinsic unsigned short getDistanceMostReflective(tSensors nDeviceIndex)																			asm(opcdVexIqFunctions, byte(vexIqFcn_GetDistanceMostReflective),	variable(nDeviceIndex), functionReturn);
intrinsic unsigned short getDistanceMinRange(tSensors nDeviceIndex)																						asm(opcdVexIqFunctions, byte(vexIqFcn_GetDistanceMinRange),	variable(nDeviceIndex), functionReturn);
intrinsic unsigned short getDistanceMaxRange(tSensors nDeviceIndex)																						asm(opcdVexIqFunctions, byte(vexIqFcn_GetDistanceMaxRange),	variable(nDeviceIndex), functionReturn);
intrinsic void getDistanceAdvanced(tSensors nDeviceIndex, TDistanceInfo *pDistanceInfo)												asm(opcdVexIqFunctions, byte(vexIqFcn_GetDistanceAdvanced),	variable(nDeviceIndex), variable(pDistanceInfo));
