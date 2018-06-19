////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																Load Build Options for LEGO EV3
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "LoadBuildOptionsClearFields.h"
#define	romtype																												// EV3
#define	ramtype																												// EV3
#define	ramfunc 																											// EV3
#define	neartype																											// EV3
#define	no_init 																											// EV3
//#undef inline																												// EV3

#define	bFirmwareStoresMotorType																			// EV3
#define	bFirmwareStoresMotorDriveSide																	// EV3
#define	bIncludeMotorTypeInUploadMessage() true												// EV3
#define	bMotorMirroring																								// EV3
#define	bMotorsWithEncoders																						// EV3
#undef	bMotorsWithCurrentLimiting																		// EV3
#define	bSmartMotorsWithEncoders()   1																// EV3
#define	kSizeOfDefaultPidSettingsTable 0															// EV3
#undef	bAssociateMotorWithEncoderSensor															// EV3
#undef	bHasEncoderTimeStamp																					// EV3
#undef	bHasEncoderVelocity																						// EV3
#undef	bAssociateMotorWithIOPins 																		// EV3
#define	 bIncludeMotorEncoderInUploadMessage() true										// EV3
#undef	 bSupportsSoftwareBasedMotorPWM																// EV3
#undef	 bSupportsSoftwareBasedServoPWM																// EV3
#undef	bHasHardwareAutoDetectionMotors					 											// EV3
#undef	bHasHardwareAutoDetectionSensors					 										// EV3

#define	kNumbOfBreakpoints 16																					// EV3
#define	bUsesFlashStorage																							// EV3
#define	kFlashSectorSize   256																				// EV3
#undef	kSystemClockSpeed																							// EV3

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// EV3
#define	optionalExceptions 																						// EV3
#define	optionalBreakpoints 																					// EV3
#define	optionalDebugSupport																					// EV3
#define	hasBulkUploadlupport																					// EV3
#define	hasOptionalUploadSupport																			// EV3
#define	hasDeviceUploadSupport																				// EV3
#define	optionalTrinaryOpcodes																				// EV3
#define	bHasOpcodeStateMachine																				// EV3

#define	useFloats																											// EV3
#define	useLongs																											// EV3
#define	useStackVariables																							// EV3

#define	hasJoystickDownloadMessageOpcodes															// EV3
#undef	hasJoystickUploadMessageOpcodes																// EV3
#define	hasMemMoveSupport																							// EV3
#define	hasMemCmpSupport																							// EV3
#define	hasStringSupport																							// EV3
#define	has_sscanf_Support																						// EV3
#define	hasTranscendentalSupport																			// EV3

#define	bHasSoundSupport 1																						// EV3
#define	bHasSoundVolume 1																							// EV3
#undef	bHasPlayMusicalNotes																					// EV3
#undef	bHasSoundsInRomChip																						// EV3
#define	bHasSoundDriverOnOff 0																				// EV3
#define	bHasSoundFiles 1																							// EV3
#define	kSoundQueueSize 10																						// EV3

#undef	hasCamera																											// EV3
#undef hasHarvardArchitecture																					// EV3
#define	hasDebugStreamSupport																					// EV3
#define	kDebugStreamDefaultBufferSize 4000														// EV3
#define	kRamBaseAddr 0																								// EV3
#define	bHasDatalog																										// EV3
#define	kDatalogDefaultBufferSize 4000																// EV3
#undef	bHasDatalogSave																								// EV3
#undef	bHasMessageStatistics																					// EV3
#undef	TETRIX_CAPABLE																								// EV3

#undef	hasAlphaNumericLCDDisplayViaUART															// EV3
#define	bHasLCDGraphicsDisplay																				// EV3
#undef	hasLCDMenuFunctions																						// EV3
#define	bPixelByteContainsColumnData() false													// EV3
#define	bPixelRowsLSBFirst()					 true														// EV3
#undef	hasLCDBacklight																								// EV3
#define	kScreenWidth									178															// EV3
#define	kScreenHeight									128															// EV3
#define	kFirstVisibleScreenRow()				0															// EV3
#define	hasLCDButtons																									// EV3
#undef	bHasLCDContrast																								// EV3
#define	bHasRemoteButtons																							// EV3

