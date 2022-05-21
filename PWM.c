/*
 * PWM.c
 *
 *  Created on: May 12, 2022
 *      Author: Michael Crum
 */

#include <MKL46Z4.h>

void pwm_init(void){
	//Turn on clock gating for port C
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	//Set the TPM to use the MCFGLLCLK
	SIM->SOPT2 = SIM_SOPT2_PLLFLLSEL(0);
	SIM->SOPT2 = SIM_SOPT2_TPMSRC(01);
	//Turn on clock gating for TPM0
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
	//Set the pin MUX to TMP channel 4
	PORTC->PCR[8] = PORT_PCR_MUX(3); // Pin C8
	//Allow to run in debug mode
	//TPM0->CONF = TPM_CONF_DBGMODE(3);
	//Set the TPM to up counting, incrementing every clock, edge-aligned
	(TPM0->CONTROLS[4]).CnSC |= (1 << 5 | 1 << 3); //MSB = 1 && ELSB = 1
	TPM0->SC = TPM_SC_CPWMS(0);
	//Enable TPM
	TPM0->SC = TPM_SC_CMOD(01);
}

void set_control(int pulse_width, int period){
	//Set the frequency and pulse width
	TPM0->SC = TPM_SC_CMOD(00);
	TPM0->SC |= 5; // 32x pre-scale
	TPM0->MOD = TPM_MOD_MOD((int)(period*0.66));
	(TPM0->CONTROLS[4]).CnV = TPM_CnV_VAL((int)(pulse_width*0.66));
	TPM0->SC = TPM_SC_CMOD(01);
}

void pwm_disable(){
	//Disable TPM
	TPM0->SC = TPM_SC_CMOD(00);
}
