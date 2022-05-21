/*
 * lcd.c
 *
 *  Created on: May 6, 2022
 *      Author: Aaron Wilhelm
 */

#include "board.h"
#include "fsl_slcd.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "lcd.h"

#define MCG_PLL_DISABLE                                   0U  /*!< MCGPLLCLK disabled */
#define OSC_CAP0P                                         0U  /*!< Oscillator 0pF capacitor load */
#define OSC_ER_CLK_DISABLE                                0U  /*!< Disable external reference clock */
#define SIM_OSC32KSEL_LPO_CLK                             3U  /*!< OSC32KSEL select: LPO clock */
#define SIM_PLLFLLSEL_MCGFLLCLK_CLK                       0U  /*!< PLLFLL select: MCGFLLCLK clock */
#define SIM_PLLFLLSEL_MCGPLLCLK_CLK                       1U  /*!< PLLFLL select: MCGPLLCLK clock */

const osc_config_t oscConfig_BOARD_BootClockRUN =
{
	.freq = 8000000U,                         /* Oscillator frequency: 8000000Hz */
	.capLoad = (OSC_CAP0P),                   /* Oscillator capacity load: 0pF */
	.workMode = kOSC_ModeOscLowPower,         /* Oscillator low power */
	.oscerConfig =
		{
			.enableMode = kOSC_ErClkEnable,   /* Enable external reference clock, disable external reference clock in STOP mode */
		}
};
const sim_clock_config_t simConfig_BOARD_BootClockRUN =
{
	.pllFllSel = SIM_PLLFLLSEL_MCGPLLCLK_CLK, /* PLLFLL select: MCGPLLCLK clock */
	.er32kSrc = SIM_OSC32KSEL_LPO_CLK,        /* OSC32KSEL select: LPO clock */
	.clkdiv1 = 0x10010000U,                   /* SIM_CLKDIV1 - OUTDIV1: /2, OUTDIV4: /2 */
};
const mcg_config_t mcgConfig_BOARD_BootClockRUN =
{
	.mcgMode = kMCG_ModePEE,                  /* PEE - PLL Engaged External */
	.irclkEnableMode = kMCG_IrclkEnable,      /* MCGIRCLK enabled, MCGIRCLK disabled in STOP mode */
	.ircs = kMCG_IrcSlow,                     /* Slow internal reference clock selected */
	.fcrdiv = 0x0U,                           /* Fast IRC divider: divided by 1 */
	.frdiv = 0x0U,                            /* FLL reference clock divider: divided by 32 */
	.drs = kMCG_DrsLow,                       /* Low frequency range */
	.dmx32 = kMCG_Dmx32Default,               /* DCO has a default range of 25% */
	.pll0Config =
		{
			.enableMode = MCG_PLL_DISABLE,    /* MCGPLLCLK disabled */
			.prdiv = 0x1U,                    /* PLL Reference divider: divided by 2 */
			.vdiv = 0x0U,                     /* VCO divider: multiplied by 24 */
		},
};

static void CLOCK_CONFIG_SetFllExtRefDiv(uint8_t frdiv)
{
    MCG->C1 = ((MCG->C1 & ~MCG_C1_FRDIV_MASK) | MCG_C1_FRDIV(frdiv));
}

const char segments[10][8] = {"ABCDEF", "BC", "ABEDG", "ABCDG", "BCFG", "ACDDFG", "ACDEFG", "ABC", "ABCDEFG", "ABCDFG"};
LCD_Pin pins[13];

void LCD_TimeDelay(uint32_t count)
{
    while (count--)
    {
        __NOP();
    }
}


