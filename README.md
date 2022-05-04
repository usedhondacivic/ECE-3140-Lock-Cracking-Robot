## Your Project Answers

### Project Description

We plan to make a sort of reflex-based game, in which a player is given an array of buttons and corresponding LEDs, and must hit a button when its respective LED lights up. A player fails when they aren't able to hit the button in time. The speed of LED lights will increase as the game goes on, as to make the game more challenging.

We plan to track score in one of a few ways, with ideas including time until failure (maybe with a set number of lives), number of failures within a given time frame, total reflex lateness (sum of time between LED lightup and button press), or some measure of 'stages' of different LED speeds. At the end of the game, score will be displayed, either using the onboard LED to display numbers in either number of flashes or morse code, or the onboard 4-digit display.

If we are able to implement this in time, we are also considering expanding this into a multiplayer version of the game, in which players can compete head-to-head with the first player to fail/lose their lives losing the match.

 
### Technical Approach

The only peripherals we anticipate needing are the buttons and LEDs arranged in an external array, using a breadboard or other type of external board that can hold the necessary circuits for displaying information to and getting inputs from the player.

The game logic will clearly make heavy use of interrupts, as each button acts as an external input and the game relies entirely on timing. Onboard clocks such as the PIT will be used to regulate LED triggers and the increasing speed of the game. I/O concepts will also be clearly used for the board to interface with our external lights and buttons.
The only peripherals we anticipate needing are the buttons and LEDs arranged in an external array, using a breadboard or other type of external board that can hold the necessary circuits for displaying information to and getting inputs from the player.

The game logic will clearly make heavy use of interrupts, as each button acts as an external input and the game relies entirely on timing. Onboard clocks such as the PIT will be used to regulate LED triggers and the increasing speed of the game. I/O concepts will also be clearly used for the board to interface with our external lights and buttons.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/ja598-jjn48 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/ja598-jjn48 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.