## Your Project Answers

### Project Description

I would like to make a driving game similar to crazy taxi. I'll have a 3 lane road, and doing an action on the board will change lanes (probably pressing the buttons, but maybe the touch slider). The road will have potholes that you need to avoid by switching lanes. When you hit a pothole, the game is over. I'll also make a pause action on the board, probably with the touch slider. When you beat a level, the green LED will flash 3 times. When you hit a pothole, the red LED will flash 3 times then stay on. When resuming from a pause or when starting a new game, both LEDs will flash 3 times (for a countdown) then the game will begin. When you are actively playing or haven't yet resumed/started the game, both LEDs will remain off. The speed of the game will increase with each level.
### Technical Approach

I don't plan to use any additional hardware other than the board for this project. I plan to use the SW1 and SW3 buttons to switch lanes, the touch slider to start/pause/unpause the game, and the LEDs on the board. I will write a gui in python for this game. I plan to use UART and pySerial to communicate between the board and the programs. I plan to use interrupts for when the buttons are pressed or when there is an interaction with the touch slider.
I don't plan to use any additional hardware other than the board for this project. I plan to use the SW1 and SW3 buttons to switch lanes, the touch slider to start/pause/unpause the game, and the LEDs on the board. I will write a gui in python for this game. I plan to use UART and pySerial to communicate between the board and the programs. I plan to use interrupts for when the buttons are pressed or when there is an interaction with the touch slider.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/agh93" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/agh93" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.