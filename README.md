## Your Project Answers

### Project Description

I would like to use KL46Z as a smart home hub. I want to be able to do multiple tasks such as monitor my location inside the home to turn on/off lights, turning on the dehumidifier if a humidity threshold has been reached, turning on certain appliances at times of the day, being able to detect when I am away or not, and monitor my hamster's activity. To undertake these tasks, I will need to utilize some sensors such as a humidity sensor and location sensors, and a camera. On top of these sensors, I will need to get a module that enables communication with the sensors. 

 

As far the tasks it can do, I would like it to be able to incorporate all of my desired tasks if possible. However, I realize that development can cause some delays and I might need to account for a lack of time to finish everything. Therefore, I want to be able to use location sensing for lights at a bare minimum. All the other tasks will be contingent on that task being implemented. I also need to account for availability of sensors and modules. If I cannot acquire certain kinds of sensors, I will revise my project and omit them from the final product.
### Technical Approach

Since I will be doing multiple tasks, I need to have concurrency so that I can allow the tasks to run simultaneously. I will also need to consider the priorities of each task so that I can run a proper scheduling algorithm. I am looking at using the round-robin approach so that I prevent starvation.

For peripherals, I am considering adding Bluetooth and UWB modules to the KL46Z. I am doing research on the sensors and hoping to finalize everything within the next day or two. These modules will be able to communicate with my sensors and the KL46Z will conduct the necessary processing. 

For software, I want to potentially make an app that allows a user to change the settings (i.e. distance to where person has considered to have left, which lights/appliances to turn on/off). I was thinking of a phone app to allow this, but a program implemented through a website might be a good initial approach.
Since I will be doing multiple tasks, I need to have concurrency so that I can allow the tasks to run simultaneously. I will also need to consider the priorities of each task so that I can run a proper scheduling algorithm. I am looking at using the round-robin approach so that I prevent starvation.

For peripherals, I am considering adding Bluetooth and UWB modules to the KL46Z. I am doing research on the sensors and hoping to finalize everything within the next day or two. These modules will be able to communicate with my sensors and the KL46Z will conduct the necessary processing. 

For software, I want to potentially make an app that allows a user to change the settings (i.e. distance to where person has considered to have left, which lights/appliances to turn on/off). I was thinking of a phone app to allow this, but a program implemented through a website might be a good initial approach.

## Feedback.

## Welcome team! Please edit me.
### You can use the 'main' branch for you code.
### The GitHub web-page should be in the 'gh-pages' branch
You can access the page adding a "pages" prefix to the url for the git repo e.g. if your browser currently shows https://github.coecis.cornell.edu/ece3140-sp22/ajb497 then the GitHub page is at https://pages.github.coecis.cornell.edu/ece3140-sp22/ajb497 . You can edit the source in the gh-pages branch or use the "automatic page generator" acessible via settings->options in the GitHub Pages Section toward the bottom. We recommend the latter approach since it is quick and easy. We made an initial wepage that you can edit and a description of the headings we expect to see.