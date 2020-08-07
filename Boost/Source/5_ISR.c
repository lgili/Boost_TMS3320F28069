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
#include "Defines.h"


//Uint16 ConversionCount;
Uint16 Corrente;
Uint16 Tensao;

// Vri�veis para a implementa��o do controle
static double aV, bV, aI, bI, y0v, y1v, r0v, r1v, y0i, y1i, r0i, r1i, V_lido, I_lido, Vref;
static double kci, wzi, kcv, wzv;
static double ki, Rmi, kadc, kv, Rmv;

void ISR (void)
{
	//-- Configura��es Individuais Perif�ricos --------------------------------


	//-- Populaciona o vetor PIE com o endere�o das ISR -----------------------
	EALLOW;
	//PieVectTable.XXX= &XXX;	// Int XXX
	PieVectTable.ADCINT1 = &ADCINT1_ISR;

	EDIS;


	//-- Habilita as Interup��es Desejadas (PIE) ------------------------------
	PieCtrlRegs.PIEACK.all  = 0xFFFF;		// Reseta o bit de acknowledgement
	//PieCtrlRegs.PIEIERXXX.bit.INTxXXX = 1;	//HAB. INT. XXX


	//-- Habilita as Interup��es no CPU ---------------------------------------
	//IER |= M_INTX;	// Enable CPU Interrupt X


	EINT;  	// Enable Interrupts at the CPU level
	ERTM; 	// Coloca 0 no FLAG DBGM, permitindo Debug em Tempo Real
}
__interrupt void ADCINT1_ISR(void)
{

  Corrente = AdcResult.ADCRESULT1;  // set SOC1 channel select to ADCINB0
  Tensao = AdcResult.ADCRESULT0;    // set SOC0 channel select to ADCINA0

  if(AdcResult.ADCRESULT0>3500 || AdcResult.ADCRESULT1>3500)
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
  }
  else
  {
  // Controle

//----------------Constantes------------------------------------------------
    //sensor de corrente
	ki = 0.001;                   		 // Ganho do sensor de corrente
    Rmi = 130;                     		 // Resistor do sensor de corrente
    kadc = 4096./3.3;             		 // Ganho do ADC
   // kio = ki*Rmi*kadc;             		 // Ganho de corrente em tens�o

    //sensor de tensao
    kv = 2.5    ;                         // Ganho do sensor de Tens�o
    Vref = 0.01;                         // LV 55-P (Vref=400V em corrente 10mA)
    Rmv = 100;                           // Resistor do sensor de Tens�o
    //kvo = Vref*kv*Rmv*kadc               // Ganho do sensor de Tens�o em tens�o


   //Ta = 1./100000;               		 // Per�odo de amostragem

    kci = 0.000579049769267075;   		 // Ganho do controlador PI de corrente
    wzi = 1797.28220911438;      		 // Frequ�ncia do zedo do controlador PI de corrente

    kcv =						  		 // Ganho do controlador PI de corrente
    wzv = 						 	 	 // Frequ�ncia do zedo do controlador PI de corrente

// -------------------------------------------------------------------------

//---------------Par�metros do controlador PI-------------------------------

    		//controlador de tens�o

    V_lido = Tensao;     // Vari�vel de controle recebe AdcResult 1 Soc1

    /*r1v = 4-Vo;                     	  // Erro da Malha de tens�o (4 = 400V *0.01)

    aV = (kcv*wzv*Ta+(2*kcv))/2;          // Constante do controlador PI de tens�o discretizado
    bV = (kcv*wzv*Ta-(2*kcv))/2;		  // Constante do controlador PI de tens�o discretizado

    y1v = y0v+(a1*r1v) + (b1*r0v);        // Controlador PI de tens�o discretizado (y1v = Iref)

    if(y1v>10) y1v=10;                    // Saturador da malha de tens�o. (limita o valor da corrente fornecida pela fonte at� a tens�o chegar a 400V).

    r0v = r1v;                            // Atualiza as vari�veis
    y0v = y1v;							  // Atualiza as vari�veis

    		//controlador de corrente

    I_lido = Corrente;	  // Vari�vel de controle recebe AdcResult 0 Soc0

    r1i = y1v-I_lido;					  // Erro da malha de corrente (y1v = Iref)

    aI = (kci*wzi*Ta+(2*kci))/2;	      // Constante do controlador PI de corrente discretizado
    bI = (kci*wzi*Ta-(2*kci))/2;          // Constante do controlador PI de corrente discretizado

    y1i = y0i+(a2*r1i) + (b2*r0i); 		  // Controlador PI de corrente discretizado (y1i = d)

    r0i=r1i;							  // Atualiza as vari�veis
    y0i=y1i; 			 				  // Atualiza as vari�veis

    d = y1i;	*/					      // Raz�o C�clica

   // if(d>0.5) d=0.5;					  // Saturador da malha de corrente. (limita o valor da raz�o c�clica. Ex.: Conversor Forward max D = 0.5)

   	//EPwm1Regs.CMPA.half.CMPA = d;	      // Comparador ePWM1A atualiza com o valor de "d"
   	//EPwm2Regs.CMPA.half.CMPA = d;		  // Comparador ePWM2A atualiza com o valor de "d"
   	//EPwm3Regs.CMPA.half.CMPA = d;		  // Comparador ePWM3A atualiza com o valor de "d"
   	//EPwm4Regs.CMPA.half.CMPA = d;		  // Comparador ePWM4A atualiza com o valor de "d"
  }

//------------------Atualiza as vari�ves------------------------------------

    //i0=i1;
    //ei0=ei1;
}
