////////////////////////////////////////////////////////////////////////////////////////////////
//
//                         NXT I/O Map Access
//
// This include file is for expert users / hackers!
//
// It provides direct "extern" access to the NXT firmware I/O Maps. If you're not familiar with
// IOMaps, then best to not use this file.
//
////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(NXT_IOMAP_Access__H_) && defined(NXT)
#define NXT_IOMAP_Access__H_

typedef long SLONG;
typedef long ULONG;
typedef word UWORD;
typedef word SWORD;
typedef byte UBYTE;
typedef byte SBYTE;



///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                        I/O Map for  Motor Access
//
// The instrinsic variable 'nMotorIOMap' will provide complete access to the IOMap for motors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////



typedef enum TMotorMode
{
	COAST         = 0x00,   // Dick's add
	MOTORON       = 0x01,
	BRAKE         = 0x02,
	REGULATED     = 0x04,   // Dick's change -- Regulated flag is not used!

	OFFCOAST_UNR  = 0x00,
	ON_COAST_UNR  = 0x01,
	OFFBRAKE_UNR  = 0x02,
	ON_BRAKE_UNR  = 0x03,
	OFFCOAST_REG  = 0x04,
	ON_COAST_REG  = 0x05,
	OFFBRAKE_REG  = 0x06,
	ON_BRAKE_REG  = 0x07,

	REG_METHOD    = 0xF0   /* Regulation methods - to be designed! */
} TMotorMode;

typedef enum TRobotCFlags
{
	kMirrorMotor        = 0x01,
	//kClosedLoopSpeed    = 0x02,
	kInactiveFloatMode  = 0x04,
} TRobotCFlags;

typedef enum TRegMode
{
	REGULATION_MODE_NONE,
	REGULATION_MODE_MOTOR_SPEED,
	REGULATION_MODE_MOTOR_SYNC,
} TRegMode;

typedef   struct OUTPUT
{
	SLONG     nCumulativeEncoder;	// R  - Holds current number of counts, since last reset, updated every 1 mS
	SLONG     BlockTachoCount;		// R  - Holds current number of counts for the current output block
	SLONG     nUserEncoderCount;  // R  - Holds current number of counts for the rotation counter to the output. Was named "RotationCount"
	ULONG     TachoLimit;					// RW - Holds number of counts to travel, 0 => Run forever
	SWORD     MotorRPM;						// !! Is not updated, will be removed later !!
	UBYTE     Flags;							// RW - Holds flags for which data should be updated
	TMotorMode Mode;							// RW - Holds motor mode: Run, Break, regulated, ...
																// Only brake field is used in ROBOTC -- other fields are redundant!!!
	SBYTE     Speed;							// RW - Holds the wanted speed
	SBYTE     ActualSpeed;				// R  - Holds the current motor speed -- i.e. power level to AVR!! Very transient based on PID.
	SBYTE     RegPParameter;			// RW - Holds the P-constant use din the regulation, Is set to a default value at init => Setting this value is optional for the user
	SBYTE     RegIParameter;			// RW - Holds the I-constant use din the regulation, Is set to a default value at init => Setting this value is optional for the user
	SBYTE     RegDParameter;      // RW - Holds the D-constant use din the regulation, Is set to a default value at init => Setting this value is optional for the user
	TNxtRunState	RunState;				// RW - Holds the current RunState in the output module
	TRegMode  RegMode;						// RW - Tells which regulation mode should be used
	UBYTE     Overloaded;					// R  - True if the motor has been overloaded within speed control regulation
	SBYTE     SyncTurnParameter;	// RW - Holds the turning parameter need within MoveBlock

	TRobotCFlags   nRobotCFlags;  // RW - Used by ROBOTC / Robolab to indicate "speed regulation is desired" -- was SpareOne
	SBYTE     nLastPhysicalNonZeroSpeedSetting;// RW - Used by ROBOTC / Robolab to indicate "last speed setting"      -- was SpareTwo
	UBYTE     SpareThree;
} OUTPUT;


typedef   struct IOMAPOUTPUT
{
	OUTPUT  Outputs[3];
	UBYTE   PwnFreq;
} IOMAPOUTPUT;

intrinsic const IOMAPOUTPUT  propertyIndex(nMotorIOMap, parmSourceExternMemoryRef, kExternMotorIOMAPAddress);


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                   I/O Map for  Sensor Access
//
// The instrinsic variable 'nSensorIOMap' will provide complete access to the IOMap for sensors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


