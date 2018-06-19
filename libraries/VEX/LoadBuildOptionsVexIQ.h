////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																Load Build Options for VEX IQ
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "LoadBuildOptionsClearFields.h"
#define	romtype																												// VexIQ
#define	ramtype																												// VexIQ
#define	neartype																											// VexIQ
#define	ramfunc //__ramfunc																						// VexIQ
#define	no_init																												// VexIQ
//#undef inline																												// VexIQ

#define	bFirmwareStoresMotorType																			// VexIQ
#define	bFirmwareStoresMotorDriveSide																	// VexIQ
#define	bIncludeMotorTypeInUploadMessage() true		 										// VexIQ
#define	bMotorMirroring																								// VexIQ
#define	bMotorsWithEncoders																						// VexIQ
#define	bMotorsWithCurrentLimiting																		// VexIQ
#define	bSmartMotorsWithEncoders()   0																// VexIQ
#define	kSizeOfDefaultPidSettingsTable 0															// VexIQ
#undef	bAssociateMotorWithEncoderSensor															// VexIQ
#undef	bHasEncoderTimeStamp																					// VexIQ
#undef	bHasEncoderVelocity																						// VexIQ
#undef	bAssociateMotorWithIOPins 																		// VexIQ
#define	bIncludeMotorEncoderInUploadMessage() true			 							// VexIQ
#undef	bSupportsSoftwareBasedMotorPWM						 										// VexIQ
#undef	bSupportsSoftwareBasedServoPWM						 										// VexIQ
#define	bHasHardwareAutoDetectionMotors					 											// VexIQ
#define	bHasHardwareAutoDetectionSensors					 										// VexIQ

#define	kNumbOfBreakpoints 6																					// VexIQ
#define	kSystemClockSpeed	    80000000																// VexIQ

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// VexIQ
#define	optionalExceptions 																						// VexIQ
#define	optionalBreakpoints 																					// VexIQ
#define	optionalDebugSupport																					// VexIQ
#define	hasBulkUploadlupport																					// VexIQ
#define	hasOptionalUploadSupport																			// VexIQ
#define	hasDeviceUploadSupport																				// VexIQ
#define	optionalTrinaryOpcodes																				// VexIQ
#define	bHasOpcodeStateMachine																				// VexIQ

#define	useFloats																											// VexIQ
#define	useLongs																											// VexIQ
#define	useStackVariables																							// VexIQ

#define	hasJoystickDownloadMessageOpcodes															// VexIQ
#define	hasJoystickUploadMessageOpcodes																// VexIQ
#define	hasMemMoveSupport																							// VexIQ
#define	hasMemCmpSupport																							// VexIQ
#define	hasStringSupport																							// VexIQ
#define	has_sscanf_Support																						// VexIQ
#define	hasTranscendentalSupport																			// VexIQ

#define	bHasSoundSupport 1																						// VexIQ
#define	bHasSoundVolume 0																							// VexIQ
#define	bHasPlayMusicalNotes																					// VexIQ
#define	bHasSoundsInRomChip																						// VexIQ
#define	bHasSoundDriverOnOff 0																				// VexIQ
#define	bHasSoundFiles 0																							// VexIQ
#define	kSoundQueueSize 10																						// VexIQ

#undef	hasCamera																											// VexIQ
#undef	hasHarvardArchitecture 																				// VexIQ
#define	kMaxTimeBetweenMessageChars 75																// VexIQ
#define	hasDebugStreamSupport																					// VexIQ
#define	kDebugStreamDefaultBufferSize 1000														// VexIQ
#define	kRamBaseAddr 0x20000000																				// VexIQ
#define	bHasDatalog																										// VexIQ
#define	kDatalogDefaultBufferSize 1000																// VexIQ
#undef	bHasDatalogSave																								// VexIQ
#undef	bHasMessageStatistics																					// VexIQ
#undef	TETRIX_CAPABLE																								// VexIQ

#undef	hasAlphaNumericLCDDisplayViaUART															// VexIQ
#define	bHasLCDGraphicsDisplay																				// VexIQ
#define	hasLCDMenuFunctions																						// VexIQ
#define	bPixelByteContainsColumnData() false													// VexIQ
#define	bPixelRowsLSBFirst()					 false													// VexIQ
#undef	hasLCDBacklight																								// VexIQ
#define	kScreenWidth                      128													// VexIQ
#define	kScreenHeight                      45													// VexIQ
#define	kFirstVisibleScreenRow()            0													// VexIQ
#define	hasLCDButtons																									// VexIQ
#undef	hasStatusLEDs																									// VexIQ
#undef	bHasLCDContrast																								// VexIQ
#define	bHasRemoteButtons																							// VexIQ

