## Your Project Answers

### Project Description

Our project is that of an addition to a conventional windowed air conditioning system that should allow it to regulate the temperature in the room. The project will consist of a 3D printed housing that will hold a servo motor and gear system to spin the knob on the air conditioning unit. That will be controlled by reading a temperature sensor from the gpio pins. The buttons on the board will be used to increase and decrease the set temperature. The main concern with this project is that the small motor we have is not going to have enough torque to turn the knob. In that case we will still make the same design, but we will simply note that we are unable to actually turn the knob. In that case the system will serve more of a “proof of concept” role.

One potential expansion for this project is to use the LCD screen to indicate the set temperature, or we could use the LEDs to indicate some status about the temperature relative to the set. This depends on the complexity of implementing the aforementioned section.

The project demonstrates use of input and output pins on the board. As well, we can use either polling or interrupts to read the input sensor and perform respective actions. This also couples with our ability to conduct simple mechanical design and CAD. I think it represents a satisfactory culmination of our engineering abilities.
### Technical Approach

We plan on using a servo motor that we already have, a temperature sensor that we may have (we may also be able to take one from an on campus lab as they only cost a few cents), and our board.

We will use the gpio pins mostly.

The software will basically run as follows:

Measure the temperature every few minutes.

if(tempMeasured < tempSet-1) - turn ac down by moving servo; display red led

 else if(tempMeasured > tempSet+1) - turn ac up by moving servo ; display red led

else display green led

Use interrupts to allow button presses to change the set temp at any point

 

potentially run the screen to display the set temperature number. [see previous question]

The project demonstrates use of input and output pins on the board. As well, we can use either polling or interrupts to read the input sensor and perform respective actions. This also couples with our ability to conduct simple mechanical design and CAD. I think it represents a satisfactory culmination of our engineering abilities.
We plan on using a servo motor that we already have, a temperature sensor that we may have (we may also be able to take one from an on campus lab as they only cost a few cents), and our board.

We will use the gpio pins mostly.

The software will basically run as follows:

Measure the temperature every few minutes.

if(tempMeasured < tempSet-1) - turn ac down by moving servo; display red led

 else if(tempMeasured > tempSet+1) - turn ac up by moving servo ; display red led

else display green led

Use interrupts to allow button presses to change the set temp at any point

 

potentially run the screen to display the set temperature number. [see previous question]

The project demonstrates use of input and output pins on the board. As well, we can use either polling or interrupts to read the input sensor and perform respective actions. This also couples with our ability to conduct simple mechanical design and CAD. I think it represents a satisfactory culmination of our engineering abilities.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/emg229-ocl6 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/emg229-ocl6 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.