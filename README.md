## Your Project Answers

### Project Description

Implement a game of red light green light using the lights on the boards with a board per player and using the accelerometer. 
### Technical Approach

We intend to use no peripherals except for multiple boards.  We intend on having the board interact and manipulate specific global variables which would indicate whether or not the light is red or green, and how many players are left in the game.  All other code such as handling blinking or polling to see if the global variable changes will be handled on each board, and one board will handling the random lengths of the red and green lights and updating them.  Because we are not using outside peripherals, the winner of the game will have to be declared using the discretion of players based on where the determined “end line” is.  However, the boards will determine if players are eliminated.  To detect if a player is eliminated, the accelerometer will be used to detect movement during the red period.  To power the boards, they will likely have to connected to laptop for each board, and to interact between boards we are currently planning on using the UART capabilities to communicate between boards.
We intend to use no peripherals except for multiple boards.  We intend on having the board interact and manipulate specific global variables which would indicate whether or not the light is red or green, and how many players are left in the game.  All other code such as handling blinking or polling to see if the global variable changes will be handled on each board, and one board will handling the random lengths of the red and green lights and updating them.  Because we are not using outside peripherals, the winner of the game will have to be declared using the discretion of players based on where the determined “end line” is.  However, the boards will determine if players are eliminated.  To detect if a player is eliminated, the accelerometer will be used to detect movement during the red period.  To power the boards, they will likely have to connected to laptop for each board, and to interact between boards we are currently planning on using the UART capabilities to communicate between boards.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/esm234-sek256-vkb29" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/esm234-sek256-vkb29" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.