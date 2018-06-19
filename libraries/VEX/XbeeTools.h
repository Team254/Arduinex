#pragma systemFile
/*
Developed by T.Friez
Last Updated: 3/9/2015 5:00pm EST
Version #: 1.03
For use with Digi Xbee Radios
*/

/////////////////////////
// Initalization Routines
/////////////////////////
#if defined(NXT)
void initRS485(long nBaudRate = 9600)
{
  nxtEnableHSPort();            //Enable High Speed Port #4
  nxtSetHSBaudRate(nBaudRate);  //Xbee Default Speed
  nxtHS_Mode = hsRawMode;       //Set to Raw Mode (vs. Master/Slave Mode)
}
#elif defined(VEX2)
void initRS232(TUARTs tSelectedUART = UART1, TBaudRate tSelectBaud = baudRate9600)
{
  configureSerialPort(tSelectedUART, uartUserControl);
  setBaudRate(tSelectedUART, tSelectBaud);
}
#endif

/////////////////////////
// Sending a String
/////////////////////////
#if defined(NXT)
void sendString(const char* sOutgoing)
{
	for(int i = 0; i < strlen(sOutgoing); i++)
	{
		nxtWriteCharRawHS(sOutgoing[i]);
		wait1Msec(2);
	}
}
#elif defined(VEX2)

void sendString(const char* sOutgoing, TUARTs tSelectedUART = UART1)
{
	for(int i = 0; i < strlen(sOutgoing); i++)
	{
		sendChar(tSelectedUART, sOutgoing[i]);
		while(!bXmitComplete(tSelectedUART)) continue;
	}
}

#endif

/////////////////////////
// Receiving a String
/////////////////////////
#if defined(NXT)
void receiveString(const char* cProcessing, bool bClearBuffer = true, short nTimeoutInMS = -1)
{
	ubyte cIncomingChar;
	int nCounter = 0;

	memset(cProcessing, 0, sizeof(cProcessing));

	if(bClearBuffer)
	{
		while(nxtGetAvailHSBytes())
		{
			nxtReadRawHS(&cIncomingChar, 1);
			noOp();
		}
	}

	clearTimer(T4);

	while(!nxtGetAvailHSBytes())
	{
		if((time1[T4] > nTimeoutInMS) && (nTimeoutInMS != -1))
			return;
		noOp();
	}

	wait1Msec(1);

	while(nxtGetAvailHSBytes() && nCounter < (maxSize))
	{
		nxtReadRawHS(&cIncomingChar, 1);
		cProcessing[nCounter] = cIncomingChar;
		nCounter++;
		wait1Msec(1);
	}
}

#elif defined(VEX2)
void receiveString(const char *cProcessing, const short nSizeOfBuffer, TUARTs tSelectedUART = UART1, bool bClearBuffer = true, short nTimeoutInMS = -1)
{
	short incomingChar = -1;
	long 	nStartTime = 0;
	long 	nCurrentTime = 0;
	short nCounter = 0;

	//Clean up any old data.
	memset(cProcessing, 0, nSizeOfBuffer);

	//Clear the existing serial buffer (if requested)
	while(incomingChar != -1 && bClearBuffer)	
		incomingChar = getChar(tSelectedUART);

	nStartTime = nPgmTime;
	
	while(incomingChar == -1)
	{
		if((nStartTime > (nStartTime+nTimeoutInMS)) && (nTimeoutInMS != -1))
			return;

		incomingChar = getChar(tSelectedUART);
		sleep(1);
	}

	cProcessing[nCounter] = incomingChar;
	sleep(1);

	while((incomingChar != -1) && (nCounter < nSizeOfBuffer))
	{
		incomingChar = getChar(tSelectedUART);
		nCounter++;
		if(incomingChar != -1)
		{
			cProcessing[nCounter] = incomingChar;
			sleep(1);
		}
		else
			return;
	}
}
#endif