## Your Project Answers

### Project Description

We were thinking about creating a reaction time game using only the given board. This would work by flashing one LED while simultaneously starting a timer. Then, the player would have to press a button as quickly as possible after this light goes off. Then, the timer would be stopped and it would be read out, potentially via morse code using the other LED. 
### Technical Approach

We were not planning on using any peripherals, as we think this project can be done just using the given board, as it only requires used of a timer, an LED, and a button. To use a timer, we would implement what we've done for lab 5 in order to keep track of current time. This would involving using a similar interrupt and interrupt handler. We would also have to figure out a way to use one of the buttons on the board in order to halt the timer once the player presses it after the LED goes off. For this, we could check for the button being pressed within the handler in order to stop the clock. We could also check for button presses before the LED goes off, which would result in a fault. This could be done via another interrupt potentially or polling. Lastly, we could reuse parts from lab1 in order to implement morse code for the timer readout once the player presses the button.
We were not planning on using any peripherals, as we think this project can be done just using the given board, as it only requires used of a timer, an LED, and a button. To use a timer, we would implement what we've done for lab 5 in order to keep track of current time. This would involving using a similar interrupt and interrupt handler. We would also have to figure out a way to use one of the buttons on the board in order to halt the timer once the player presses it after the LED goes off. For this, we could check for the button being pressed within the handler in order to stop the clock. We could also check for button presses before the LED goes off, which would result in a fault. This could be done via another interrupt potentially or polling. Lastly, we could reuse parts from lab1 in order to implement morse code for the timer readout once the player presses the button.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/cea57-rak277-sh823" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/cea57-rak277-sh823" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.