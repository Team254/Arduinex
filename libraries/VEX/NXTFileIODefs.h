#ifndef TFileIODefs__H_
#define TFileIODefs__H_


///////////////////////////////////////////////////////////////////////////////////////////////
//
//                                     NXT Buttons
//
///////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TNxtButtons
{
	#define kNoButton (-1)   // Don't want to put in enum because enum size will change from 8-bits to 16/32-bits
	kExitButton    = 0,      //  BTN1
	kRightButton   = 1,      //  BTN2
	kLeftButton    = 2,      //  BTN3
	kEnterButton   = 3       //  BTN4
} TNxtButtons;  // NXT Only

#define TButtons TNxtButtons  // For legacy support

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                        File I/O Opcode Definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////

//
// File I/O Command Types
//
typedef enum TFileIOCommands
{
	//
	// Do not change the order of these enums!!!
	//
	ioFindFirstFile           = 0,  // Start file iteration
	ioFindNextFile            = 1,  // Next file iteration

	ioOpenReadVariableFN      = 2,  // open   file read  (Variable string for filename)
	ioOpenWriteVariableFN     = 3,  // open   file write (Variable string for filename)
	ioClose                   = 4,  // close  file
	ioDelete                  = 5,  // delete file

	ioReadByte                = 6,  // read   single byte
	ioReadShort               = 7,  // read   16-bit short
	ioReadLong                = 8,  // read   32-bit long
	ioReadFloat               = 9,  // read   32-bit float
	ioReadString              = 10, // read   string
	ioReadVariableLength      = 11, // Future

	ioWriteByte               = 12, // write  single byte
	ioWriteShort              = 13, // write  16-bit short
	ioWriteLong               = 14, // write  32-bit long
	ioWriteFloat              = 15, // write  32-bit float
	ioWriteStringConst        = 16, // write  string constant -- allows arbitrary length strings
	ioWriteStringVar          = 17, // write  string variable -- limited to "strings" of 20 bytes
	ioWriteText               = 18, // write  string variable as text -- no trailing nll terminator
	ioWriteVariableLength     = 19, // Future

	ioRename                  = 20, // Rename file
	ioCloseAllFileHandles     = 21, // Force close all open file handles

} TFileIOCommands;


//
// File System Error Codes
//

//
// Detailed Error codes from the "loader" (File System) and "Bluetooth Messaging" System
//
// For file system commands the file handle is "OR-ed" into the lower byte.
//
typedef enum TLoaderErrors
{
	SUCCESS             = (unsigned short) 0x000000,
	INPROGRESS          = (unsigned short) 0x000001,   // If these two in upper byte, we could use a 'byte' instead of 'word' variable
	//REQPIN              = (unsigned short) 0x000002,   // If these two in upper byte, we could use a 'byte' instead of 'word' variable
	//
	// Values >= (unsigned short) 0x008000 are errors. Values < 0x8000 are warnings
	//
	NOMOREHANDLES       = (unsigned short) 0x008100,
	NOSPACE             = (unsigned short) 0x008200,
	NOMOREFILES         = (unsigned short) 0x008300,
	EOFEXSPECTED        = (unsigned short) 0x008400,
	ENDOFFILE           = (unsigned short) 0x008500,
	NOTLINEARFILE       = (unsigned short) 0x008600,
	FILENOTFOUND        = (unsigned short) 0x008700,
	HANDLEALREADYCLOSED = (unsigned short) 0x008800,
	NOLINEARSPACE       = (unsigned short) 0x008900,
	UNDEFINEDERROR      = (unsigned short) 0x008A00,
	FILEISBUSY          = (unsigned short) 0x008B00,
	NOWRITEBUFFERS      = (unsigned short) 0x008C00,
	APPENDNOTPOSSIBLE   = (unsigned short) 0x008D00,
	FILEISFULL          = (unsigned short) 0x008E00,
	FILEEXISTS          = (unsigned short) 0x008F00,
	MODULENOTFOUND      = (unsigned short) 0x009000,
	OUTOFBOUNDERY       = (unsigned short) 0x009100,
	ILLEGALFILENAME     = (unsigned short) 0x009200,
	ILLEGALHANDLE       = (unsigned short) 0x009300,
	BTBUSY              = (unsigned short) 0x009400,
	BTCONNECTFAIL       = (unsigned short) 0x009500,
	BTTIMEOUT           = (unsigned short) 0x009600,
	FILETX_TIMEOUT      = (unsigned short) 0x009700,
	FILETX_DSTEXISTS    = (unsigned short) 0x009800,
	FILETX_SRCMISSING   = (unsigned short) 0x009900,
	FILETX_STREAMERROR  = (unsigned short) 0x009A00,
	FILETX_CLOSEERROR   = (unsigned short) 0x009B00
} TLoaderErrors;