void init_lcd() {

	slcd_config_t config;
	slcd_clock_config_t clkConfig = {kSLCD_AlternateClk1, kSLCD_AltClkDivFactor1, kSLCD_ClkPrescaler01, false};

	/* Hardware initialize. */
	/* Port B Clock Gate Control: Clock enabled */
	CLOCK_EnableClock(kCLOCK_PortB);
	/* Port C Clock Gate Control: Clock enabled */
	CLOCK_EnableClock(kCLOCK_PortC);
	/* Port D Clock Gate Control: Clock enabled */
	CLOCK_EnableClock(kCLOCK_PortD);
	/* Port E Clock Gate Control: Clock enabled */
	CLOCK_EnableClock(kCLOCK_PortE);

	/* PORTB10 (pin 60) is configured as LCD_P10 */
	PORT_SetPinMux(PORTB, 10U, kPORT_PinDisabledOrAnalog);

	/* PORTB11 (pin 61) is configured as LCD_P11 */
	PORT_SetPinMux(PORTB, 11U, kPORT_PinDisabledOrAnalog);

	/* PORTB21 (pin 67) is configured as LCD_P17 */
	PORT_SetPinMux(PORTB, 21U, kPORT_PinDisabledOrAnalog);

	/* PORTB22 (pin 68) is configured as LCD_P18 */
	PORT_SetPinMux(PORTB, 22U, kPORT_PinDisabledOrAnalog);

	/* PORTB23 (pin 69) is configured as LCD_P19 */
	PORT_SetPinMux(PORTB, 23U, kPORT_PinDisabledOrAnalog);

	/* PORTB7 (pin 57) is configured as LCD_P7 */
	PORT_SetPinMux(PORTB, 7U, kPORT_PinDisabledOrAnalog);

	/* PORTB8 (pin 58) is configured as LCD_P8 */
	PORT_SetPinMux(PORTB, 8U, kPORT_PinDisabledOrAnalog);

	/* PORTC17 (pin 91) is configured as LCD_P37 */
	PORT_SetPinMux(PORTC, 17U, kPORT_PinDisabledOrAnalog);

	/* PORTC18 (pin 92) is configured as LCD_P38 */
	PORT_SetPinMux(PORTC, 18U, kPORT_PinDisabledOrAnalog);

	/* PORTD0 (pin 93) is configured as LCD_P40 */
	PORT_SetPinMux(PORTD, 0U, kPORT_PinDisabledOrAnalog);

	/* PORTE4 (pin 5) is configured as LCD_P52 */
	PORT_SetPinMux(PORTE, 4U, kPORT_PinDisabledOrAnalog);

	/* PORTE5 (pin 6) is configured as LCD_P53 */
	PORT_SetPinMux(PORTE, 5U, kPORT_PinDisabledOrAnalog);

	/* Set the system clock dividers in SIM to safe value. */
	CLOCK_SetSimSafeDivs();
	/* Initializes OSC0 according to board configuration. */
	CLOCK_InitOsc0(&oscConfig_BOARD_BootClockRUN);
	CLOCK_SetXtal0Freq(oscConfig_BOARD_BootClockRUN.freq);
	/* Configure FLL external reference divider (FRDIV). */
	CLOCK_CONFIG_SetFllExtRefDiv(mcgConfig_BOARD_BootClockRUN.frdiv);
	/* Set MCG to PEE mode. */
	CLOCK_BootToPeeMode(kMCG_OscselOsc,
						kMCG_PllClkSelPll0,
						&mcgConfig_BOARD_BootClockRUN.pll0Config);
	/* Configure the Internal Reference clock (MCGIRCLK). */
	CLOCK_SetInternalRefClkConfig(mcgConfig_BOARD_BootClockRUN.irclkEnableMode,
								  mcgConfig_BOARD_BootClockRUN.ircs,
								  mcgConfig_BOARD_BootClockRUN.fcrdiv);
	/* Set the clock configuration in SIM module. */
	CLOCK_SetSimConfig(&simConfig_BOARD_BootClockRUN);

	/* SLCD get default configure. */
	/*
	 * config.displayMode = kSLCD_NormalMode;
	 * config.powerSupply = kSLCD_InternalVll3UseChargePump;
	 * config.voltageTrim = kSLCD_RegulatedVolatgeTrim08;
	 * config.lowPowerBehavior = kSLCD_EnabledInWaitStop;
	 * config.frameFreqIntEnable = false;
	 * config.faultConfig = NULL;
	 */
	SLCD_GetDefaultConfig(&config);

	/* Verify and Complete the configuration structure. */
	config.clkConfig = &clkConfig;
	config.loadAdjust = kSLCD_HighLoadOrSlowestClkSrc;
	config.dutyCycle = kSLCD_1Div4DutyCycle;
	config.slcdLowPinEnabled = 0x000e0d80U;  /* LCD_P19/P18/P17/P11/P10/P8/P7. */
	config.slcdHighPinEnabled = 0x00300160U; /* LCD_P53/P52/P40/P38/P37. */
	config.backPlaneLowPin = 0x000c0000U;    /* LCD_P19/P18 --> b19/b18. */
	config.backPlaneHighPin = 0x00100100U;   /* LCD_P52/P40 --> b20/b8. */

	config.faultConfig = NULL;
	/* SLCD Initialize. */
	SLCD_Init(LCD, &config);

	// initialize the p
	pins[0] = (LCD_Pin) {0};
	pins[1] = (LCD_Pin) { .mcu_pin=40, .waveForm=kSLCD_PhaseAActivate, .isBackPlane=1 }; /* SLCD COM1 --- LCD_P40. */
	pins[2] = (LCD_Pin) { .mcu_pin=52, .waveForm=kSLCD_PhaseBActivate, .isBackPlane=1 }; /* SLCD COM2 --- LCD_P52. */
	pins[3] = (LCD_Pin) { .mcu_pin=19, .waveForm=kSLCD_PhaseCActivate, .isBackPlane=1 }; /* SLCD COM3 --- LCD_P19. */
	pins[4] = (LCD_Pin) { .mcu_pin=18, .waveForm=kSLCD_PhaseDActivate, .isBackPlane=1 }; /* SLCD COM4 --- LCD_P18. */
	pins[5] = (LCD_Pin) { .mcu_pin=37, .waveForm=0, .isBackPlane=0 }; /* SLCD P05 --- LCD_P37. */
	pins[6] = (LCD_Pin) { .mcu_pin=17, .waveForm=0, .isBackPlane=0 }; /* SLCD P06 --- LCD_P17. */
	pins[7] = (LCD_Pin) { .mcu_pin=7, .waveForm=0, .isBackPlane=0 }; /* SLCD P07 --- LCD_P7. */
	pins[8] = (LCD_Pin) { .mcu_pin=8, .waveForm=0, .isBackPlane=0 }; /* SLCD P08 --- LCD_P8. */
	pins[9] = (LCD_Pin) { .mcu_pin=53, .waveForm=0, .isBackPlane=0 }; /* SLCD P09 --- LCD_P53. */
	pins[10] = (LCD_Pin) { .mcu_pin=38, .waveForm=0, .isBackPlane=0 }; /* SLCD P10 --- LCD_P38. */
	pins[11] = (LCD_Pin) { .mcu_pin=10, .waveForm=0, .isBackPlane=0 }; /* SLCD P11 --- LCD_P10. */
	pins[12] = (LCD_Pin) { .mcu_pin=11, .waveForm=0, .isBackPlane=0 }; /* SLCD P12 --- LCD_P11. */

	/* Set SLCD back plane phase. */
	SLCD_SetBackPlanePhase(LCD, 40, kSLCD_PhaseAActivate); /* SLCD COM1 --- LCD_P40. */
	SLCD_SetBackPlanePhase(LCD, 52, kSLCD_PhaseBActivate); /* SLCD COM2 --- LCD_P52. */
	SLCD_SetBackPlanePhase(LCD, 19, kSLCD_PhaseCActivate); /* SLCD COM3 --- LCD_P19. */
	SLCD_SetBackPlanePhase(LCD, 18, kSLCD_PhaseDActivate); /* SLCD COM4 --- LCD_P18. */
    SLCD_StartDisplay(LCD);
}


