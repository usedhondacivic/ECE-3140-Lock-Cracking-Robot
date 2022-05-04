## Your Project Answers

### Project Description

    We are going to use two boards to control an RC car. The car will be composed of one microcontroller, two servos, and a battery bank. If needed, we may switch from the servos to the motors and driver instead. The other microcontroller will be controlling the speed and direction. This will be done through the accelerometer, tilting of the other board, and a transmitter/receiver unit. For example, tilting it forwards would cause the car to move forward and with more tilt would be more speed. Tilting to the right or left would cause the car to change direction to right or left. One of the buttons on the board will also be used to toggle the microcontroller functions; so if it is toggled off, no matter the tilt, the RC car will not move.
### Technical Approach

    For boards a separate set of features are going to be needed. For the controller being used to drive the controller the accelerometer (MMA8451Q) on the board will be used to capture the users intended inputs. Tilting the board forward and backwards will correspond to forward/backwards motion and left/right will correspond to turning. The button (SW1) will also toggle on/off the control from the board. This board will have an SPI connection to a nRF24L01 which will be used as a transmitter.

    For the board on the robot it will have another nRF24L01 operating as a receiver and connected to the SPI pins on the board. These signals will be processed and used to generate 2 PWM signals (one for each wheel) using the TMP (Timer/PWM module) module on the board. The PWM signals will be sent to two continuous rotation servos which are attached to each of the wheels. The car unit will be powered by either a USB power bank or AA batteries (via battery holder).
    For boards a separate set of features are going to be needed. For the controller being used to drive the controller the accelerometer (MMA8451Q) on the board will be used to capture the users intended inputs. Tilting the board forward and backwards will correspond to forward/backwards motion and left/right will correspond to turning. The button (SW1) will also toggle on/off the control from the board. This board will have an SPI connection to a nRF24L01 which will be used as a transmitter.

    For the board on the robot it will have another nRF24L01 operating as a receiver and connected to the SPI pins on the board. These signals will be processed and used to generate 2 PWM signals (one for each wheel) using the TMP (Timer/PWM module) module on the board. The PWM signals will be sent to two continuous rotation servos which are attached to each of the wheels. The car unit will be powered by either a USB power bank or AA batteries (via battery holder).

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/keb282-zen3 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/keb282-zen3 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.