#define   NOT_A_HANDLE                  ((TLoaderErrors) 0x00FF)


#define   IS_LOADER_ERR(LStatus)        (((LStatus) & 0x8000) != 0)

typedef enum NXT_STATUS
{
	NO_ERR                   =  0,
	STAT_MSG_EMPTY_MAILBOX   = 64,  //Specified mailbox contains no new messages
	STAT_COMM_PENDING        = 32,  //Pending setup operation in progress
	ERR_ARG                  = -1,  //0xFF Bad arguments
	ERR_INSTR                = -2,  //0xFE Illegal bytecode instruction
	ERR_FILE                 = -3,  //0xFD Malformed file contents
	ERR_VER                  = -4,  //0xFC Version mismatch between firmware and compiler
	ERR_MEM                  = -5,  //0xFB Insufficient memory available
	ERR_BAD_PTR              = -6,  //0xFA Someone passed us a bad pointer!
	ERR_WrongIDE             = -7,  //0xF9 Dick's add -- Program type not "RobotC" or "Robolab"

	//General errors

	//ERR_INVALID_PORT        = -16,  //0xF0 Bad input or output port specified
	//ERR_INVALID_FIELD       = -17,  //0xEF Attempted to access invalid field of a structure
	//ERR_INVALID_QUEUE       = -18,  //0xEE Illegal queue ID specified
	//ERR_INVALID_SIZE        = -19,  //0xED Illegal size specified

	ERR_NO_PROG             = -20,  //0xEC No active program

	//Communications specific errors

	//ERR_COMM_CHAN_NOT_READY = -32,  //0xE0 Specified channel/connection not configured or busy
	//ERR_COMM_CHAN_INVALID   = -33,  //0xDF Specified channel/connection is not valid
	//ERR_COMM_BUFFER_FULL    = -34,  //0xDE No room in comm buffer
	//ERR_COMM_BUS_ERR        = -35,  //0xDD Something went wrong on the communications bus

//Remote control ("direct commands") errors

	ERR_RC_ILLEGAL_VAL      = -64,  //0xC0 Data contains out-of-range values
	ERR_RC_BAD_PACKET       = -65,  //0xBF Clearly insane packet
	ERR_RC_UNKNOWN_CMD      = -66,  //0xBE Unknown command opcode
	ERR_RC_FAILED           = -67,  //0xBD Request failed (i.e. specified file not found)
} NXT_STATUS;