// dig_num is the digit number ranging from 1 to 4
// seg_char is letter corresponding to the desired segment ranging from A-F, P for decimal point and N for colon
void segmentToPinNumber(int dig_num, char seg_char, int* pin_num, uint8_t* waveForm) {
	*pin_num = 5 + 2*(dig_num-1);  // See LCD-S401M16KR datasheet for segment to pin conversions
	if(seg_char == 'A' || seg_char == 'B' || seg_char == 'C' || seg_char == 'P') {
		*pin_num += 1;
	}
	if(seg_char == 'N'){
		*pin_num = 12;
	}

	if(seg_char == 'A' || seg_char == 'F') {
		*waveForm = kSLCD_PhaseDActivate;
	} else if(seg_char == 'B' || seg_char == 'G') {
		*waveForm = kSLCD_PhaseCActivate;
	} else if(seg_char == 'C' || seg_char == 'E') {
		*waveForm = kSLCD_PhaseBActivate;
	} else {
		*waveForm = kSLCD_PhaseAActivate;
	}
}


// disp_num is the display digit number ranging from 1 to 4
// seg_char is letter corresponding to the desired segment ranging from A-F, P for decimal point and N for colon
void turnOnSegment(int disp_num, char seg_char) {
	uint8_t waveForm;
	int pin_num;
	segmentToPinNumber(disp_num, seg_char, &pin_num, &waveForm);
	pins[pin_num].waveForm |= waveForm;
	SLCD_SetFrontPlaneSegments(LCD, pins[pin_num].mcu_pin, pins[pin_num].waveForm);
}

