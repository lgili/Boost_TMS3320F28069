/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

                                INEP-UFSC
___________________________________________________________________________
                |
-        PROJETO: BOODT
-        ARQUIVO: 2_ADC.c
________________|__________________________________________________________
                |
-           DATA: 07/08/2020
-    ATUALIZA��O:
-         VERS�O: 1.0
________________|__________________________________________________________
                |
-      AUTOR: LUIZ CARLOS GILI
_______________ |__________________________________________________________
                |
-    OBSERVA��ES:
_______________ |__________________________________________________________
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

//-- Includes -------------------------------------------------------------
#include "F2806x_Device.h"
//#include "Defines.h"

void GPIO (void)
{
	EALLOW;

	//-- GPIO34 LED BLINK---------------------------------------------------------------
	GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;	// Fun��o -> GPIO34
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;		// Dire��o -> Sa�da

	// -- GPIO0 --> ePWM1A
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;	//Desativa Pull Up
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; //EPWM1A -> GPIO0
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  //Define GPIO como sa�da
    // -- GPIO2 --> ePWM2A
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;	//Desativa Pull Up
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0; //EPWM1A -> GPIO0
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;  //Define GPIO como sa�da
    // -- GPIO4 --> ePWM3A
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;	//Desativa Pull Up
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1; //EPWM1A -> GPIO0
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;  //Define GPIO como sa�da
    // -- GPIO6 --> ePWM4A
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;	//Desativa Pull Up
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1; //EPWM1A -> GPIO0
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;  //Define GPIO como sa�da

	EDIS;
}
