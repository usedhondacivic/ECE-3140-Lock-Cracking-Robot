## Your Project Answers

### Project Description

We plan on creating a theremin-like instrument that plays a certain note depending on where the player’s hand is. We have an ultrasonic sensor that determines how far away a solid object is from the sensor. Depending on how far away the object is, the speaker will play a sound of a certain frequency. The closer the object is, the higher the frequency is. We will use a piezo buzzer that acts as a small speaker. 
### Technical Approach

We will use an ultrasonic sensor, which is a central part of the project. The sensor will determine the note to be played. We will have a piezo buzzer that generates sound waves. This acts as a speaker. We will have a level shifter that converts from 3.3 V to 5 V. Lastly, we will use the freedom development board given to us for this class. 

 

To get distance measurements from the ultrasonic sensor, two GPIO pins will be used to trigger the sensor and to receive the echo signal. The sensor uses a microsecond delay to measure distances, so a PIT timer will be used to create a microsecond delay by polling the timer. 

To create the notes on the buzzer, the distance calculated from the sensor will be quantized into integers. Then, using the formula for 12 tone temperament, we can calculate the period of the sound signal needed to play the correct note. Then, to play this note, a PWM signal is sent through a GPIO pin with the period calculated from the 12 tone temperament formula using the SDK example.
We will use an ultrasonic sensor, which is a central part of the project. The sensor will determine the note to be played. We will have a piezo buzzer that generates sound waves. This acts as a speaker. We will have a level shifter that converts from 3.3 V to 5 V. Lastly, we will use the freedom development board given to us for this class. 

 

To get distance measurements from the ultrasonic sensor, two GPIO pins will be used to trigger the sensor and to receive the echo signal. The sensor uses a microsecond delay to measure distances, so a PIT timer will be used to create a microsecond delay by polling the timer. 

To create the notes on the buzzer, the distance calculated from the sensor will be quantized into integers. Then, using the formula for 12 tone temperament, we can calculate the period of the sound signal needed to play the correct note. Then, to play this note, a PWM signal is sent through a GPIO pin with the period calculated from the 12 tone temperament formula using the SDK example.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/jm2385-jwf224-ljk74 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/jm2385-jwf224-ljk74 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.