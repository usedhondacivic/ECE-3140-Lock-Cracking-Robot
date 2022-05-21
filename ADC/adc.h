/*
 * adc.h
 *
 *  Created on: May 20, 2022
 *      Author: micac
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

void adc_init(void);

int adc_get_val(void);

int adc_calibrate(void);

#endif /* ADC_ADC_H_ */
