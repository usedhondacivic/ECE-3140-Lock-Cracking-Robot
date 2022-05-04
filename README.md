## Your Project Answers

### Project Description

Smart Lock Project Proposal

For our final project, we intend to create a “smart” lock. Utilizing the NXP kl46z board, we will create a lock that utilizes two-factor authentication. The board will be connected to a keypad, in which a user will be able to input a combination. If a correct combination is inputted, the board will show a timer that counts down 5 seconds so that the user will know when their picture is taken. To take a picture, the onboard camera on the ESP32 board will be utilized. Due to the networking ability of the ESP32, utilizing the SMTP library, an email will be sent to the user with the picture taken by the esp, along with the ESP32's IP address. Utilizing a simple app, the user will be able to unlock the lock remotely. The app will prompt the user to provide an IP address. Utilizing the inputted IP, the app creates a WebSocket connection with the ESP32 and signals to lock or unlock the door. If the ESP32 receives authorization, a simple digital pin will be written to signal to the kl46z board to unlock the door. Then, the kl46z board will lift a deadbolt using a servo motor. 

 
### Technical Approach

NXP KL46Z Board

 

First, we will be utilizing the NXP FRDM-kl46z board used throughout this class. We will be including different concepts that we learned through our labs that including concurrency and blocking processes. Our board will be used as a facilitator of information to and from the different components used in our project. In effect, we are building a state machine to control the lock. If the keypad input is correct, the board will make a state transition to trigger a 5-second countdown and take a picture. The board will signal to the ESP32 to take a picture. The state transition to lift the deadbolt will occur only when the ESP32 signals to do so. 

 

ESP32-WROVER Board

 

ESP32-WROVER is a Wi-Fi and Bluetooth adaptable MCU module that fits our needs perfectly, including anything from low-power sensor networks to a built-in camera. The ESP32 is a microcontroller with both Wifi and Bluetooth capabilities. Crucially, the board we ordered has an onboard 2 MP camera as well. With the onboard wifi, we will be able to send an email with an image attached. In this email, we will also attach the IP of the ESP32. Using an app we created, we will control the ESP32 by controlling it over a WebSocket. When the owner indicates to unlock the door in the app, the ESP32 should receive a signal over the WebSocket. It then sends a signal to our main board depending on whether the request has 

been approved or not.

 

Initially, we had hoped to use lwip, along with an ethernet peripheral device, to network our board. Unfortunately, as we began trying to implement this idea, we realized that it would not be possible to complete by the end of the semester. The reason for this is that while in theory, OSI layers are independent of each other, in practice, on our board, this is not the case. Usually, lwip is run on board with Ethernet, to enable physical layer communication. As our board does not have this, it would be extremely difficult to implement. While it is possible, by sending ethernet packets over USB, it would take far too long to program in the amount of time we have. Thus, for our system, we will utilize the ESP32. 

 

DIYmalls 4x4 Keypad

 

This keypad will be programmed through our board to be true if the correct password is inputted and false if the password is incorrect. We chose this because it is easy to program and it has built-in capabilities to communicate with the microcontroller. When the board receives a correct input sequence, it should immediately start counting down 5 seconds and simultaneously communicate to the ESP32. This keypad is essentially the input of our smart lock. Without the correct combination, nothing should happen because the board will not be communicating with our ESP32 at all.

 

Linear Servo Motor

While we do not know what exact model we’ll be using, a low-power and low-current servo motor are ideal. This is because our other components can only take in so much voltage and current. The reason we chose a linear servo is that it is also easy to program. All we need to tell it to do is to retract and extend depending on whether the request to unlock is approved or not. This will be programmed through our mainboard where it only retracts the motor when a signal to unlock comes from the ESP32. This motor is essentially our output. It will not move at all if either one of the two-factor authentication fails. Only a specific process will make it retract. It should extend back after 5 seconds of it being retracted.

 

Software/Coding

 

