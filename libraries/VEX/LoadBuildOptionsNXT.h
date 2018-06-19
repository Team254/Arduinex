////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																Load Build Options for LEGO NXT
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "LoadBuildOptionsClearFields.h"
#define	romtype																												// NXT
#define	ramtype																												// NXT
#define	ramfunc __ramfunc																							// NXT
#define	neartype																											// NXT
#define	no_init __no_init																							// NXT
//#undef inline																												// NXT

#undef	bFirmwareStoresMotorType																			// NXT
#define	bFirmwareStoresMotorDriveSide																	// NXT
#define	 bIncludeMotorTypeInUploadMessage() false											// NXT
#define	bMotorMirroring																								// NXT
#define	bMotorsWithEncoders																						// NXT
#undef	bMotorsWithCurrentLimiting																		// NXT
#define	bSmartMotorsWithEncoders()   1																// NXT
#define	kSizeOfDefaultPidSettingsTable 0															// NXT
#undef	bAssociateMotorWithEncoderSensor															// NXT
#undef	bHasEncoderTimeStamp																					// NXT
#undef	bHasEncoderVelocity																						// NXT
#undef	bAssociateMotorWithIOPins 																		// NXT
#define	 bIncludeMotorEncoderInUploadMessage() true										// NXT
#undef	 bSupportsSoftwareBasedMotorPWM																// NXT
#undef	 bSupportsSoftwareBasedServoPWM																// NXT
#undef	bHasHardwareAutoDetectionMotors					 											// NXT
#undef	bHasHardwareAutoDetectionSensors					 										// NXT

#define	kNumbOfBreakpoints 16																					// NXT
#define	bUsesFlashStorage																							// NXT
#define	kFlashSectorSize   256																				// NXT
#undef	kSystemClockSpeed																							// NXT

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// NXT
#define	optionalExceptions 																						// NXT
#define	optionalBreakpoints 																					// NXT
#define	optionalDebugSupport																					// NXT
#define	hasBulkUploadlupport																					// NXT
#define	hasOptionalUploadSupport																			// NXT
#undef	hasDeviceUploadSupport																				// NXT
#define	optionalTrinaryOpcodes																				// NXT
#undef	bHasOpcodeStateMachine																				// NXT

#define	useFloats																											// NXT
#define	useLongs																											// NXT
#define	useStackVariables																							// NXT

#define	hasJoystickDownloadMessageOpcodes															// NXT
#undef	hasJoystickUploadMessageOpcodes																// NXT
#define	hasMemMoveSupport																							// NXT
#define	hasMemCmpSupport																							// NXT
#define	hasStringSupport																							// NXT
#define	has_sscanf_Support																						// NXT
#define	hasTranscendentalSupport																			// NXT

#define	bHasSoundSupport 1																						// NXT
#define	bHasSoundVolume 1																							// NXT
#undef	bHasPlayMusicalNotes																					// NXT
#undef	bHasSoundsInRomChip																						// NXT
#define	bHasSoundDriverOnOff 0																				// NXT
#define	bHasSoundFiles 1																							// NXT
#define	kSoundQueueSize 10																						// NXT

#undef	hasCamera																											// NXT
#undef hasHarvardArchitecture																					// NXT
#define	hasDebugStreamSupport																					// NXT
#define	kDebugStreamDefaultBufferSize 4000														// NXT
#define	kRamBaseAddr 0																								// NXT
#define	bHasDatalog																										// NXT
#define	kDatalogDefaultBufferSize 4000																// NXT
#define	bHasDatalogSave																								// NXT
#undef	bHasMessageStatistics																					// NXT
#define	TETRIX_CAPABLE																								// NXT