#define	bUseLookupBreakpointTableInRAM																// VexIQ
#undef	bHasFloatDuringInactivePWM																		// VexIQ
#define	nnRobotType	rbtTypeVexIQ																			// VexIQ
#undef	bHasServoSpecificSourceTypes																	// VexIQ
#undef	bHasSourceTypeSensorRawValue																	// VexIQ
#undef	bHasSourceTypeSensorMode																			// VexIQ
#define	nUploadSensorValueType sensorUploadSizeShortX									// VexIQ
#undef	hasWatchDogTimerFunctions																			// VexIQ
#define	bHasClearFlashOpcodes																					// VexIQ
#undef	hasSpareOption9																								// VexIQ

#define	kSizeOfTLargeValue				 4																	// VexIQ

#define	bHasReadBatteryVoltage																				// VexIQ
#undef	bHasStandardBatteryMonitoring																	// VexIQ
#undef	bHasSoftwareControlledPowerOnOff															// VexIQ
#undef	bHasSoftwareControlledPowerOnOffTiming												// VexIQ
#undef	UNUSED__23                     																// VexIQ
#undef	bHasShiftOutOpcode																						// VexIQ
#define	bHasRandomFunctions																						// VexIQ
#define	bHasBulkClearSensorFunction																		// VexIQ
#define	bHasBulkClearMotorFunction																		// VexIQ

// Flags to control level of sensor support

#undef	sensorHandlerWorkBetweenOpcodes																// VexIQ

extern int nSensorWorkBetweenCyclesCounter;
extern void sensorHandlerWorkBetweenOpcodesLowLevel(void);
#define kCyclesBetweenSensorWorkChecks 10

#define sensorHandlerWorkBetweenOpcodes()\
{\
	if (nSensorWorkBetweenCyclesCounter < kCyclesBetweenSensorWorkChecks)\
		++nSensorWorkBetweenCyclesCounter;\
	else\
	{\
		nSensorWorkBetweenCyclesCounter = 0;\
		sensorHandlerWorkBetweenOpcodesLowLevel();\
	}\
}

#undef  bSoftwareMustStartADCConversionCycle													// VexIQ
#undef	useSimpleADCArrayLookup																				// VexIQ
#undef	includeSonarSensorSupportTwoPins															// VexIQ  -- For MaxBotic SRP-04 ultrasonic and similar
#undef	includeSonarSensorSupportOnePin																// VexIQ  -- For Parallax Ping ultrasonic and similar
#undef	includeEncoderSensorSupport																		// VexIQ  -- For minimal f/w size, this can be discarded
#undef	includeGyroAndAccelSupport																		// VexIQ  -- For minimal f/w size, this can be discarded
#define	nGyroJitterRange 4																						// VexIQ
#define	bHasSensorBiasSettings																				// VexIQ
#undef	bHasI2CPort																										// VexIQ
#undef	bHasDaisyChainedI2C																						// VexIQ
#define	nFirstAutoDaisyChainI2CAddress  0x60													// VexIQ  -- First address for automatically assigned I2C addresses
#undef	bHasGetSensorRawADValue																				// VexIQ
#undef	bHasFastSonarSensor																						// VexIQ

#define	kNumbAnalogSensors 						 0															// VexIQ
#define	kNumbDigitalSensors						12															// VexIQ
#define	kNumbSensorsOnI2CPorts				 0															// VexIQ
#define	kMaxNumbofComplicatedSensors  12															// VexIQ
#define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts) // VexIQ

#define	bHasSystemTaskForUserProgramComplete													// VexIQ
#define	bHasSemaphoreSupport																					// VexIQ
#define	kMaxBytesPerDataBytesUpload   240															// VexIQ
#define	kReceivedOpcodeSize           240															// VexIQ
#undef	bGetClearVariablesOnPgmStart																	// VexIQ
#define	bHasPropertyOpcodes																						// VexIQ
#define	hasDriveTrainConfiguration																		// VexIQ
#define	hasJoystickAxisConfiguration																	// VexIQ
#define	hasMotorOpcodes																								// VexIQ
#undef	platformDriversBufferOutgoingSerialData												// VexIQ
#define	platformDriversBufferIncomingSerialData												// VexIQ
#define	DelayTimeForStartupProgram()   0															// VexIQ
#undef	spareOption16																									// VexIQ
#undef	spareOption17																									// VexIQ
#undef	spareOption18																									// VexIQ
#undef	spareOption19																									// VexIQ
#undef	spareOption20																									// VexIQ
#undef	spareOption21																									// VexIQ
#undef	spareOption22																									// VexIQ
#undef	spareOption23																									// VexIQ
#undef	spareOption24																									// VexIQ
#undef	bUserMessagesAllowed																					// VexIQ

