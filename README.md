## Your Project Answers

### Project Description

Our final project will be Squid Game. This will involve three stages of games inspired by the popular Netflix show Squid Game. Our first game is Red Light, Green Light. The objective of the game is to reach the goal before the time runs out while watching for the red light to turn on. When the green LED is on, the player can run with the board, which will add distance. However, if we detect any movements when the red LED blinks, then the player loses. Our second game will be Dalgona game, where the player needs to carve out a shape out of the honeycomb candy. We will use some modifications to simulate the game. When the green light blinks, the player needs to slide left on the touch slider, and the same for the red light and right direction. If the player successfully follows the instructions, they win this round. Our last game will be glass bridge - a game of chance. In the original TV series, players attempt to cross two parallel bridges made of glass by jumping across tempered glass panels while avoiding weaker panes of regular glass. Those who landed on a regular glass panel broke through the pane and fell to their deaths from a high place, resulting in their elimination from the game. To recreate the game, we will have two buttons to represent the two bridges. Players will have a 50/50 chance to press the correct (tempered glass) button. There will be three rounds. If they press the wrong button, the player loses. If they successfully press the right button three times, the player has won the Squid Game.
### Technical Approach

Default board orientation will be with the capacitive touch slider on top.

Left button/side is SW1 and right button/side is SW3.

We plan on using no peripherals other than an external power source (probably external battery bank) to enable the user to run for one of the minigames.

* Red Light Green Light

* We plan on using the red and green LEDs to signal to the player when they can start running and when they need to stop. Movement will be tracked using the onboard accelerometer. When the red light is on, we use interrupts and get the current value from the accelerometer. If it’s bigger than the threshold value we chose, the player loses. Also, we accumulate the values from the accelerometer, and once it adds up to the goal, the player wins. 

* Dalgona

* We are simplifying the original game from the TV series to instead of having to trace out a shape to just having to follow a jagged line.

* The jagged line will be conveyed to the user the green and red LEDs signaling left and right to which they’ll respond with by moving their finger on the capacitive touch slider.

* If they successfully follow the directions and trace the line out, then the green LED will stay solid, if they fail, the red LED will stay solid.

* Glass Stepping Stones

* Our final game is a game of chance. Much like the original show’s glass stepping stones, the player will have to choose to go left or right by clicking the respective buttons and taking it up with fate. We will choose the “safe” stone before each round by taking the current time. If the current time is even, we use 0, and if it’s odd we use 1. Once a player presses a button, we will take the input signal (0 for left and 1 for right) and compare that with the pre-selected choice. Each successful choice will be signified by the green LED. Death will be signified by the red LED.
Default board orientation will be with the capacitive touch slider on top.

Left button/side is SW1 and right button/side is SW3.

We plan on using no peripherals other than an external power source (probably external battery bank) to enable the user to run for one of the minigames.

* Red Light Green Light

* We plan on using the red and green LEDs to signal to the player when they can start running and when they need to stop. Movement will be tracked using the onboard accelerometer. When the red light is on, we use interrupts and get the current value from the accelerometer. If it’s bigger than the threshold value we chose, the player loses. Also, we accumulate the values from the accelerometer, and once it adds up to the goal, the player wins. 

* Dalgona

* We are simplifying the original game from the TV series to instead of having to trace out a shape to just having to follow a jagged line.

* The jagged line will be conveyed to the user the green and red LEDs signaling left and right to which they’ll respond with by moving their finger on the capacitive touch slider.

* If they successfully follow the directions and trace the line out, then the green LED will stay solid, if they fail, the red LED will stay solid.

* Glass Stepping Stones

* Our final game is a game of chance. Much like the original show’s glass stepping stones, the player will have to choose to go left or right by clicking the respective buttons and taking it up with fate. We will choose the “safe” stone before each round by taking the current time. If the current time is even, we use 0, and if it’s odd we use 1. Once a player presses a button, we will take the input signal (0 for left and 1 for right) and compare that with the pre-selected choice. Each successful choice will be signified by the green LED. Death will be signified by the red LED.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/jcg294-nyc9-sj598" then the GitHub page is at "https://pages.github.coecis.cornell.edu/ece3140-sp22/jcg294-nyc9-sj598" You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.