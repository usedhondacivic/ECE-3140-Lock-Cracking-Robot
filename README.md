## Your Project Answers

### Project Description

We intend on creating an automatic plant-watering system. This system will employ a small array of sensors that will take measurements of environmental factors - namely soil moisture, humidity, temperature, and the ambient light level. Once the values have been collected, the microcontroller will drive a peristaltic pump (via a load switch) to water the plant if certain thresholds and conditions have been met. 

Furthermore, we will create a small array of LEDs to display the relative values of the data measurements. For example, each of the four data types will have a set of 3 LEDs: one LED turned on means low, two means medium, and three corresponds to high. Furthermore, we will repurpose a moisture sensor to measure whether any water is left in the tank: when the water for the pump runs dry, the sensor will no longer be moist and hence its readings will be low. When this repurposed moisture sensor indicates a low measurement, we will turn on a single LED to warn the user to fill up the water tank. 

Lastly, we will 3D print a nested pot to contain the plant itself as well as the water tank (for the pump). This 3D-printed structure will also contain mounting brackets for the battery packs (that will power the KL46z and 12V DC motor), microcontroller, and breadboard (which will contain the array of sensors and current limiting resistors). 
### Technical Approach

We have already completed a working version of the project.

The sensors we utilized were the following: AHT20 (temperature and humidity), two STEMMA soil moisture sensors (from Adafruit), and lastly a VEML 7700 (which measures light in units of lux). All of the aforementioned sensors operate over the I2C communication protocol. These sensors have been wired up on a single breadboard. Standard female Dupont headers were soldered onto a board to provide easy interfacing with the breadboard. 

Regarding the motor, a small peristaltic and about 3 meters of tubing was purchased. Aidan soldered on a flyback diode to the motor to prevent damage caused by back-EMF (basically, to protect against a rush of current into the microcontroller due to the "discharging" of the inductor/motor). Furthermore, Jon hooked up a power MOSFET that acts as a load switch between the MCU and the motor since the MCU cannot directly drive the motor due to current and voltage limitations. 

During Spring break, Jon, with help from Andrew and mixed-domain oscilloscope (with a built-in logic analyzer), successfully programmed a I2C library to communicate with all three sensors. To sample the data every second, PIT interrupts were utilized. When certain threshold values were reached (up to the user and the nature of the selected plant), a GPIO pin was driven high so as to turn on the load switch, allowing the motor to draw water from a reservoir and hence actually water the plant.

Regarding future work, we have yet to complete the 3D-printed structure and the array of LEDs. However, implementing the array of LEDs will be quite straight forward: we will configure and enable more GPIO pins and drive them high when the threshold values are met (whilst remembering to use current limiting resistors to prevent damage to the MCU). 
We have already completed a working version of the project.

The sensors we utilized were the following: AHT20 (temperature and humidity), two STEMMA soil moisture sensors (from Adafruit), and lastly a VEML 7700 (which measures light in units of lux). All of the aforementioned sensors operate over the I2C communication protocol. These sensors have been wired up on a single breadboard. Standard female Dupont headers were soldered onto a board to provide easy interfacing with the breadboard. 

Regarding the motor, a small peristaltic and about 3 meters of tubing was purchased. Aidan soldered on a flyback diode to the motor to prevent damage caused by back-EMF (basically, to protect against a rush of current into the microcontroller due to the "discharging" of the inductor/motor). Furthermore, Jon hooked up a power MOSFET that acts as a load switch between the MCU and the motor since the MCU cannot directly drive the motor due to current and voltage limitations. 

During Spring break, Jon, with help from Andrew and mixed-domain oscilloscope (with a built-in logic analyzer), successfully programmed a I2C library to communicate with all three sensors. To sample the data every second, PIT interrupts were utilized. When certain threshold values were reached (up to the user and the nature of the selected plant), a GPIO pin was driven high so as to turn on the load switch, allowing the motor to draw water from a reservoir and hence actually water the plant.

Regarding future work, we have yet to complete the 3D-printed structure and the array of LEDs. However, implementing the array of LEDs will be quite straight forward: we will configure and enable more GPIO pins and drive them high when the threshold values are met (whilst remembering to use current limiting resistors to prevent damage to the MCU). 

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/acm289-akc55-jzh8" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/acm289-akc55-jzh8" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.