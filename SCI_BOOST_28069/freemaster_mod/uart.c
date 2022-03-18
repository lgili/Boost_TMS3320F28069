/*
 * uart.c
 *
 *  Created on: 8 de set de 2020
 *      Author: lgili
 */
#include "DSP28x_Project.h"     // DSP28x Headerfile

// SCIA  8-bit word, baud rate 0x000F, default, 1 STOP bit, no parity
void scia_init()
{

    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function

    SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
    SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE

    SciaRegs.SCICTL2.bit.TXINTENA =1;
    SciaRegs.SCICTL2.bit.RXBKINTENA =1;

    SciaRegs.SCIHBAUD    =0x0000;  // 115200 baud @LSPCLK = 22.5MHz (90 MHz SYSCLK).
    SciaRegs.SCILBAUD    =0x0017;

    SciaRegs.SCICTL1.all =0x0023;  // Relinquish SCI from Reset

    //return;
}

void scib_init()
{

    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function

    ScibRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
    ScibRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE

    ScibRegs.SCICTL2.bit.TXINTENA =1;
    ScibRegs.SCICTL2.bit.RXBKINTENA =1;

    ScibRegs.SCIHBAUD    =0x0000;  // 115200 baud @LSPCLK = 22.5MHz (90 MHz SYSCLK).
    ScibRegs.SCILBAUD    =0x0017;

    ScibRegs.SCICTL1.all =0x0023;  // Relinquish SCI from Reset

    //return;
}

void scia_fifo_init()
{
    SciaRegs.SCIFFTX.all=0xE040;
    SciaRegs.SCIFFRX.all=0x204f;
    SciaRegs.SCIFFCT.all=0x0;

}

void scib_fifo_init()
{
    ScibRegs.SCIFFTX.all=0xE040;
    ScibRegs.SCIFFRX.all=0x204f;
    ScibRegs.SCIFFCT.all=0x0;

}

// Transmit a character from the SCI
void scia_xmit(int a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}
    SciaRegs.SCITXBUF=a;

}

void scib_xmit(int a)
{
    while (ScibRegs.SCIFFTX.bit.TXFFST != 0) {}
    ScibRegs.SCITXBUF=a;

}

void uart_tx_msg(char * msg,unsigned char length)
{
    int i;
    i = 0;
    for(i=0;i<length;i++)
    {
        scia_xmit(msg[i]);

    }
}

void uart_receive(unsigned char * msg)
{
    while(SciaRegs.SCIFFRX.bit.RXFFST == 0) { } // wait for empty state
    *msg = SciaRegs.SCIRXBUF.all;
}


