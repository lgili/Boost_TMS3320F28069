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
#include "F2806x_EPwm_defines.h"             // Macros used for PWM examples.
#include "F2806x_EPwm.h"               // Enhanced PWM
//#include "Defines.h"
//#include "Geral.h"


void PWM (void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;  // Para poder sincronizar ao TBCLK
    EDIS;

    //-- Configura��o PWM  ---------------------------------------------------
    //// ePWM1 ////
    EPwm1Regs.ETSEL.bit.SOCAEN = 1;          // Enable the ADC Start of Conversion A (EPWMxSOCA) Pulse.
    EPwm1Regs.ETSEL.bit.SOCASEL = 3;         // Determine when a EPWMxSOCA pulse will be generated. (3 -> When CTR = ZERO or PRD)
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;          // Generate pulse on 1st event.
    EPwm1Regs.CMPA.half.CMPA = 360;          // Set compare A value.
    EPwm1Regs.TBPRD = 900;                   // Set period for ePWM1.
    EPwm1Regs.TBCTL.bit.CTRMODE = 0;         // 2 -> Up-Down-Count mode.
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // Clock ratio to SYSCLKOUT
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;
    EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;
    //EPwm1Regs.AQCTLA.bit.PRD = AQ_CLEAR;
    EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    //EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;

    //config defasagem pwm1
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;
    EPwm1Regs.TBPHS.half.TBPHS= 0x0;
    EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO; // Sync down-stream module
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;

    //// ePWM2 ////
    EPwm2Regs.ETSEL.bit.SOCAEN = 1;          // Enable the ADC Start of Conversion A (EPWMxSOCA) Pulse.
    EPwm2Regs.ETSEL.bit.SOCASEL = 3;         // Determine when a EPWMxSOCA pulse will be generated. (3 -> When CTR = ZERO or PRD)
    EPwm2Regs.ETPS.bit.SOCAPRD = 1;          // Generate pulse on 1st event.
    EPwm2Regs.CMPA.half.CMPA = 360;          // Set compare A value.
    EPwm2Regs.TBPRD = 900;                   // Set period for ePWM1.
    EPwm2Regs.TBCTL.bit.CTRMODE = 0;         // 2 -> Up-Down-Count mode.
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // Clock ratio to SYSCLKOUT
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;
    EPwm2Regs.AQCTLA.bit.ZRO = AQ_SET;
    //EPwm1Regs.AQCTLA.bit.PRD = AQ_CLEAR;
    EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    //EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;

    //config defasagem pwm2
    EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;
    EPwm2Regs.TBPHS.half.TBPHS= 0xE1;
    EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // Sync down-stream module
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;



    //// ePWM3 ////
    EPwm3Regs.ETSEL.bit.SOCAEN = 1;          // Enable the ADC Start of Conversion A (EPWMxSOCA) Pulse.
    EPwm3Regs.ETSEL.bit.SOCASEL = 3;         // Determine when a EPWMxSOCA pulse will be generated. (3 -> When CTR = ZERO or PRD)
    EPwm3Regs.ETPS.bit.SOCAPRD = 1;          // Generate pulse on 1st event.
    EPwm3Regs.CMPA.half.CMPA = 360;          // Set compare A value.
    EPwm3Regs.TBPRD = 900;                   // Set period for ePWM1.
    EPwm3Regs.TBCTL.bit.CTRMODE = 0;         // 0 -> Up-Count mode 2 -> Up-Down-Count mode.
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // Clock ratio to SYSCLKOUT
    EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;
    EPwm3Regs.AQCTLA.bit.ZRO = AQ_SET;
    //EPwm1Regs.AQCTLA.bit.PRD = AQ_CLEAR;
    EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    //EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;

    //config defasagem pwm3
    EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE;
    EPwm3Regs.TBPHS.half.TBPHS= 0x1C2;
    EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // Sync down-stream module
    EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;


    //// ePWM4 ////
    EPwm4Regs.ETSEL.bit.SOCAEN = 1;          // Enable the ADC Start of Conversion A (EPWMxSOCA) Pulse.
    EPwm4Regs.ETSEL.bit.SOCASEL = 3;         // Determine when a EPWMxSOCA pulse will be generated. (3 -> When CTR = ZERO or PRD)
    EPwm4Regs.ETPS.bit.SOCAPRD = 1;          // Generate pulse on 1st event.
    EPwm4Regs.CMPA.half.CMPA = 360;          // Set compare A value.
    EPwm4Regs.TBPRD = 900;                   // Set period for ePWM1.
    EPwm4Regs.TBCTL.bit.CTRMODE = 0;         // 2 -> Up-Down-Count mode.
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // Clock ratio to SYSCLKOUT
    EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;
    EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;
    //EPwm1Regs.AQCTLA.bit.PRD = AQ_CLEAR;
    EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    //EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;

    //config defasagem pwm4
    EPwm4Regs.TBCTL.bit.PHSEN = TB_ENABLE;
    EPwm4Regs.TBPHS.half.TBPHS= 0x2A3;
    EPwm4Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // Sync down-stream module
    EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;


    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;  // Sincroniza os m�dulos ao TBCLK
    EDIS;
}