typedef   struct INPUT
{
	UWORD   CustomZeroOffset;           // Set the offset of the Custom sensor
	UWORD   ADRaw;
	UWORD   SensorRaw;
	SWORD   SensorValue;

	TSensorTypes  SensorType;
	TSensorModes  SensorMode;
	bool 					SensorBoolean;

	UBYTE   DigiPinsDir;                // Bit mask of direction of the Digital pins. 1 is output 0 is input
	UBYTE   DigiPinsIn;                 // Bit mask. Contains the status of the digital pins
	UBYTE   DigiPinsOut;                // Sets the output level of the digital pins
	UBYTE   CustomPctFullScale;         // Sets the Pct full scale of the Custom sensor
	UBYTE   CustomActiveStatus;         // Sets the active or inactive state of the CUSTOM sensor

	UBYTE   InvalidData;                // Indicates whether data is invalid (1) or valid (0)

	UBYTE   Spare1;
	UBYTE   Spare2;
	UBYTE   Spare3;

} INPUT;


typedef struct IOMAPINPUT
{
	INPUT   Inputs[4];
}IOMAPINPUT;

intrinsic const IOMAPINPUT  propertyIndex(nSensorIOMap, parmSourceExternMemoryRef, kExternSensorIOMAPAddress);

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                   I/O Map for User Interface
//
// The instrinsic variable 'nSensorIOMap' will provide complete access to the IOMap for sensors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


// Constants related to Flags
enum
{
	UI_UPDATE                   = 0x01,         // W  - Make changes take effect
	UI_DISABLE_LEFT_RIGHT_ENTER = 0x02,         // RW - Disable left, right and enter button
	UI_DISABLE_EXIT             = 0x04,         // RW - Disable exit button
	UI_REDRAW_STATUS            = 0x08,         // W  - Redraw entire status line
	UI_RESET_SLEEP_TIMER        = 0x10,         // W  - Reset sleep timeout timer
	//UI_EXECUTE_LMS_FILE         = 0x20,         // W  - Execute LMS file in "LMSfilename" (Try It)
	UI_BUSY                     = 0x40,         // R  - UI busy running or datalogging (popup disabled)
	UI_ENABLE_STATUS_UPDATE     = 0x80          // W  - Enable status line to be updated
};

// Constants related to State
typedef enum TGUIStates
{
	INIT_DISPLAY,                               // RW - Init display and load font, menu etc.
	INIT_LOW_BATTERY,                           // R  - Low battery voltage at power on
	INIT_INTRO,                                 // R  - Display intro
	INIT_WAIT,                                  // RW - Wait for initialization end
	INIT_MENU,                                  // RW - Init menu system
	NEXT_MENUxxx,                               // RW - Next menu icons ready for drawing
	UI_ProcessMenu,                             // RW - Execute function and draw menu icons
	TEST_BUTTONSxxx,                            // RW - Wait for buttons to be pressed
	LEFT_PRESSED,                               // RW - Load selected function and next menu id
	RIGHT_PRESSED,                              // RW - Load selected function and next menu id
	ENTER_PRESSED,                              // RW - Load selected function and next menu id
	EXIT_PRESSED,                               // RW - Load selected function and next menu id
	CONNECT_REQUEST,                            // RW - Request for connection accept
	EXECUTE_FILExxx,                            // RW - Execute file in "LMSfilename"
	EXECUTING_FILEzzz,                          // R  - Executing file in "LMSfilename"
	LOW_BATTERY,                                // R  - Low battery at runtime
	BT_ERROR                                    // R  - BT error
} TGUIStates;
#define DRAW_MENU UI_ProcessMenu              // So that defined for legacy purposes
// Constants related to Button
typedef enum TButtonPressed
{
	BUTTON_NONE,                                // R  - Button inserted are executed
	BUTTON_LEFT,                                // W  - Insert left arrow button
	BUTTON_ENTER,                               // W  - Insert enter button
	BUTTON_RIGHT,                               // W  - Insert right arrow button
	BUTTON_EXIT                                 // W  - Insert exit button
} TButtonPressed;

