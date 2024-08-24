# Universe Simulation

This program will load and display a moving universe with the given information in the .txt file, applying physics to calculate the velocity, position.

### Features
- I used vector data structure to store the planets inside the universe class. I chose vector becauseit is simple and easy to interact, all I need is to go through the vector when I want to ouput theplanets. 
- I also use the smart pointer to organize the celestialbody objects inside the universe.
- I have 3 functions to do the math for the physics part, one to calculate force, one to calculate velocity, and one to calculate position. After the force and velocity are updated, I update the position.
- I have a personal background for the universe, I also play the sound of the universe.
- I also have my own universe called the custom-uni.txt where I put only the sun and the earth,  but I figure out the velocity and position so that the earth will speed up towards the sun at some point, crashes into the sun, then slow down again.
- I also have the elapsed time displayed on the screen. 
