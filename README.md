## Your Project Answers

### Project Description

We want to make a playable game that will use the freedom development board as inputs, and will use serial communication with a computer to incorporate the inputs into the game. The game will be based on doodlejump, so we will be tracking the rotational position of the board and using it to update the character's position. 
### Technical Approach

We plan on using the on-board accelerometer to collect positional data, which will be sent to a C program using the I2C interface. We can forward the data to a program running on a computer using the UART interface. The game will be programmed in python and displayed using a GUI library (pygame), and data will be sent back to the board using the pyserial package. We can use the onboard switches to control the state of the game (start/restart) and the onboard LEDs via GPIO to indicate the status of the game (win/lose).
We plan on using the on-board accelerometer to collect positional data, which will be sent to a C program using the I2C interface. We can forward the data to a program running on a computer using the UART interface. The game will be programmed in python and displayed using a GUI library (pygame), and data will be sent back to the board using the pyserial package. We can use the onboard switches to control the state of the game (start/restart) and the onboard LEDs via GPIO to indicate the status of the game (win/lose).

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/crm332-kz227 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/crm332-kz227 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.