Networking: To network our board, we will utilize the WiFi capabilities of the ESP32. To send an email, we will use the ESP32_MailClient library, which will allow us to send an email with an image attachment. To take a picture, we will utilize the API provided by the board manufacturer. Our app is a simple JavaScript program(running in DroidScript) that prompts the user to provide an IP address, used to establish a WebSocket with the ESP32. The app has two buttons, one to approve and one to deny, a request from the ESP32. When a button is clicked, the app opens a socket connection with the ESP32 and sends a command.

 

Controlling Motor: By directly using the NXP kl46z, we will make the linear servo retract fully using basic code programmed into the databanks of microcontrollers. We will extend it immediately after it is done.

LCD: A demo from NXP kl46z SDK was modified, to allow us to create a timer to countdown from 5 to 0. A small library was written to enable the use of the LCD for our needs.

Keypad: We have a matrix-style keypad. We will have to write a lightweight library to process input from the keypad. 

 

Constructs from ECE 3140:

Concurrency: We will implement our state transitions using interrupt handlers. Thus, when a state transition occurs, our interrupt handler will rapidly take care of it.

Locks: We will utilize locks, and a delay, to ensure that only one key on our keypad can be pressed and read at once.

Blocking Locks: We will ensure that the motor is not overwhelmed due to a continuous approval of requests to unlock.

 

 

Testing

 

We must do a lot of testing in order for this project to be successful. Before anything, we must test whether the keypad connected to the board works. The first test to perform is to make the board’s LCD begins the countdown sequence if the correct password is inputted. Next, we must test the communication between the ESP32 and the NXP KL46Z. We should give input to the ESP32, and if true is received by the ESP32, it should send a signal back to the NXP KL46Z for it to blink an LED. This will be our second test(but will not be in the final system). Our third test is the communication of the NXP KL46Z and the camera on the ESP32. Once the timer counts down 5 seconds, the camera should take a picture and send it by email to our user. This will be the hardest to do because we will not know if the camera has successfully taken a picture unless we see the email in our inbox. After this, the fourth test should be our server communicating to the ESP32 over the WebSocket. We will then have to test that ESP32 correctly signals to our NXP KL46Z. Successful communication will be signaled with a LED blink. Finally, we will test the NXP KL46Z and the linear servo motor independently to see if we can retract and extend with a simple true or false statement. Each of these tests must be done independently of each other before we can combine them. Once we combine them, we will run a case where the entire two-factor authentication is correct, a case where the keypad fails, and a case where the request to unlock is denied. These test cases will serve to prove that our smart lock works perfectly.

 
NXP KL46Z Board

 

First, we will be utilizing the NXP FRDM-kl46z board used throughout this class. We will be including different concepts that we learned through our labs that including concurrency and blocking processes. Our board will be used as a facilitator of information to and from the different components used in our project. In effect, we are building a state machine to control the lock. If the keypad input is correct, the board will make a state transition to trigger a 5-second countdown and take a picture. The board will signal to the ESP32 to take a picture. The state transition to lift the deadbolt will occur only when the ESP32 signals to do so. 

 

ESP32-WROVER Board

 

ESP32-WROVER is a Wi-Fi and Bluetooth adaptable MCU module that fits our needs perfectly, including anything from low-power sensor networks to a built-in camera. The ESP32 is a microcontroller with both Wifi and Bluetooth capabilities. Crucially, the board we ordered has an onboard 2 MP camera as well. With the onboard wifi, we will be able to send an email with an image attached. In this email, we will also attach the IP of the ESP32. Using an app we created, we will control the ESP32 by controlling it over a WebSocket. When the owner indicates to unlock the door in the app, the ESP32 should receive a signal over the WebSocket. It then sends a signal to our main board depending on whether the request has 

been approved or not.

 

