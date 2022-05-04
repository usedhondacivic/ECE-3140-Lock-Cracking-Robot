## Your Project Answers

### Project Description

Our project idea is a pong controller. We plan to utilize the onboard capacitive touch sensor to control pong played on the computer. We are thinking of having two modes, breakout mode and regular mode which can be toggled between with the onboard buttons. We can distinguish which mode is currently active with the LEDs on the controller.

The board will communicate with a driver over UART. In breakout mode, the touch sensor will essentially be used to control the horizontal motion of the computer's cursor and in regular mode, it will control the veritcal motion. This allows us to make this device support many different implementations of pong (including https://elgoog.im/breakout/ and https://playpong.net/classic  ) and not create a pong game ourselves that communicates to the controller directly. We may also add a mode that enables the controller to work with pong games that use the arrow keys such as https://pong-2.com/ .
### Technical Approach

We plan to use the onboard capactivie touch sensor, LEDs, buttons, and UART. We plan to use interrupts to detect when a touch or button press occurs. In the interrupt handler, we can queue up the event that ocurred. To avoid latency, we can use a timer interrupt to periodically check the event queue (rather then send them over UART when they occur), and if it's not empty, send the data to the computer over UART.

We plan on creating a cross-platform Rust program that will communicate with the device over UART. This program will simply interpret the messages sent from the controller, and use this information to raise the corresponding mouse/keyboard events. We will use cross-platform, freely available crates to make this part of the project simpler. C can be used instead if using other languages is not allowed.
We plan to use the onboard capactivie touch sensor, LEDs, buttons, and UART. We plan to use interrupts to detect when a touch or button press occurs. In the interrupt handler, we can queue up the event that ocurred. To avoid latency, we can use a timer interrupt to periodically check the event queue (rather then send them over UART when they occur), and if it's not empty, send the data to the computer over UART.

We plan on creating a cross-platform Rust program that will communicate with the device over UART. This program will simply interpret the messages sent from the controller, and use this information to raise the corresponding mouse/keyboard events. We will use cross-platform, freely available crates to make this part of the project simpler. C can be used instead if using other languages is not allowed.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/rs992-sev47 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/rs992-sev47 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.