## Your Project Answers

### Project Description

I want to build a combination lock cracker. It will take any standard master lock combination lock and automatically and efficiently run through combinations to open the lock. Master locks are notoriously easy to crack, and it is possible for a human to brute force one in around 3 minutes. I am targeting under a minute to crack the lock, but hoping to go as low as 30 seconds. 
### Technical Approach

It will use a stepper motor to manipulate the dial and a servo motor to pull on the shackle. I will 3d print the mechanical parts and the motors will be controlled by the board. I already have the stepper driver / battery needed for the project. The stepper driver uses a fairly simple control scheme that should be easy to write a driver for. The servo is driven using PWM, for which a controller is built into the chip.

 
It will use a stepper motor to manipulate the dial and a servo motor to pull on the shackle. I will 3d print the mechanical parts and the motors will be controlled by the board. I already have the stepper driver / battery needed for the project. The stepper driver uses a fairly simple control scheme that should be easy to write a driver for. The servo is driven using PWM, for which a controller is built into the chip.

 

## Feedback.
This is a great idea! I think your goal of finding the combination in under a minute is doable, however the system as a whole might be a little complicated for how much time you have. I would recommend tinking of ways to simplify for that sake of time, for example only using one motor and having the user pull on the shackle. If you already feel fairly comfortable with the hardware and 3D printing it is a doable project, just don't get too caught up on the hardware. Make sure you spend some time thinking about all the requirements of the system and ensuring that they are not too complicated.
## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/mmc323 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/mmc323 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.