Initially, we had hoped to use lwip, along with an ethernet peripheral device, to network our board. Unfortunately, as we began trying to implement this idea, we realized that it would not be possible to complete by the end of the semester. The reason for this is that while in theory, OSI layers are independent of each other, in practice, on our board, this is not the case. Usually, lwip is run on board with Ethernet, to enable physical layer communication. As our board does not have this, it would be extremely difficult to implement. While it is possible, by sending ethernet packets over USB, it would take far too long to program in the amount of time we have. Thus, for our system, we will utilize the ESP32. 

 

DIYmalls 4x4 Keypad

 

This keypad will be programmed through our board to be true if the correct password is inputted and false if the password is incorrect. We chose this because it is easy to program and it has built-in capabilities to communicate with the microcontroller. When the board receives a correct input sequence, it should immediately start counting down 5 seconds and simultaneously communicate to the ESP32. This keypad is essentially the input of our smart lock. Without the correct combination, nothing should happen because the board will not be communicating with our ESP32 at all.

 

Linear Servo Motor

While we do not know what exact model we’ll be using, a low-power and low-current servo motor are ideal. This is because our other components can only take in so much voltage and current. The reason we chose a linear servo is that it is also easy to program. All we need to tell it to do is to retract and extend depending on whether the request to unlock is approved or not. This will be programmed through our mainboard where it only retracts the motor when a signal to unlock comes from the ESP32. This motor is essentially our output. It will not move at all if either one of the two-factor authentication fails. Only a specific process will make it retract. It should extend back after 5 seconds of it being retracted.

 

Software/Coding

 

Networking: To network our board, we will utilize the WiFi capabilities of the ESP32. To send an email, we will use the ESP32_MailClient library, which will allow us to send an email with an image attachment. To take a picture, we will utilize the API provided by the board manufacturer. Our app is a simple JavaScript program(running in DroidScript) that prompts the user to provide an IP address, used to establish a WebSocket with the ESP32. The app has two buttons, one to approve and one to deny, a request from the ESP32. When a button is clicked, the app opens a socket connection with the ESP32 and sends a command.

 

Controlling Motor: By directly using the NXP kl46z, we will make the linear servo retract fully using basic code programmed into the databanks of microcontrollers. We will extend it immediately after it is done.

LCD: A demo from NXP kl46z SDK was modified, to allow us to create a timer to countdown from 5 to 0. A small library was written to enable the use of the LCD for our needs.

Keypad: We have a matrix-style keypad. We will have to write a lightweight library to process input from the keypad. 

 

Constructs from ECE 3140:

Concurrency: We will implement our state transitions using interrupt handlers. Thus, when a state transition occurs, our interrupt handler will rapidly take care of it.

Locks: We will utilize locks, and a delay, to ensure that only one key on our keypad can be pressed and read at once.

Blocking Locks: We will ensure that the motor is not overwhelmed due to a continuous approval of requests to unlock.

 

 

Testing

 

We must do a lot of testing in order for this project to be successful. Before anything, we must test whether the keypad connected to the board works. The first test to perform is to make the board’s LCD begins the countdown sequence if the correct password is inputted. Next, we must test the communication between the ESP32 and the NXP KL46Z. We should give input to the ESP32, and if true is received by the ESP32, it should send a signal back to the NXP KL46Z for it to blink an LED. This will be our second test(but will not be in the final system). Our third test is the communication of the NXP KL46Z and the camera on the ESP32. Once the timer counts down 5 seconds, the camera should take a picture and send it by email to our user. This will be the hardest to do because we will not know if the camera has successfully taken a picture unless we see the email in our inbox. After this, the fourth test should be our server communicating to the ESP32 over the WebSocket. We will then have to test that ESP32 correctly signals to our NXP KL46Z. Successful communication will be signaled with a LED blink. Finally, we will test the NXP KL46Z and the linear servo motor independently to see if we can retract and extend with a simple true or false statement. Each of these tests must be done independently of each other before we can combine them. Once we combine them, we will run a case where the entire two-factor authentication is correct, a case where the keypad fails, and a case where the request to unlock is denied. These test cases will serve to prove that our smart lock works perfectly.

 

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/alk246-dk844 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/alk246-dk844 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.