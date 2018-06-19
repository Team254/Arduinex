#ifndef TNxtSynchMotors__H_
#define TNxtSynchMotors__H_

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                        File I/O Opcode Definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////


typedef enum TSynchedMotors
{
	//
	// First motor in 'name' is dominant; second is slave motor
	//
	synchNone   = 0,
	synchAB     = 1,
	synchAC     = 2,
	synchBA     = 3,
	synchBC     = 4,
	synchCA     = 5,
	synchCB     = 6
} TSynchedMotors;

#endif
