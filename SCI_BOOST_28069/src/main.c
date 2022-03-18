//###########################################################################
//
// FILE:   Example_2806xScia_Echoback.c
//
// TITLE:  SCI Echo Back Example
//
//!  \addtogroup f2806x_example_list
//!  <h1>SCI Echo Back(sci_echoback)</h1>
//!
//!  This test receives and echo-backs data through the SCI-A port.
//!
//!  The PC application 'hypterterminal' can be used to view the data
//!  from the SCI and to send information to the SCI.  Characters received
//!  by the SCI port are sent back to the host.
//!
//!  \b Running \b the \b Application
//!  -# Configure hyperterminal:
//!  Use the included hyperterminal configuration file SCI_96.ht.
//!  To load this configuration in hyperterminal
//!    -# Open hyperterminal
//!    -# Go to file->open
//!    -# Browse to the location of the project and
//!       select the SCI_96.ht file.
//!  -# Check the COM port.
//!  The configuration file is currently setup for COM1.
//!  If this is not correct, disconnect (Call->Disconnect)
//!  Open the File-Properties dialog and select the correct COM port.
//!  -# Connect hyperterminal Call->Call
//!  and then start the 2806x SCI echoback program execution.
//!  -# The program will print out a greeting and then ask you to
//!  enter a character which it will echo back to hyperterminal.
//!
//!  \note If you are unable to open the .ht file, you can create
//!  a new one with the following settings
//!  -  Find correct COM port
//!  -  Bits per second = 9600
//!  -  Date Bits = 8
//!  -  Parity = None
//!  -  Stop Bits = 1
//!  -  Hardware Control = None
//!
//!  \b Watch \b Variables \n
//!  - \b LoopCount, for the number of characters sent
//!  - ErrorCount
//!
//! \b External \b Connections \n
//!  Connect the SCI-A port to a PC via a transceiver and cable.
//!  - GPIO28 is SCI_A-RXD (Connect to Pin3, PC-TX, of serial DB9 cable)
//!  - GPIO29 is SCI_A-TXD (Connect to Pin2, PC-RX, of serial DB9 cable)
//
//###########################################################################
// $TI Release: F2806x Support Library v2.05.00.00 $
// $Release Date: Tue May 26 17:12:03 IST 2020 $
// $Copyright:
// Copyright (C) 2009-2020 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
//#include "freemaster.h"
#include "uart.h"
//
// Function Prototypes
// Used for running BackGround in flash, and ISR in RAM
//extern Uint16 RamfuncsLoadStart, RamfuncsLoadEnd, RamfuncsRunStart,RamfuncsLoadSize;
void InitFlash(void);
void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);
//
// Globals
//
Uint16 LoopCount;
Uint16 ErrorCount;

#define DELAY 1000000L

static float valor_novo=10;
static float doidura= 0.5;
unsigned char xx;
unsigned long ui32Base11 = 0x00007050;   // SCI-A
Uint16 ReceivedChar = 0;
//

//
// These are defined by the linker (see F2808.cmd)
//
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadSize;

//#pragma CODE_SECTION(InitFlash, "ramfuncs");
// Main
//
void main(void)
{

    unsigned char *msg;


    //
    // Step 1. Initialize System Control:
    // PLL, WatchDog, enable Peripheral Clocks
    // This example function is found in the F2806x_SysCtrl.c file.
    //
    InitSysCtrl();

    //
    // Step 2. Initalize GPIO:
    // This example function is found in the F2806x_Gpio.c file and
    // illustrates how to set the GPIO to its default state.
    //
    //InitGpio(); Skipped for this example

    //
    // For this example, only init the pins for the SCI-A port.
    // This function is found in the F2806x_Sci.c file.
    //
    //InitSciaGpio();
    InitScibGpio();
    //
    // Step 3. Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    //
    DINT;

    //
    // Initialize PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags
    // are cleared.
    // This function is found in the F2806x_PieCtrl.c file.
    //
    InitPieCtrl();

    //
    // Disable CPU interrupts and clear all CPU interrupt flags
    //
    IER = 0x0000;
    IFR = 0x0000;

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    // This will populate the entire table, even if the interrupt
    // is not used in this example.  This is useful for debug purposes.
    // The shell ISR routines are found in F2806x_DefaultIsr.c.
    // This function is found in F2806x_PieVect.c.
    //
    InitPieVectTable();

//#ifdef FLASH
    //memcpy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
    //MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsLoadSize);
    //
        // Call Flash Initialization to setup flash waitstates
        // This function must reside in RAM
        //
        //InitFlash();
    //MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
        //memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

    // Call Flash Initialization to setup flash waitstates
    // This function must reside in RAM
    //InitFlash();
//#endif
    //
    // Step 4. Initialize all the Device Peripherals:
    // This function is found in F2806x_InitPeripherals.c
    //
    //InitPeripherals(); // Not required for this example
    //=================================
    //  INITIALISATION - Peripherals
    //=================================

    GPIO();
    ADC();
    PWM();
    ISR ();
    //
    // Step 5. User specific code
    //
    LoopCount = 0;
    ErrorCount = 0;

    scib_fifo_init();      // Initialize the SCI FIFO
    scib_init();  // Initalize SCI for echoback

    /*msg = "\r\n\n\nHello World!\0";
    scia_msg(msg);

    msg = "\r\nYou will enter a character, and the DSP will echo it back! \n\0";
    scia_msg(msg);*/
    //FMSTR_Init();

    for(;;)
    {
        //valor_novo=valor_novo+1;
        //if(valor_novo >=1000) valor_novo=0;

        GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
        GpioDataRegs.GPBTOGGLE.bit.GPIO39 = 1;
        //uart_receive(&msg);
        //scia_xmit(msg);


        //ReceivedChar = UARTCharGet(ui32Base11);
        //UARTCharPutNonBlocking(ui32Base11, ReceivedChar);
        //while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}
        //SciaRegs.SCITXBUF =msg ;
        //FMSTR_Poll();
        /*msg = "\r\nEnter a character: \0";
        scia_msg(msg);*/

        //
        // Wait for inc character
        //
        while(ScibRegs.SCIFFRX.bit.RXFFST !=1)
        {
            //
            // wait for XRDY =1 for empty state
            //
        }

        //
        // Get character
        //
       //
        // Echo character back
        //
        //msg = "  You sent: \0";
        //scia_msg(msg);
        //ReceivedChar = 24;
        ReceivedChar = ScibRegs.SCIRXBUF.all;
        scib_xmit(ReceivedChar);

        /*LoopCount++;*/
        //DELAY_US(DELAY);
    }
}

//
// scia_echoback_init - Test 1,SCIA  DLB, 8-bit word, baud rate 0x0103,
// default, 1 STOP bit, no parity
//



/*
//
// scia_xmit - Transmit a character from the SCI
//
void
scia_xmit(int a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0)
    {

    }
    SciaRegs.SCITXBUF=a;
}

//
// scia_msg -
//
void
scia_msg(char * msg)
{
    int i;
    i = 0;
    while(msg[i] != '\0')
    {
        scia_xmit(msg[i]);
        i++;
    }
}*/

//
// scia_fifo_init - Initalize the SCI FIFO
//
/*
void
scia_fifo_init()
{
    SciaRegs.SCIFFTX.all=0xE040;
    SciaRegs.SCIFFRX.all=0x2044;
    SciaRegs.SCIFFCT.all=0x0;
}
*/
//
// End of File
//

