/*
 * ui.h
 *
 *  Created on: May 16, 2022
 *      Author: Michael Crum
 */

#ifndef UI_H_
#define UI_H_

#include <stdbool.h>

void ui_init(void);

void display_number(int i);

void display_combo(int one, int two, int three);

void wait_button_left();

void wait_button_right();

bool get_button_left();

bool get_button_right();

int get_slider_val();

#endif /* UI_H_ */
