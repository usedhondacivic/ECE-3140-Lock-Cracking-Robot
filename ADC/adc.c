#include "fsl_adc16.h"
#include "adc.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_ADC16_BASE ADC0
#define DEMO_ADC16_CHANNEL_GROUP 0U
#define DEMO_ADC16_USER_CHANNEL 0U /* PTE20, ADC0_SE0 */
#define MCG_PLL_DISABLE                                   0U  /*!< MCGPLLCLK disabled */
#define OSC_CAP0P                                         0U  /*!< Oscillator 0pF capacitor load */
#define OSC_ER_CLK_DISABLE                                0U  /*!< Disable external reference clock */
#define SIM_OSC32KSEL_LPO_CLK                             3U  /*!< OSC32KSEL select: LPO clock */
#define SIM_PLLFLLSEL_MCGFLLCLK_CLK                       0U  /*!< PLLFLL select: MCGFLLCLK clock */
#define SIM_PLLFLLSEL_MCGPLLCLK_CLK                       1U  /*!< PLLFLL select: MCGPLLCLK clock */

const osc_config_t oscConfig =
{
	.freq = 8000000U,                         /* Oscillator frequency: 8000000Hz */
	.capLoad = (OSC_CAP0P),                   /* Oscillator capacity load: 0pF */
	.workMode = kOSC_ModeOscLowPower,         /* Oscillator low power */
	.oscerConfig =
		{
			.enableMode = kOSC_ErClkEnable,   /* Enable external reference clock, disable external reference clock in STOP mode */
		}
};
const sim_clock_config_t simConfig =
{
	.pllFllSel = SIM_PLLFLLSEL_MCGPLLCLK_CLK, /* PLLFLL select: MCGPLLCLK clock */
	.er32kSrc = SIM_OSC32KSEL_LPO_CLK,        /* OSC32KSEL select: LPO clock */
	.clkdiv1 = 0x10010000U,                   /* SIM_CLKDIV1 - OUTDIV1: /2, OUTDIV4: /2 */
};
const mcg_config_t mcgConfig =
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


adc16_config_t adc16ConfigStruct;
adc16_channel_config_t adc16ChannelConfigStruct;

void adc_init(void){
	//Turn on the clock gating to port E
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

	//PORTE->PCR[20] = PORT_PCR_MUX(001);

	/* Set the system clock dividers in SIM to safe value. */
	CLOCK_SetSimSafeDivs();
	/* Initializes OSC0 according to board configuration. */
	CLOCK_InitOsc0(&oscConfig);
	CLOCK_SetXtal0Freq(oscConfig.freq);
	/* Configure FLL external reference divider (FRDIV). */
	CLOCK_CONFIG_SetFllExtRefDiv(mcgConfig.frdiv);
	/* Set MCG to PEE mode. */
	CLOCK_BootToPeeMode(kMCG_OscselOsc,
						kMCG_PllClkSelPll0,
						&mcgConfig.pll0Config);
	/* Configure the Internal Reference clock (MCGIRCLK). */
	CLOCK_SetInternalRefClkConfig(mcgConfig.irclkEnableMode,
								  mcgConfig.ircs,
								  mcgConfig.fcrdiv);
	/* Set the clock configuration in SIM module. */
	CLOCK_SetSimConfig(&simConfig);

	ADC16_GetDefaultConfig(&adc16ConfigStruct);
	adc16ConfigStruct.longSampleMode = kADC16_LongSampleCycle24;
	ADC16_Init(DEMO_ADC16_BASE, &adc16ConfigStruct);
	ADC16_EnableHardwareTrigger(DEMO_ADC16_BASE, false); /* Make sure the software trigger is used. */
	#if defined(FSL_FEATURE_ADC16_HAS_CALIBRATION) && FSL_FEATURE_ADC16_HAS_CALIBRATION
	    if (kStatus_Success == ADC16_DoAutoCalibration(DEMO_ADC16_BASE))
	    {

	    }
	#endif /* FSL_FEATURE_ADC16_HAS_CALIBRATION */
	    adc16ChannelConfigStruct.channelNumber = DEMO_ADC16_USER_CHANNEL;
	    adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = false;
	#if defined(FSL_FEATURE_ADC16_HAS_DIFF_MODE) && FSL_FEATURE_ADC16_HAS_DIFF_MODE
	    adc16ChannelConfigStruct.enableDifferentialConversion = false;
	#endif /* FSL_FEATURE_ADC16_HAS_DIFF_MODE */
}

int adc_calibrate(void){
	return (kStatus_Success == ADC16_DoAutoCalibration(DEMO_ADC16_BASE));
}

int adc_get_val(void){
	int val[2];
	for(int i =0; i < 3; i++){
		ADC16_SetChannelConfig(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP, &adc16ChannelConfigStruct);
		while (0U == (kADC16_ChannelConversionDoneFlag &
					  ADC16_GetChannelStatusFlags(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP)))
		{
		}
		val[i] = ADC16_GetChannelConversionValue(DEMO_ADC16_BASE, DEMO_ADC16_CHANNEL_GROUP);
	}
	return (val[0] + val[1] + val[2]) / 3;
}