#undef	bHasMultRobotNetworking																				// VexIQ
#undef 	bSystemUARTSupportsZigBee																			// VexIQ
#undef	bHasZigBeeFeatureSpare0																				// VexIQ
#undef	bHasZigBeeFeatureSpare1																				// VexIQ
#undef	bHasZigBeeFeatureSpare2																				// VexIQ
#define kNumbOfZigBeeMessageBuffers		0																// VexIQ

#define	kNumbOfTasks									(5)															// VexIQ
#define	kNumbOfGlobalVariablesInBytes	(2500)													// VexIQ
#define	kSpareA01											(0)															// VexIQ
#define	kNumbOfRealMotors             (12)														// VexIQ
#define	kNumbOfRealServos             ((ubyte) 12)										// VexIQ
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// VexIQ
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// VexIQ

#undef	bSupportsInvokeBootloaderOpcode																// VexIQ
#define	bSupportsFlashWriteOpcodes	(1)																// VexIQ
#define	bSpareFlagABC	(0)																							// VexIQ
#define	bSupportsRAMWriteOpcodes																			// VexIQ

#define	bHasFlashFileSystem																						// VexIQ
#undef	bHasFlashFileSystemDelete																			// VexIQ
#define	bUsesFlashStorage																							// VexIQ
#define	kFlashSectorSize							1024														// VexIQ
#define	kMaxNumbofFlashFiles					60															// VexIQ
#define	kVTOCItemSize									4																// VexIQ
#define	kStoreRobotNameInPersistentData 0    													// VexIQ
#define	bStoreStartupUARTTypesInPersistentData() (1)									// VexIQ
#define	kSizeOfFlashMemoryPtr					4																// VexIQ
#define	kSizeOfRAMMemoryPtrInHW				4																// VexIQ

#undef	bHasEvents																										// VexIQ
#define	kTotalCallSubStackSize				60*kNumbOfTasks									// VexIQ
#define	kTotalVariablesStackSize			256*kNumbOfTasks								// VexIQ
#define	kConstantPoolSize							3200														// VexIQ -- Maximum size in bytes of constant pool. None if "#undef".
#define	kStartOfFileSystem 						0x00034000											// VexIQ -- Byte (and not word) address
#undef	kStartOfBootloader																						// VexIQ
#define	bHasDivideByZeroException							 												// VexIQ
#define	loadBuildOptionSpare1      							 											// VexIQ
#define	loadBuildOptionSpare2      							 											// VexIQ
#define	loadBuildOptionSpare3      							 											// VexIQ
#define	loadBuildOptionSpare4      							 											// VexIQ
#define	loadBuildOptionSpare5      							 											// VexIQ
#define	loadBuildOptionSpare6      							 											// VexIQ
#define	loadBuildOptionSpare7      							 											// VexIQ
#define	loadBuildOptionSpare8      							 											// VexIQ
#define	loadBuildOptionSpare9      							 											// VexIQ
#define	loadBuildOptionSpare10      							 										// VexIQ
#define	loadBuildOptionSpare11      							 										// VexIQ
#define	loadBuildOptionSpare12      							 										// VexIQ
#define	loadBuildOptionSpare13      							 										// VexIQ
#define	loadBuildOptionSpare14      							 										// VexIQ
#define	bHasUserMessaging      							 										      // VexIQ

#undef	SystemUartPortCanBeReconfigured																// VexIQ
#undef	hasUserSerialPorts																						// VexIQ
#define	getNumbOfSerialPorts()			1																	// VexIQ
#define	kSizeOfXmitUartBuffer 		256																	// VexIQ
#define	kSizeOfRcvUartBuffer	 		256																	// VexIQ

#define	ARMCPU																												// VexIQ
#undef	AVRCPU																												// VexIQ
#undef	STM8CPU																												// VexIQ
#undef	Spare1CPU																											// VexIQ
#undef	Spare2CPU																											// VexIQ
#undef	Spare3CPU																											// VexIQ
#define	useParmForCurrOpPtr																						// VexIQ
