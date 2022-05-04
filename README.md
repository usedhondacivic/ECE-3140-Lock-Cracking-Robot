## Your Project Answers

### Project Description

From a high level, we would like to recreate the game "Heads Up!" (popularized by Ellen). In this game, a user hold usually holds a phone, showing a name of something, on their forehead and the other player describes what it is to them. When they guess it correctly, they tilt the phone down the go to the next word. If they want to skip a word, they tilt the phone up. After a set period of time finishes, the player's score is the number they correctly guessed. We would like to implement this with our board and a computer. The board will act as the phone, but will only be used to tilt up and down. The computer will display the current word, the timer, and the current score.

 

Tutorial: https://www.youtube.com/watch?v=yruo5DhD-y4
### Technical Approach

We will enable the tilt control on ther board as an I/O and poll it to see how much the board has rotated. We can track the board's y-axis tilt to see if it has been tilted upwards (for a skip), downwards (for a correct answer), or not at all (for nothing). Additionally, we can use the x-axis tilt as a controller to possibly switch to different difficulty questions or categories before a game starts. We might also implement the red LED as a GPIO to blink quickly if the timer is counting down and the player is running out of time. Lastly, we plan to use these inputs as controls to a python program, which will be used to display and keep track of the words, timer, and score on the computer display. 
We will enable the tilt control on ther board as an I/O and poll it to see how much the board has rotated. We can track the board's y-axis tilt to see if it has been tilted upwards (for a skip), downwards (for a correct answer), or not at all (for nothing). Additionally, we can use the x-axis tilt as a controller to possibly switch to different difficulty questions or categories before a game starts. We might also implement the red LED as a GPIO to blink quickly if the timer is counting down and the player is running out of time. Lastly, we plan to use these inputs as controls to a python program, which will be used to display and keep track of the words, timer, and score on the computer display. 

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/ceh256-cjc353-psp43" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/ceh256-cjc353-psp43" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.