/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

                                INEP-UFSC
___________________________________________________________________________
                |
-        PROJETO: 28069_LIMPO
-        ARQUIVO: 5_ISR.c
________________|__________________________________________________________
                |
-           DATA: 29/04/2015
-    ATUALIZA��O:
-         VERS�O: 1.0
________________|__________________________________________________________
                |
-DESENVOLVIMENTO: VICTOR FERREIRA GRUNER
-   ORIENTADORES: ROBERTO FRANSCISCO COELHO
_______________ |__________________________________________________________
                |
-    OBSERVA��ES:
_______________ |__________________________________________________________
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

//-- Includes -------------------------------------------------------------
#include "F2806x_Device.h"
#include "F2806x_Adc.h"                // ADC Registers
#include "F2806x_DefaultISR.h"
#include "F2806x_EPwm_defines.h"             // Macros used for PWM examples.
//#include "Defines.h"
//#include "uart.h"

interrupt void adca1_isr(void);


unsigned long ui32BaseSCI = 0x00007050;   // SCI-A
extern  Uint16 ReceivedChar;

Uint16 local;
//Uint16 ConversionCount;


// Vri�veis para a implementa��o do controle
float Corrente,Vbus,Va,Vb,Vc;

int count =0;
int state_Boost=0, state_Buck=0;

float iRef=0.4f;
float vBusRef = 670;
int prot =0;

void ISR (void)
{
    //-- Configura��es Individuais Perif�ricos --------------------------------


    //-- Populaciona o vetor PIE com o endere�o das ISR -----------------------
    EALLOW;
    //PieVectTable.XXX= &XXX;   // Int XXX
    PieVectTable.ADCINT1 = &adca1_isr;

    EDIS;


    //-- Habilita as Interup��es Desejadas (PIE) ------------------------------
    PieCtrlRegs.PIEACK.all  = 0xFFFF;       // Reseta o bit de acknowledgement
    PieCtrlRegs.PIEIER1.bit.INTx1 = 1;  //HAB. INT. XXX
    //PieCtrlRegs.PIEIERXXX.bit.INTxXXX = 1;    //HAB. INT. XXX


    //-- Habilita as Interup��es no CPU ---------------------------------------
    //IER |= M_INTX;    // Enable CPU Interrupt X
    IER |= M_INT1;  // Enable CPU Interrupt X


    EINT;   // Enable Interrupts at the CPU level
    ERTM;   // Coloca 0 no FLAG DBGM, permitindo Debug em Tempo Real
}

interrupt void adca1_isr(void)
{
    /*EALLOW;
    GpioDataRegs.GPASET.bit.GPIO2 = 1;
    EDIS;*/
   /* Uint16 ReceivedChar;
    unsigned char *msg;

    ReceivedChar = UARTCharGet(ui32BaseSCI);
    UARTCharPutNonBlocking(ui32BaseSCI, ReceivedChar);*/

      Corrente = 0.008954*(AdcResult.ADCRESULT0);  // set SOC1 channel select to ADCINB0
      Vbus = 0.251518*(AdcResult.ADCRESULT2);    // set SOC0 channel select to ADCINA0
      Va = 0.211225*(AdcResult.ADCRESULT1);
      Vb = 0.211225*(AdcResult.ADCRESULT3);
      Vc = 0.211225*(AdcResult.ADCRESULT4);

      // Ref corrente
      iRef = ReceivedChar * 0.127;

      if(Corrente > 35 || Vbus > 750 )
      {
      EPwm1Regs.AQCTLA.bit.ZRO = AQ_CLEAR;
      EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
      EPwm1Regs.AQCTLB.bit.ZRO = AQ_CLEAR;
      EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR;

      EPwm2Regs.AQCTLA.bit.ZRO = AQ_CLEAR;
      EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
      EPwm2Regs.AQCTLB.bit.ZRO = AQ_CLEAR;
      EPwm2Regs.AQCTLB.bit.CBU = AQ_CLEAR;

      EPwm3Regs.AQCTLA.bit.ZRO = AQ_CLEAR;
      EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;
      EPwm3Regs.AQCTLB.bit.ZRO = AQ_CLEAR;
      EPwm3Regs.AQCTLB.bit.CBU = AQ_CLEAR;

        EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;
        EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;
        EPwm4Regs.AQCTLB.bit.ZRO = AQ_CLEAR;
        EPwm4Regs.AQCTLB.bit.CBU = AQ_CLEAR;

        EALLOW;
            GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
            GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
            EDIS;

            prot = 1;
      }
      else
      {
      // Controle

    //----------------Para teste malha aberta------------------------------------------------
         /* count++;
          if(count < 20)
          {
              EALLOW;
              GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
              GpioDataRegs.GPASET.bit.GPIO2 = 1;
              EDIS;
          }
          else if(count >= 20 && count < 40)
          {
              EALLOW;
              GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
              GpioDataRegs.GPASET.bit.GPIO0 = 1;
              EDIS;
          }
          else
          {
              count = 0;
          }*/

    // -------------------------------------------------------------------------

          // Control Boost
          //Boost.var.histereseCtrl.run(&Boost.var.histereseCtrl.var, 20.0f, Corrente, 0.25f);
          if(state_Boost == 1 && Corrente > (iRef + 0.25))
          {
              state_Boost = 0;
          }
          else if(state_Boost == 0 && Corrente < (iRef - 0.25))
          {
              state_Boost = 1;
          }

          // Control Buck
          //Buck.var.histereseCtrl.run(&Buck.var.histereseCtrl.var, 600.0f, Vbus, 5.0f);

           if(state_Buck == 0 && Vbus > (vBusRef + 5))
            {
               state_Buck = 1;
            }
            else if(state_Buck == 1 && Vbus < (vBusRef - 5))
            {
                state_Buck = 0;
            }

          if(state_Boost == 1 && prot == 0)
          {
             EALLOW;
             GpioDataRegs.GPASET.bit.GPIO0 = 1;
             EDIS;
          }
          else
          {
              EALLOW;
              GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
              EDIS;
          }


          if(state_Buck == 1 && prot == 0)
          {
             EALLOW;
             GpioDataRegs.GPASET.bit.GPIO2 = 1;
             EDIS;
          }
          else
          {
              EALLOW;
              GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
              EDIS;
          }



        //EPwm1Regs.CMPA.half.CMPA = 4500;      // Comparador ePWM1A atualiza com o valor de "d"
        //EPwm2Regs.CMPA.half.CMPA = 4500;  // Comparador ePWM2A atualiza com o valor de "d"
        //EPwm3Regs.CMPA.half.CMPA = d;  // Comparador ePWM3A atualiza com o valor de "d"
        //EPwm4Regs.CMPA.half.CMPA = d;  // Comparador ePWM4A atualiza com o valor de "d"
      }
                  /*EALLOW;
                  GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
                  EDIS;*/


//------------------Atualiza as vari�ves------------------------------------

    //i0=i1;
    //ei0=ei1;
    AdcRegs.ADCINTFLGCLR.all = 0x0001;
    PieCtrlRegs.PIEACK.all = 0x0001;
}