typedef enum TFileIOResult // NOTE the "ioRsltForceTo16Bits" entry -- ROBOTC compiler will assign enum to 16-bit value!!!
{
	ioRsltSuccess             = (0x00FF & (SUCCESS             >> 8)),
	ioRsltInProgress          = (0x00FF & (0x01)),
	ioRsltReqPIN              = (0x00FF & (0x02)),
	ioRsltNoMoreHandles       = (0x00FF & (NOMOREHANDLES       >> 8)),
	ioRsltNoSpace             = (0x00FF & (NOSPACE             >> 8)),
	ioRsltNoMoreFiles         = (0x00FF & (NOMOREFILES         >> 8)),
	ioRsltEofExpected         = (0x00FF & (EOFEXSPECTED        >> 8)),
	ioRsltEndOfFile           = (0x00FF & (ENDOFFILE           >> 8)),
	ioRsltNotLinearFile       = (0x00FF & (NOTLINEARFILE       >> 8)),
	ioRsltFileNotFound        = (0x00FF & (FILENOTFOUND        >> 8)),
	ioRsltHandleAlreadyClosed = (0x00FF & (HANDLEALREADYCLOSED >> 8)),
	ioRsltNoLinearSpace       = (0x00FF & (NOLINEARSPACE       >> 8)),
	ioRsltUndefinedError      = (0x00FF & (UNDEFINEDERROR      >> 8)),
	ioRsltFileIsBusy          = (0x00FF & (FILEISBUSY          >> 8)),
	ioRsltNoWriteBuffers      = (0x00FF & (NOWRITEBUFFERS      >> 8)),
	ioRsltAppendNotPossible   = (0x00FF & (APPENDNOTPOSSIBLE   >> 8)),
	ioRsltFileIsFull          = (0x00FF & (FILEISFULL          >> 8)),
	ioRsltFileExists          = (0x00FF & (FILEEXISTS          >> 8)),
	ioRsltModuleNotFound      = (0x00FF & (MODULENOTFOUND      >> 8)),
	ioRsltOutOfBoundery       = (0x00FF & (OUTOFBOUNDERY       >> 8)),
	ioRsltIllegalFilename     = (0x00FF & (ILLEGALFILENAME     >> 8)),
	ioRsltIllegalHandle       = (0x00FF & (ILLEGALHANDLE       >> 8)),
	ioRsltBTBusy              = (0x00FF & (BTBUSY              >> 8)),
	ioRsltBTConnectFail       = (0x00FF & (BTCONNECTFAIL       >> 8)),
	ioRsltBTTimeout           = (0x00FF & (BTTIMEOUT           >> 8)),
	ioRsltFileTxTimeout       = (0x00FF & (FILETX_TIMEOUT      >> 8)),
	ioRsltFileTxDSTExists     = (0x00FF & (FILETX_DSTEXISTS    >> 8)),
	ioRsltFileTxSRCMissing    = (0x00FF & (FILETX_SRCMISSING   >> 8)),
	ioRsltFileTxStreamError   = (0x00FF & (FILETX_STREAMERROR  >> 8)),
	ioRsltFileTxCloseError    = (0x00FF & (FILETX_CLOSEERROR   >> 8)),


	ioRsltCommChannelBusError = (0x00FF & -35),  //0xDD Something went wrong on the communications bus
	ioRsltCommBufferFull      = (0x00FF & -34),  //0xDE No room in comm buffer
	ioRsltCommChannelBad      = (0x00FF & -33),  //0xDF Specified channel/connection is not valid
	ioRsltCommChannelNotReady = (0x00FF & -32),  //0xE0 Specified channel/connection not configured or busy
	//#define ERR_COMM_BUS_ERR        ((short) ioRsltCommChannelBusError)
	#define ERR_COMM_BUFFER_FULL    ((short) ioRsltCommBufferFull)
	ERR_COMM_CHAN_INVALIDX   	= ((short) ioRsltCommChannelBad),
	//#define ERR_COMM_CHAN_NOT_READY ((short) ioRsltCommChannelNotReady)

	//General errors

	ERR_INVALID_PORT          = (0x00FF & -16),  //0xF0 Bad input or output port specified
	ERR_INVALID_FIELD         = (0x00FF & -17),  //0xEF Attempted to access invalid field of a structure
	ERR_INVALID_QUEUE         = (0x00FF & -18),  //0xEE Illegal queue ID specified
	ERR_INVALID_SIZE          = (0x00FF & -19),  //0xED Illegal size specified

	ioRsltCommPending         = (0x00FF & STAT_COMM_PENDING),       //0x20
	ioRsltEmptyMailbox        = (0x00FF & STAT_MSG_EMPTY_MAILBOX),  //0x40

	ioRsltBadArgs             = (0x00FF & ERR_ARG),                 //0xFF

	ioRsltForceTo16Bits				= 0x1234,															// Value larger than 0xff to forece enum to take 16-bit size.
} TFileIOResult;

typedef enum TMessageOps
{
	//
	// Do not shift these constants.
	//
	msgOpSizeForQueue 						=  0,

	msgOpBluetoothStatus					=  1,

	msgOpMessageWriteNoPort 			=  2,
	msgOpMessageWriteToPort 			=  3,
	msgOpBluetoothWriteRawNoPort	=  4,
	msgOpBluetoothWriteRawToPort	=  5,

	msgOpMessageReadFromQueue 		=  6,
	msgOpBluetoothReadRaw         =  7,

	msgOpPurgeReadBuffer					=  8,

	msgOpMessageAddQueue					=  9,

	msgOpHSBaudRate               = 10,  // Set   High Speed Link Baud Rate
	msgOpHSReadAvailBytes         = 11,  // Get   High Speed Available Read Bytes
	msgOpHSRead                   = 12,  // Read  High Speed Link
	msgOpHSWrite                  = 13,  // Write High Speed Link
	msgOpHSWriteSingleChar				= 14,  // Write High Speed Link single char



} TMessageOps;


