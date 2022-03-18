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
#include "F2806x_Adc.h"                // ADC Registers
#include "F2806x_Examples.h"
//#include "Geral.h"

//-- Vari�veis ------------------------------------------------------------
#define ADC_usDELAY  1000L

void ADC(void)
{
///// Init ADC /////
extern void DSP28x_usDelay(Uint32 Count);

EALLOW;
SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
(*Device_cal)();
EDIS;

   EALLOW;
   AdcRegs.ADCCTL1.bit.ADCBGPWD  = 1;      // Power ADC BG
   AdcRegs.ADCCTL1.bit.ADCREFPWD = 1;      // Power reference
   AdcRegs.ADCCTL1.bit.ADCPWDN   = 1;      // Power ADC
   AdcRegs.ADCCTL1.bit.ADCENABLE = 1;      // Enable ADC
   AdcRegs.ADCCTL1.bit.ADCREFSEL = 0;      // Select interal BG
   EDIS;

   //DELAY_US(1000L);         // Delay before converting ADC channels

   EALLOW;
AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1;
EDIS;

//DELAY_US(1000L);         // Delay before converting ADC channels

//// Config. ADC ////
EALLOW;
AdcRegs.ADCCTL1.bit.ADCENABLE = 1; // Enable ADC
AdcRegs.ADCCTL1.bit.ADCBGPWD = 1; // Enable ADC
AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 1; // Enable non-overlap mode
AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1; // ADCINT1 trips after AdcResults latch
AdcRegs.INTSEL1N2.bit.INT1E     = 1; // Enabled ADCINT1
AdcRegs.INTSEL1N2.bit.INT1CONT  = 0; // Disable ADCINT1 Continuous mode
AdcRegs.INTSEL1N2.bit.INT1SEL = 0;    // Setup EOC1 to trigger ADCINT1 to fire

AdcRegs.ADCSOC0CTL.bit.CHSEL = 0x2;    // set SOC0 channel select to ADCINA2
AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 5;    // set SOC0 start trigger on EPWM1A, due to round-robin SOC0 converts first then SOC1
AdcRegs.ADCSOC0CTL.bit.ACQPS = 6; // set SOC0 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)

AdcRegs.ADCSOC2CTL.bit.CHSEL = 0xA;    // set SOC1 channel select to ADCINB2
AdcRegs.ADCSOC2CTL.bit.TRIGSEL = 5;    // set SOC1 start trigger on EPWM1A, due to round-robin SOC0 converts first then SOC1
AdcRegs.ADCSOC2CTL.bit.ACQPS = 6; // set SOC1 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)

AdcRegs.ADCSOC1CTL.bit.CHSEL = 0x0;    // set SOC2 channel select to ADCINA0
AdcRegs.ADCSOC1CTL.bit.TRIGSEL = 5;    // set SOC2 start trigger on EPWM1A, due to round-robin SOC0 converts first then SOC1
AdcRegs.ADCSOC1CTL.bit.ACQPS = 6; // set SOC2 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)

AdcRegs.ADCSOC3CTL.bit.CHSEL = 0x8;    // set SOC3 channel select to ADCINB0
AdcRegs.ADCSOC3CTL.bit.TRIGSEL = 5;    // set SOC3 start trigger on EPWM1A, due to round-robin SOC0 converts first then SOC1
AdcRegs.ADCSOC3CTL.bit.ACQPS = 6; // set SOC3 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)

AdcRegs.ADCSOC4CTL.bit.CHSEL    = 0x1;    // set SOC3 channel select to ADCINA1
AdcRegs.ADCSOC4CTL.bit.TRIGSEL  = 5;    // set SOC3 start trigger on EPWM1A, due to round-robin SOC0 converts first then SOC1
AdcRegs.ADCSOC4CTL.bit.ACQPS    = 6;    // set SOC3 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)


EDIS;
}
