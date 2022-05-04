## Your Project Answers

### Project Description

We want to make a timer based switch system to implement power saving timeout after user inactivity. Our system will sense when the lights are off and initialize a timer that will go until a specified timeout limit and request user input of whether to turn off our system or keep it on. If they decide to keep it on, the timer will reset, but if a user does not respond within a certain time limit, the system will automatically turn off. At this point the user will have to reset the system to turn it on again.
### Technical Approach

We will use both the PIT timers, the ambient light sensor, both LEDs, both user switches, and possibly an external peripheral to control with our remote. We will be using interrupts, real time scheduling, and controlling different ports on the board.
We will use both the PIT timers, the ambient light sensor, both LEDs, both user switches, and possibly an external peripheral to control with our remote. We will be using interrupts, real time scheduling, and controlling different ports on the board.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/jar595-ssc256 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/jar595-ssc256 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.