#define	bUseLookupBreakpointTableInRAM																// EV3
#define	bHasFloatDuringInactivePWM																		// EV3
#define	nnRobotType	rbtTypeLegoEV3																		// EV3
#undef	bHasServoSpecificSourceTypes																	// EV3
#define	bHasSourceTypeSensorRawValue																	// EV3
#define	bHasSourceTypeSensorMode																			// EV3
#define	nUploadSensorValueType sensorUploadSizeFloatX									// EV3
#undef	hasWatchDogTimerFunctions																			// EV3
#undef	bHasClearFlashOpcodes																					// EV3
#undef	hasSpareOption9																								// EV3

#define	kSizeOfTLargeValue							4															// EV3

#define	bHasReadBatteryVoltage																				// EV3
#define	bHasStandardBatteryMonitoring																	// EV3
#define	bHasSoftwareControlledPowerOnOff															// EV3
#define	bHasSoftwareControlledPowerOnOffTiming												// EV3
#undef	UNUSED__23                     																// EV3
#undef	bHasShiftOutOpcode																						// EV3
#define	bHasRandomFunctions																						// EV3
#define	bHasBulkClearSensorFunction																		// EV3
#define	bHasBulkClearMotorFunction																		// EV3

// Flags to control level of sensor support

#define	sensorHandlerWorkBetweenOpcodes()															// EV3
#undef  bSoftwareMustStartADCConversionCycle													// EV3
#undef	useSimpleADCArrayLookup																				// EV3
#undef	includeSonarSensorSupportTwoPins															// EV3  -- For MaxBotic SRP-04 ultrasonic and similar
#undef	includeSonarSensorSupportOnePin																// EV3  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// EV3  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// EV3  -- For minimal f/w size, this can be discarded
#undef	nGyroJitterRange																							// EV3  -- For minimal f/w size, this can be discarded
#undef	bHasSensorBiasSettings																				// EV3
#undef	bHasI2CPort																										// EV3
#undef	bHasDaisyChainedI2C																						// EV3
#undef	nFirstAutoDaisyChainI2CAddress																// EV3
#define	bHasGetSensorRawADValue																				// EV3
#undef	bHasFastSonarSensor																						// EV3

#define	kNumbAnalogSensors 	 4																				// EV3
#define	kNumbDigitalSensors  4																				// EV3
#define	kNumbSensorsOnI2CPorts  0																			// EV3
#define	kMaxNumbofComplicatedSensors  4																// EV3
#define	kNumbOfRealSensors            (4)															// EV3

#undef	bHasSystemTaskForUserProgramComplete													// EV3
#define	bHasSemaphoreSupport																					// EV3
#define	kMaxBytesPerDataBytesUpload   998															// EV3
#define	kReceivedOpcodeSize           1024														// EV3
#undef bGetClearVariablesOnPgmStart																		// EV3
#define	bHasPropertyOpcodes																						// EV3
#define	hasDriveTrainConfiguration																		// EV3
#define	hasJoystickAxisConfiguration																	// EV3
#define	hasMotorOpcodes 																							// EV3
#undef	platformDriversBufferOutgoingSerialData												// EV3
#undef	platformDriversBufferIncomingSerialData												// EV3
#define	DelayTimeForStartupProgram()   0															// EV3
#undef	spareOption16																									// EV3
#undef	spareOption17																									// EV3
#undef	spareOption18																									// EV3
#undef	spareOption19																									// EV3
#undef	spareOption20																									// EV3
#undef	spareOption21																									// EV3
#undef	spareOption22																									// EV3
#undef	spareOption23																									// EV3
#undef	spareOption24																									// EV3
#undef	bUserMessagesAllowed																					// EV3

