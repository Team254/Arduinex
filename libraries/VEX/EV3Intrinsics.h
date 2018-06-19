#pragma once
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//									ROBOTC Intrinsic Functions to Access Functions in LEGO's EV3 VM
//
// This file contains ROBOT intrinsic function declarations that allow access to capabilities
// of the LEGO developedEV3 firmware by the ROBOTC VM.
//
// Automatically Generated File on: 8/27/2014 at 11:22:10 PM
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ev3_native_bytecodes.h"



// Get name of program. Note there is no buffer overflow check on 'pProgramName'.
intrinsic void ProgramInfoGetPrgname(const short pgmSlotNumber, char *pProgramName)
                asm(byte(opcdEV3_LEGO), byte(opPROGRAM_INFO), byte(GET_PRGNAME), variable(pgmSlotNumber), variable(pProgramName));


// Get HW version string
intrinsic void GetHWVersion(const char nMaxLength, char *pVersionChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_HW_VERS), variable(nMaxLength), variable(pVersionChars));

// Get FW version string
intrinsic void GetFWVersion(const char nMaxLength, char *pVersionChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_FW_VERS), variable(nMaxLength), variable(pVersionChars));

// Get FW Build string
intrinsic void GetFWBuild(const char nMaxLength, char *pBuildChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_FW_BUILD), variable(nMaxLength), variable(pBuildChars));

// Get OS Build string
intrinsic void GetOSBuild(const char nMaxLength, char *pBuildChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_OS_BUILD), variable(nMaxLength), variable(pBuildChars));

// Get version string
intrinsic void GetVersion(const char nMaxLength, char *pVersionChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_VERSION), variable(nMaxLength), variable(pVersionChars));


// Wait for keypress
intrinsic void waitForButtonPress()
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(WAIT_FOR_PRESS));

// Flush unprocessed button messages
intrinsic void flushButtonMessages()
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(FLUSH));

// Generate button press
intrinsic void generateButtonPress(const char button)
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(PRESS), variable(button));

// Generate button release
intrinsic void generateButtonRelease(const char button)
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(RELEASE), variable(button));

// Write data to sensor via UART
intrinsic void sensorWriteUART(const char sensorPort, const char numbOfBytes, char *pBytes)
                asm(byte(opcdEV3_LEGO), byte(opINPUT_WRITE), variable(sensorPort), variable(numbOfBytes), variable(pBytes));

// Tests if new message is available
intrinsic void testForMailboxMessage(const char mailboxIndex, char &bBusy)
                asm(byte(opcdEV3_LEGO), byte(opMAILBOX_TEST), variable(mailboxIndex), variableRefRAM(bBusy));


// Wait for message to be available
intrinsic void waitForMailboxMessage(const char mailboxIndex)
                asm(byte(opcdEV3_LEGO), byte(opMAILBOX_READY), variable(mailboxIndex));