// Constants related to BlueToothState
enum
{
	BT_STATE_VISIBLE            = 0x01,         // RW - BT visible
	BT_STATE_CONNECTED          = 0x02,         // RW - BT connected to something
	BT_STATE_OFF                = 0x04,         // RW - BT power off
	BT_ERROR_ATTENTION          = 0x08,         // W  - BT error attention
	BT_CONNECT_REQUEST          = 0x40,         // RW - BT get connect accept in progress
	BT_PIN_REQUEST              = 0x80          // RW - BT get pin code
};

typedef enum TUSBState
{
	USB_Disconnected = 0,
	USB_Connected    = 1,
	USB_Working      = 2,
} TUSBState;

#define   getBluetoothVisible()    (IOMapUi.BluetoothState & BT_STATE_VISIBLE)
#define   getBluetoothEnabled()    ((IOMapUi.BluetoothState & BT_STATE_OFF) == 0)
#define   getBluetoothDisabled()   ((IOMapUi.BluetoothState & BT_STATE_OFF) != 0)

typedef string tFileName;

typedef   struct IOMAPUI
{
	int             dontCare;                // W  - Pointer to menu definition. A don't care!!. Not Used
	UWORD           BatteryVoltage;          // R  - Battery voltage in millivolts
	tFileName       LMSfilename;             // W  - LMS filename to execute (Try It)
	UBYTE           Flags;                   // RW - Update command flags  (flags enumerated above)
	TGUIStates      State;                   // RW - UI state              (states enumerated above)
	TButtonPressed  Button;                  // RW - Insert button         (buttons enumerated above)
	bool            bRunState;               // W  - VM Run state          (0 = stopped, 1 = running)
	UBYTE           BatteryState;            // W  - Battery state         (0..4 capacity)
	UBYTE           BluetoothState;          // W  - Bluetooth state       (0=on, 1=visible, 2=conn, 3=conn.visible, 4=off, 5=dfu)
	TUSBState       UsbState;                // W  - Usb state             (0=disconnected, 1=connected, 2=working)
	UBYTE           SleepTimeout;            // RW - systemSleep timeout time    (min)
	UBYTE           SleepTimer;              // RW - systemSleep timer           (min)
	bool            Rechargeable;            // R  - Rechargeable battery  (0 = no, 1 = yes)
	UBYTE           Volume;                  // RW - Volume used in UI     (0 - 4)
	UBYTE           Error;                   // W  - Error code
	UBYTE           OBPPointer;              // W  - Actual OBP step       (0 - 4)
	bool            ForceOff;                // W  - Force off             (> 0 = off)
}IOMAPUI;

intrinsic IOMAPUI  propertyIndex(nUiOMap, parmSourceExternMemoryRef, kExternUiIOMAPAddress);

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                   I/O Map for  Bluetooth Tables
//
// The instrinsic variable 'nSensorIOMap' will provide complete access to the IOMap for sensors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////



typedef enum TBtDeviceStatus
{
	BT_DEVICE_EMPTY 			= (UBYTE) 0x00,
	BT_DEVICE_UNKNOWN 		= (UBYTE) 0x01,
	BT_DEVICE_KNOWN 			= (UBYTE) 0x02,
	BT_DEVICE_NAME				= (UBYTE) 0x40,
	BT_DEVICE_AWAY				= (UBYTE) 0x80,
	//BT_DEVICE_EMPTY     = 0                 | 0               | 0              | 0             ,
	//BT_DEVICE_UNKNOWN   = BT_DEVICE_UNKNOWN | 0               | 0              | 0             ,
	//BT_DEVICE_KNOWN     = 0                 | BT_DEVICE_KNOWN | 0              | 0             ,
	btUnknwnKnwn					= BT_DEVICE_UNKNOWN | BT_DEVICE_KNOWN | 0              | 0             ,
	//BT_DEVICE_NAME      = 0                 | 0               | BT_DEVICE_NAME | 0             ,
	btUnknwnName 					= BT_DEVICE_UNKNOWN | 0               | BT_DEVICE_NAME | 0             ,
	btKnwnName 						= 0                 | BT_DEVICE_KNOWN | BT_DEVICE_NAME | 0             ,
	btUnknwnKnwnName 			= BT_DEVICE_UNKNOWN | BT_DEVICE_KNOWN | BT_DEVICE_NAME | 0             ,
	//BT_DEVICE_AWAY      = 0                 | 0               | 0              | BT_DEVICE_AWAY,
	btUnknwnAway 					= BT_DEVICE_UNKNOWN | 0               | 0              | BT_DEVICE_AWAY,
	btKnwnAway 						= 0                 | BT_DEVICE_KNOWN | 0              | BT_DEVICE_AWAY,
	btUnknwnKnwnAway 			= BT_DEVICE_UNKNOWN | BT_DEVICE_KNOWN | 0              | BT_DEVICE_AWAY,
	btNameAway 						= 0                 | 0               | BT_DEVICE_NAME | BT_DEVICE_AWAY,
	btUnknwnNameAway 			= BT_DEVICE_UNKNOWN | 0               | BT_DEVICE_NAME | BT_DEVICE_AWAY,
	btKnwnNameAway 				= 0                 | BT_DEVICE_KNOWN | BT_DEVICE_NAME | BT_DEVICE_AWAY,
	btUnknwnKnwnNameAway 	= BT_DEVICE_UNKNOWN | BT_DEVICE_KNOWN | BT_DEVICE_NAME | BT_DEVICE_AWAY
} TBtDeviceStatus;