// disp_num is the display digit number ranging from 1 to 4
// seg_char is letter corresponding to the desired segment ranging from A-F, P for decimal point and N for colon
void turnOffSegment(int disp_num, char seg_char) {
	uint8_t waveForm;
	int pin_num;
	segmentToPinNumber(disp_num, seg_char, &pin_num, &waveForm);
	pins[pin_num].waveForm &= ~waveForm;
	SLCD_SetFrontPlaneSegments(LCD, pins[pin_num].mcu_pin, pins[pin_num].waveForm);
}


// clears the specified display
// disp_num is the display digit number ranging from 1 to 4
void clearDigit(int disp_num) {
	int clear_val = 8;  // as 8 uses all segments, turn off all segments in 8 to clear the digit
	int idx = 0;
	while(segments[clear_val][idx] != 0) {
		turnOffSegment(disp_num, segments[clear_val][idx]);
		idx++;
	}
}


// displays the digit at the specified display.
// Any number currently displayed will be erased before the new one is written
// disp_num is the display digit number ranging from 1 to 4
// digit is the digit to be displayed
void displayDigit(int disp_num, int digit) {
	clearDigit(disp_num);
	int idx = 0;
	while(segments[digit][idx] != 0) {
		turnOnSegment(disp_num, segments[digit][idx]);
		idx++;
	}
}


// displays the specified decimal point
void displayDecimalPoint(int dp_num) {
	turnOnSegment(dp_num, 'P');
}


// clears the specified decimal
void clearDecimalPoint(int dp_num) {
	turnOffSegment(dp_num, 'P');
}


// displays the colon
void displayColon() {
	turnOnSegment(4, 'N');
}


// clears the colon
void clearColon() {
	turnOffSegment(4, 'N');
}


// clears the entire display
void clearDisplay() {
	for(int disp_num = 1; disp_num <= 4; disp_num++) {
		clearDigit(disp_num);
	}
	for(int dp_num = 1; dp_num <= 3; dp_num++) {
		clearDecimalPoint(dp_num);
	}
	clearColon();
}
