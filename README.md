## Your Project Answers

### Project Description

We propose to design a solar panel charge controller that is designed to emulate a renewable home power generation system which powers the home using solar panels and diverts excess energy to an in-home energy storage device. Our system will perform the following functions under these different conditions:

 

Is the battery charged?

Is the solar panel generating power?

Route power from:

Yes

Yes

Solar panel to load

No

Yes

Solar panel to battery & load

Yes

No

Battery to load
### Technical Approach

Hardware

Since there are high and low voltage systems interfacing in our design, we recognize the need to isolate both systems from each other using switches, relays, and other components. Our bill of materials is as follows.

 

Item

Quantity

Function

[5V One Channel Relay Module] (https://www.amazon.com/gp/product/B00LW15A4W/ref=ox_sc_act_title_1?smid=A30QSGOJR8LMXA&psc=1)

[B00LW15A4W] (https://www.amazon.com/gp/product/B00LW15A4W/ref=ox_sc_act_title_1?smid=A30QSGOJR8LMXA&psc=1)

4

Allows low voltage FRDM board to control power routing between battery, solar panel, and load and isolate the board from the high voltage circuit.

[SparkFun Current Sensor] (https://www.amazon.com/gp/product/B07GL56CH5/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

[ACS723] (https://www.amazon.com/gp/product/B07GL56CH5/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

2

Determines if circuit components are on and generating power. Allows us to isolate and protect the battery and load in the event of current spikes.

[I2C 16x2 LCD Display Module] (https://www.amazon.com/GeeekPi-Character-Backlight-Raspberry-Electrical/dp/B07S7PJYM6/ref=pd_day0_sccl_3/131-6114398-9652515?pd_rd_w=MVxlg&pf_rd_p=8ca997d7-1ea0-4c8f-9e14-a6d756b83e30&pf_rd_r=4ABPFXBQD8KZAJ6XW78V&pd_rd_r=ba18e0d6-b1d5-4261-a12f-f6df382de9c6&pd_rd_wg=FVU4K&pd_rd_i=B07S7PJYM6&psc=1)

2

Display voltage and current from different circuit sections.

[Bi-directional 3.3V-5V Logic Level Converter] (https://www.amazon.com/gp/product/B07LG646VS/ref=ox_sc_act_title_1?smid=A2K4DGCC72N9AG&psc=1)

10

Allows 3.3V FRDM Board to interface with the 5V LCD module and 5V relays

 

Software

We will use the FRDM board to control the power routing between the solar panel, load, and battery. 

For our system, inputs for the board include:

* Voltage measurements

* Battery terminals

* Solar panel terminals

* Current measurements

* From solar panel terminals

* Into load terminals

Using these inputs, we intend to use “[maximum power point tracking] (https://en.wikipedia.org/wiki/Maximum_power_point_tracking)” (MPPT) to determine the most efficient power switching point for the solar panel and determine the correct current and voltage thresholds at which we should reroute power.

The processes required include:

* Polling current and voltage sensors

* Calculating optimum switching point using MPPT

* Relay control

* Writing to LCD; should display the relevant current and voltage measurements
Hardware

Since there are high and low voltage systems interfacing in our design, we recognize the need to isolate both systems from each other using switches, relays, and other components. Our bill of materials is as follows.

 

Item

Quantity

Function

[5V One Channel Relay Module] (https://www.amazon.com/gp/product/B00LW15A4W/ref=ox_sc_act_title_1?smid=A30QSGOJR8LMXA&psc=1)

[B00LW15A4W] (https://www.amazon.com/gp/product/B00LW15A4W/ref=ox_sc_act_title_1?smid=A30QSGOJR8LMXA&psc=1)

4

Allows low voltage FRDM board to control power routing between battery, solar panel, and load and isolate the board from the high voltage circuit.

[SparkFun Current Sensor] (https://www.amazon.com/gp/product/B07GL56CH5/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

[ACS723] (https://www.amazon.com/gp/product/B07GL56CH5/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

2

Determines if circuit components are on and generating power. Allows us to isolate and protect the battery and load in the event of current spikes.

[I2C 16x2 LCD Display Module] (https://www.amazon.com/GeeekPi-Character-Backlight-Raspberry-Electrical/dp/B07S7PJYM6/ref=pd_day0_sccl_3/131-6114398-9652515?pd_rd_w=MVxlg&pf_rd_p=8ca997d7-1ea0-4c8f-9e14-a6d756b83e30&pf_rd_r=4ABPFXBQD8KZAJ6XW78V&pd_rd_r=ba18e0d6-b1d5-4261-a12f-f6df382de9c6&pd_rd_wg=FVU4K&pd_rd_i=B07S7PJYM6&psc=1)

2

Display voltage and current from different circuit sections.

[Bi-directional 3.3V-5V Logic Level Converter] (https://www.amazon.com/gp/product/B07LG646VS/ref=ox_sc_act_title_1?smid=A2K4DGCC72N9AG&psc=1)

10

Allows 3.3V FRDM Board to interface with the 5V LCD module and 5V relays

 

Software

We will use the FRDM board to control the power routing between the solar panel, load, and battery. 

For our system, inputs for the board include:

* Voltage measurements

* Battery terminals

* Solar panel terminals

* Current measurements

* From solar panel terminals

* Into load terminals

Using these inputs, we intend to use “[maximum power point tracking] (https://en.wikipedia.org/wiki/Maximum_power_point_tracking)” (MPPT) to determine the most efficient power switching point for the solar panel and determine the correct current and voltage thresholds at which we should reroute power.

The processes required include:

* Polling current and voltage sensors

* Calculating optimum switching point using MPPT

* Relay control

* Writing to LCD; should display the relevant current and voltage measurements

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/am2389-no83" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/am2389-no83" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.