///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Enum for High Speed Link
//
///////////////////////////////////////////////////////////////////////////////////////////////


typedef enum THighSpeedState
{
	HS_Unassigned       = 0,
	HS_INITIALISE       = 1,
	HS_INIT_RECEIVER    = 2,
	HS_SEND_DATA        = 3,
	HS_DISABLE          = 4,
	HS_SENDING          = 5, // Dick's add
	HS_RECEIVING        = 6, // Dick's add
} THighSpeedState;


typedef enum THiSpeed_Mode
{
	hsInactive        = 0,
	hsRawMode         = 1,
	hsMsgModeMaster   = 2,
	hsMsgModeSlave    = 3
} THiSpeed_Mode;

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Enum for Status Icons
//
///////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TStatusTypeIcons                         // Index in status icon collection file
{
	STATUS_NO_RUNNING_0       = 0,
	STATUS_NO_RUNNING_1,
	STATUS_NO_RUNNING_2,
	STATUS_NO_RUNNING_3,
	STATUS_NO_RUNNING_4,
	STATUS_NO_RUNNING_5,
	STATUS_NO_RUNNING_6,
	STATUS_NO_RUNNING_7,
	STATUS_NO_RUNNING_8,
	STATUS_NO_RUNNING_9,
	STATUS_NO_RUNNING_10,
	STATUS_NO_RUNNING_11,

	STATUS_BATTERY_Discharged,
	STATUS_BATTERY_1,
	STATUS_BATTERY_2,
	STATUS_BATTERY_3,
	STATUS_BATTERY_Charged,
	STATUS_BATTERY_Blank,

															 //BT_STATE_VISIBLE            = 0x01,         // RW - BT visible
															 //BT_STATE_CONNECTED          = 0x02,         // RW - BT connected to something
															 //BT_STATE_OFF                = 0x04,         // RW - BT power off
	STATUS_NO_BLUETOOTH_On,                           // ~BT_STATE_VISIBLE  ~BT_STATE_CONNECTED  ~BT_STATE_OFF  <== On
	STATUS_NO_BLUETOOTH_OnVisible,                    //  BT_STATE_VISIBLE  ~BT_STATE_CONNECTED  ~BT_STATE_OFF  <== On + Visible
	STATUS_NO_BLUETOOTH_OnConnected,                  // ~BT_STATE_VISIBLE   BT_STATE_CONNECTED  ~BT_STATE_OFF  <== On            + Connected
	STATUS_NO_BLUETOOTH_OnVisibleConnected,           //  BT_STATE_VISIBLE   BT_STATE_CONNECTED  ~BT_STATE_OFF  <== On + Visible  + Connected
	STATUS_NO_BLUETOOTH_Off,                          // ~BT_STATE_VISIBLE  ~BT_STATE_CONNECTED   BT_STATE_OFF  <== Off
	STATUS_NO_BLUETOOTH_DFU,                          //  Download mode?

	STATUS_NO_USB_Disconnected,                       // Disconnected
	STATUS_NO_USB_Connected,                          // Connected
	STATUS_NO_USB_Working,                            // Working

	STATUS_BATTERY_Small_Discharged,
	STATUS_BATTERY_Small_1,
	STATUS_BATTERY_Small_2,
	STATUS_BATTERY_Small_3,
	STATUS_BATTERY_Small_Charged,
	STATUS_BATTERY_Small_Blank,

} TStatusTypeIcons;


