## Your Project Answers

### Project Description

We would like to build a pedometer which would track the number of steps taken and display them on the board's number display. It would also be able to tell if you are walking or running; during walking, the red LED would light up, and during running, the green LED would light up instead. During no activity, there'd be no light.
### Technical Approach

We are planning to use the accelerometer to detect steps, and interrupts to add to the step counter whenever one is detected. The step counter can then be displayed in decimal on the board's number display. By fine-tuning the code used to detect the steps, which will likely be a periodic real-time process, we can also split the steps into two categories: walking and running. Simple global variables (perhaps is_running and is_walking) can then be used to turn on different LEDs.
We are planning to use the accelerometer to detect steps, and interrupts to add to the step counter whenever one is detected. The step counter can then be displayed in decimal on the board's number display. By fine-tuning the code used to detect the steps, which will likely be a periodic real-time process, we can also split the steps into two categories: walking and running. Simple global variables (perhaps is_running and is_walking) can then be used to turn on different LEDs.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/mlg297-zdh5 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/mlg297-zdh5 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.