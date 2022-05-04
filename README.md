## Your Project Answers

### Project Description

We will be building a chess clock with four buttons, a switch, and a pair of four digit seven-segment displays. Each timer within the chess clock is set at the start of the game which counts down from a specified time. The play button starts the left-most timer, the switch alternates which timer is decrementing, a reset button which sets the timers to 0, and two buttons for incrementing and decrementing before the play button is pressed.
### Technical Approach

To implement this, we will create a real time clock that changes after an interrupt is called every second. Only one seven-segment display will decrement at a time, and it will be updated by a timer-struct that has seconds, deciseconds, minutes and deciminutes. This timer-struct and the display will be updated within the same interrupt. Currently, we are planning on having reset, play, update_display, switch_clock functions. There would be two different states, one for before the game starts and one for during the game. 
To implement this, we will create a real time clock that changes after an interrupt is called every second. Only one seven-segment display will decrement at a time, and it will be updated by a timer-struct that has seconds, deciseconds, minutes and deciminutes. This timer-struct and the display will be updated within the same interrupt. Currently, we are planning on having reset, play, update_display, switch_clock functions. There would be two different states, one for before the game starts and one for during the game. 

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/dtv25-ens57-jwt95" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/dtv25-ens57-jwt95" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.