///////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Enum for Internal Text Error Strings
//
///////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TTypeTextStrings                         // String index in text string file
{
	TXT_GENERAL_EMPTY,
																						// BlueTooth connect
	TXT_FB_BT_CONNECTING_WAIT,                // "Connecting"
	TXT_FB_BT_CONNECT_BUSY_FAIL1,             // "Line busy OR"
	TXT_FB_BT_CONNECT_BUSY_FAIL2,             // "Not found"

																						// BlueTooth send file
	TXT_FB_BT_SENDING_NO_CONN_FAIL,           // "Connection?"
	TXT_FB_BT_SENDING_WAIT,                   // "Sending file"

																						// BlueTooth Commands
	TXT_FB_BT_TURNING_ON_WAIT,                // "Turning on"
	TXT_FB_BT_TURNING_OFF_WAIT,               // "Turning off"
	TXT_FB_BT_SEARCHING_WAIT,                 // "Searching"

	TXT_FB_BT_CommandFailed,                  // "Failed!"
	TXT_FB_BT_CommandAborted,                 // "Aborted!"

																						// On Brick Programming
	TXT_FB_OBP_MEMORY_FULL_FAIL,              // "Memory full!"
	TXT_FB_OBP_FILE_SAVED_INFO,               // "File saved"
	TXT_FB_OBP_FILE_EXIST_FAIL,               // "File exist"
	TXT_FB_OBP_OVERWRITE_FAIL,                // "overwrite!"

																						// File delete
	TXT_FB_FD_FILE_DELETED_INFO,              // "File deleted"

																						// Files delete
	TXT_FB_FD_FILES_INFO,                     // "Files"
	TXT_FB_FD_DELETED_INFO,                   // "deleted"

																						// File run
	TXT_FILERUN_RUNNING,                      // "Running"
	TXT_FILERUN_ABORTED,                      // "Aborted!"
	TXT_FILERUN_DONE,                         // "Done"
	TXT_FILERUN_FILE_ERROR,                   // "File error!"
	TXT_Unused,																//
	TXT_FILERUN_FILE_VersionERROR,            // "Bad Version!"
	TXT_FILERUN_FILE_WrongIDEERROR,           // "File IDE Bad!"

																						// Files delete
	TXT_FILESDELETE_DELETING_ALL,             // "Deleting all"
	TXT_FILESDELETE_S_FILES,                  // "%s files!"

																						// File types
	TXT_FILETYPE_SOUND,                       // "Sound"
	TXT_FILETYPE_LMS,                         // "Software"
	TXT_FILETYPE_NXT,                         // "NXT"
	TXT_FILETYPE_TRY_ME,                      // "Try Me"
	TXT_FILETYPE_DATA,                        // "Datalog"

																						// Get user string
	TXT_GETUSERSTRING_PIN,                    // "Pin:"
	TXT_GETUSERSTRING_FILENAME,               // "Filename:"

																						// On Brick Programming
	TXT_ONBRICKPROGRAMMING_PLEASE_USE_PORT,   // "Please use port:"
	TXT_ONBRICKPROGRAMMING_1_TOUCH_SENSOR,    // "1 - Touch sensor"
	TXT_ONBRICKPROGRAMMING_2_SOUND_SENSOR,    // "2 - Sound sensor"
	TXT_ONBRICKPROGRAMMING_3_LIGHT_SENSOR,    // "3 - Light sensor"
	TXT_ONBRICKPROGRAMMING_4_ULTRA_SONIC,     // "4 - Ultra sonic"
	TXT_ONBRICKPROGRAMMING_BC_LR_MOTORS,      // "B/C - L/R motors"

																						// View
	TXT_VIEW_SELECT,                          // "Select"

																						// BlueTooth device list
	TXT_BTDEVICELIST_SELECT,                  // "Select"

																						// BlueTooth connection list
	TXT_BTCONNECTLIST_SELECT,                 // "Select"

																						// Bluetooth list errors
	TXT_FB_BT_ERROR_LR_COULD_NOT_SAVE_1,      // BT save data error!
	TXT_FB_BT_ERROR_LR_COULD_NOT_SAVE_2,      //
	TXT_FB_BT_ERROR_LR_STORE_IS_FULL_1,       // BT store is full error!
	TXT_FB_BT_ERROR_LR_STORE_IS_FULL_2,       //
	TXT_FB_BT_ERROR_LR_UNKOWN_ADDR_1,         // BT unknown addr. error!
	TXT_FB_BT_ERROR_LR_UNKOWN_ADDR_2,         //

																						// Power of time
	TXT_POWEROFFTIME_NEVER,                   // "Never"
	TXT_FILETYPE_TEMP,                        // "Temp"
	TXT_FILETYPE_TEXT,                        // "Text"
	TXT_FILETYPE_CSV,                         // "CSV"
	TXT_FILETYPE_ICON,                        // "Icon" (filetype)

	TXT_FB_BT_SEARCH_NO_ITEMS_FOUND,          // "No items found"
	TXT_FB_BT_RESET,                          // "Reset Bluetooth"
	TXT_FB_BT_InvalidDevice,                  // "Invalid Device!"
	TXT_FB_BT_InvalidSlot,                    // "Invalid Slot!"

	kNumbOfUIStrings
} TTypeTextStrings;


#endif