#undef	bHasMultRobotNetworking																				// EV3
#undef	bSystemUARTSupportsZigBee																			// EV3
#undef	bHasZigBeeFeatureSpare0																				// EV3
#undef	bHasZigBeeFeatureSpare1																				// EV3
#undef	bHasZigBeeFeatureSpare2																				// EV3
#define kNumbOfZigBeeMessageBuffers		0																// EV3

#define	kNumbOfTasks									(20)														// EV3
#define	kNumbOfGlobalVariablesInBytes	(15000)													// EV3
#define	kSpareA01											(16)														// EV3
#define	kNumbOfRealMotors             (4)															// EV3
#define	kNumbOfRealServos             ((ubyte) 4 * 4 * 8)							// EV3
//#define	kNumbOfVirtualSensors         ((ubyte) 8)										// EV3
//#define	kNumbOfVirtualMotors          ((ubyte) (4 * 4 * 2))					// EV3 -- supports the TETRIX motors on the HiTechnic Motor Controllers
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// EV3
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// EV3

#undef	bSupportsInvokeBootloaderOpcode																// EV3

#define	bSupportsFlashWriteOpcodes              (1) 									// EV3
#define	bSpareFlagABC	(0)													 										// EV3
#define	bSupportsRAMWriteOpcodes																			// EV3

#undef	bHasFlashFileSystem																						// EV3
#undef	bHasFlashFileSystemDelete																			// EV3
#undef	kMaxNumbofFlashFiles																					// EV3
#define	kVTOCItemSize 0																								// EV3
#define	kStoreRobotNameInPersistentData 0    													// EV3
#define	bStoreStartupUARTTypesInPersistentData() (0)									// EV3
#define	kSizeOfFlashMemoryPtr 4 																			// EV3
#define	kSizeOfRAMMemoryPtrInHW	 4 																		// EV3

#undef	bHasEvents																										// EV3
#define	kTotalCallSubStackSize				60*kNumbOfTasks									// EV3
#define	kTotalVariablesStackSize			256*kNumbOfTasks								// EV3

#define	kConstantPoolSize  3200																				// EV3 -- Maximum size in bytes of constant pool. None if "#undef".
#define	kStartOfFileSystem 		-1																			// EV3 -- Invalid for EV3
#undef	kStartOfBootloader																						// EV3
#define	bHasDivideByZeroException							 												// EV3
#define	loadBuildOptionSpare1      							 											// EV3
#define	loadBuildOptionSpare2      							 											// EV3
#define	loadBuildOptionSpare3      							 											// EV3
#define	loadBuildOptionSpare4      							 											// EV3
#define	loadBuildOptionSpare5      							 											// EV3
#define	loadBuildOptionSpare6      							 											// EV3
#define	loadBuildOptionSpare7      							 											// EV3
#define	loadBuildOptionSpare8      							 											// EV3
#define	loadBuildOptionSpare9      							 											// EV3
#define	loadBuildOptionSpare10      							 										// EV3
#define	loadBuildOptionSpare11      							 										// EV3
#define	loadBuildOptionSpare12      							 										// EV3
#define	loadBuildOptionSpare13      							 										// EV3
#define	loadBuildOptionSpare14      							 										// EV3
#define	loadBuildOptionSpare15      							 										// EV3

#undef	SystemUartPortCanBeReconfigured																// EV3
#undef	hasUserSerialPorts																						// EV3
#define	getNumbOfSerialPorts()    0																		// EV3
#undef	kSizeOfXmitUartBuffer																					// EV3
#undef	kSizeOfRcvUartBuffer																					// EV3

#define	ARMCPU																												// EV3
#undef	AVRCPU																												// EV3
#undef	STM8CPU																												// EV3
#undef	Spare1CPU																											// EV3
#undef	Spare2CPU																											// EV3
#undef	Spare3CPU																											// EV3
#define	useParmForCurrOpPtr																						// EV3