#undef	hasAlphaNumericLCDDisplayViaUART															// NXT
#define	bHasLCDGraphicsDisplay																				// NXT
#undef	hasLCDMenuFunctions																						// NXT
#define	bPixelByteContainsColumnData() true														// NXT
#define	bPixelRowsLSBFirst()					 true														// NXT
#undef	hasLCDBacklight																								// NXT
#define	kScreenWidth						 100																	// NXT
#define	kScreenHeight							64																	// NXT
#define	kFirstVisibleScreenRow()   0																	// NXT
#define	hasLCDButtons																									// NXT
#define	bHasLCDContrast																								// NXT
#define	bHasRemoteButtons																							// NXT

#undef	bUseLookupBreakpointTableInRAM																// NXT
#define	bHasFloatDuringInactivePWM																		// NXT
#define	nnRobotType	rbtTypeNXT																				// NXT
#define	bHasServoSpecificSourceTypes																	// NXT
#define	bHasSourceTypeSensorRawValue																	// NXT
#define	bHasSourceTypeSensorMode																			// NXT
#define	nUploadSensorValueType sensorUploadSizeShortX									// NXT
#undef	hasWatchDogTimerFunctions																			// NXT
#undef	bHasClearFlashOpcodes																					// NXT
#undef	hasSpareOption9																								// NXT

#define	kSizeOfTLargeValue							4															// NXT

#define	bHasReadBatteryVoltage																				// NXT
#define	bHasStandardBatteryMonitoring																	// NXT
#define	bHasSoftwareControlledPowerOnOff															// NXT
#define	bHasSoftwareControlledPowerOnOffTiming												// NXT
#undef	UNUSED__23                     																// NXT
#undef	bHasShiftOutOpcode																						// NXT
#define	bHasRandomFunctions																						// NXT
#define	bHasBulkClearSensorFunction																		// NXT
#define	bHasBulkClearMotorFunction																		// NXT

// Flags to control level of sensor support

#define	sensorHandlerWorkBetweenOpcodes()															// NXT
#undef  bSoftwareMustStartADCConversionCycle													// NXT
#undef	useSimpleADCArrayLookup																				// NXT
#undef	includeSonarSensorSupportTwoPins															// NXT  -- For MaxBotic SRP-04 ultrasonic and similar
#undef	includeSonarSensorSupportOnePin																// NXT  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// NXT  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// NXT  -- For minimal f/w size, this can be discarded
#undef	nGyroJitterRange																							// NXT  -- For minimal f/w size, this can be discarded
#undef	bHasSensorBiasSettings																				// NXT
#undef	bHasI2CPort																										// NXT
#undef	bHasDaisyChainedI2C																						// NXT
#undef	nFirstAutoDaisyChainI2CAddress																// NXT
#define	bHasGetSensorRawADValue																				// NXT
#undef	bHasFastSonarSensor																						// NXT

#define	kNumbAnalogSensors 	 4																				// NXT
#define	kNumbDigitalSensors  4																				// NXT
#define	kNumbSensorsOnI2CPorts  0																			// NXT
#define	kMaxNumbofComplicatedSensors  4																// NXT
#define	kNumbOfRealSensors            (4)															// NXT

#undef	bHasSystemTaskForUserProgramComplete													// NXT
#define	bHasSemaphoreSupport																					// NXT
#define	kMaxBytesPerDataBytesUpload   59															// NXT
#define	kReceivedOpcodeSize           70															// NXT
#undef bGetClearVariablesOnPgmStart																		// NXT
#define	bHasPropertyOpcodes																						// NXT
#define	hasDriveTrainConfiguration																		// NXT
#define	hasJoystickAxisConfiguration																	// NXT
#define	hasMotorOpcodes																								// NXT
#undef	platformDriversBufferOutgoingSerialData												// NXT
#undef	platformDriversBufferIncomingSerialData												// NXT
#define	DelayTimeForStartupProgram()   0															// NXT
#undef	spareOption16																									// NXT
#undef	spareOption17																									// NXT
#undef	spareOption18																									// NXT
#undef	spareOption19																									// NXT
#undef	spareOption20																									// NXT
#undef	spareOption21																									// NXT
#undef	spareOption22																									// NXT
#undef	spareOption23																									// NXT
#undef	spareOption24																									// NXT
#define	bUserMessagesAllowed																					// NXT