//
// Constants for a bit-map referring to BtStateStatus
//
typedef enum TBtStateStatus
{
	BT_OFF                  = 0x00,
	BT_BRICK_VISIBILITY     = 0x01,
	BT_BRICK_PORT_OPEN      = 0x02,
	BT_CONNECTION_0_ENABLE  = 0x10,   // When set, BT is connected on 'port' 0
	BT_CONNECTION_1_ENABLE  = 0x20,   // When set, BT is connected on 'port' 1
	BT_CONNECTION_2_ENABLE  = 0x40,   // When set, BT is connected on 'port' 2
	BT_CONNECTION_3_ENABLE  = 0x80,   // When set, BT is connected on 'port' 3
} TBtStateStatus;



typedef enum TBTHardwareStatus
{
	BT_ENABLE     = 0x00,
	BT_DISABLE    = 0x01
} TBTHardwareStatus;

#define   SIZE_OF_BT_NAME               16
#define   SIZE_OF_BRICK_NAME            8
#define   SIZE_OF_CLASS_OF_DEVICE       4
#define   SIZE_OF_BT_PINCODE            16
#define   SIZE_OF_BDADDR                7      // NOTE: real address is only six bytes. But extra character for NULL termination char
																							 //       But also note that address bytes can contain zeroes. So can't use standard
																							 //       'string' manipulation functions because they assum strings do not contain
																							 //       zeroes in the value bytes!

typedef UBYTE TFriendlyName[SIZE_OF_BT_NAME];
typedef UBYTE TBTAddress[SIZE_OF_BDADDR];
typedef UBYTE TClassOfDevice[SIZE_OF_CLASS_OF_DEVICE];
typedef UBYTE TPinCode[SIZE_OF_BT_PINCODE];


typedef   struct BDDEVICETABLE
{
	TFriendlyName     Name;
	TClassOfDevice    ClassOfDevice;
	TBTAddress        BdAddr;
	TBtDeviceStatus   DeviceStatus;
	UBYTE             Spare1;
	UBYTE             Spare2;
	UBYTE             Spare3;
} BDDEVICETABLE;

typedef   struct BDCONNECTTABLE
{
	TFriendlyName     NameX;
	TClassOfDevice    ClassOfDevice;
	TPinCode          PinCode;
	TBTAddress        BdAddr;
	UBYTE             HandleNr;
	bool              bStreamConnected;
	UBYTE             LinkQuality;
	UBYTE             Spare;
} BDCONNECTTABLE;

typedef BDDEVICETABLE  TContactTable[30];
typedef BDCONNECTTABLE TConnectTable[30];


typedef struct TBRICKDATA
{
	TFriendlyName     Name;
	UBYTE             BluecoreVersion[2];
	TBTAddress        BdAddr;
	TBtStateStatus    BtStateStatus;
	TBTHardwareStatus BtHwStatus;
	UBYTE             BluecoreTimeOutValue;
	UBYTE             Spare01;
	UBYTE             Spare02;
	UBYTE             Spare03;
} TBRICKDATA;

intrinsic TContactTable propertyIndex(BluetoothContactTable,		parmSourceExternMemoryRef, kExternBluetoothContactTableAddress);
intrinsic TConnectTable propertyIndex(BluetoothConnectionTable, parmSourceExternMemoryRef, kExternBluetoothConnectionTableAddress);
intrinsic TBRICKDATA    propertyIndex(BrickData,                parmSourceExternMemoryRef, kExternBrickData);


#endif