#undef	bHasMultRobotNetworking																				// NXT
#undef	bSystemUARTSupportsZigBee																			// NXT
#undef	bHasZigBeeFeatureSpare0																				// NXT
#undef	bHasZigBeeFeatureSpare1																				// NXT
#undef	bHasZigBeeFeatureSpare2																				// NXT
#define kNumbOfZigBeeMessageBuffers		0																// NXT

#define	kNumbOfTasks									(20)														// NXT
#define	kNumbOfGlobalVariablesInBytes	(15000)													// NXT
#define	kSpareA01											(16)														// NXT
#define	kNumbOfRealMotors             (3)															// NXT
#define	kNumbOfRealServos             ((ubyte) 4 * 4 * 8)							// NXT
#define	kNumbOfVirtualSensors         ((ubyte) 8)											// NXT
#define	kNumbOfVirtualMotors          ((ubyte) (4 * 4 * 2))						// NXT -- supports the TETRIX motors on the HiTechnic Motor Controllers

#undef	bSupportsInvokeBootloaderOpcode																// NXT

#define	bSupportsFlashWriteOpcodes              (1) 									// NXT
#define	bSpareFlagABC	(0)													 										// NXT
#define	bSupportsRAMWriteOpcodes																			// NXT

#undef	bHasFlashFileSystem																						// NXT
#undef	bHasFlashFileSystemDelete																			// NXT
#undef	kMaxNumbofFlashFiles																					// NXT
#define kVTOCItemSize 0 																							// NXT
#define	kStoreRobotNameInPersistentData 0    													// NXT
#define	bStoreStartupUARTTypesInPersistentData() (0)									// NXT
#define	kSizeOfFlashMemoryPtr 4 																			// NXT
#define	kSizeOfRAMMemoryPtrInHW	 4 																		// NXT

#define	bHasEvents																										// NXT
#define	kTotalCallSubStackSize				60*kNumbOfTasks									// NXT
#define	kTotalVariablesStackSize			256*kNumbOfTasks								// NXT

#define	kConstantPoolSize  3200																				// NXT -- Maximum size in bytes of constant pool. None if "#undef".
#define	kStartOfFileSystem -1																					// NXT -- Invalid for NXT
#undef	kStartOfBootloader																						// NXT
#define	bHasDivideByZeroException							 												// NXT
#define	loadBuildOptionSpare1      							 											// NXT
#define	loadBuildOptionSpare2      							 											// NXT
#define	loadBuildOptionSpare3      							 											// NXT
#define	loadBuildOptionSpare4      							 											// NXT
#define	loadBuildOptionSpare5      							 											// NXT
#define	loadBuildOptionSpare6      							 											// NXT
#define	loadBuildOptionSpare7      							 											// NXT
#define	loadBuildOptionSpare8      							 											// NXT
#define	loadBuildOptionSpare9      							 											// NXT
#define	loadBuildOptionSpare10      							 										// NXT
#define	loadBuildOptionSpare11      							 										// NXT
#define	loadBuildOptionSpare12      							 										// NXT
#define	loadBuildOptionSpare13      							 										// NXT
#define	loadBuildOptionSpare14      							 										// NXT
#define	loadBuildOptionSpare15      							 										// NXT

#undef	SystemUartPortCanBeReconfigured																// NXT
#undef	hasUserSerialPorts																						// NXT
#define	getNumbOfSerialPorts()    0																		// NXT
#undef	kSizeOfXmitUartBuffer																					// NXT
#undef	kSizeOfRcvUartBuffer																					// NXT

#define	ARMCPU																												// NXT
#undef	AVRCPU																												// NXT
#undef	STM8CPU																												// NXT
#undef	Spare1CPU																											// NXT
#undef	Spare2CPU																											// NXT
#undef	Spare3CPU																											// NXT
#define	useParmForCurrOpPtr																						// NXT