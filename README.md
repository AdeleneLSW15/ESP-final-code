# ESP-final-code
This is the final code written by Adelene for second year ESP project of Electrical and Electronic Department in University of Manchester. The group's buggy manage to obtain second place in the final race with a time of 57.2 seconds.


### The Challenge 
To create an autonomous buggy that is capable of following a white-line on a black track. It should be capable to respond to bluetooth command which allows it to turn around at the end of a track and return to the starting line. The end of the track has a wall barrier which the buggy should not collide with. Teams are challenged to make the buggy as fast as possible with appropriate control in place.

The fastest buggy would then be shortlisted to the final race. 

## System Components for the buggy to allow this code to work
Equipped with 6 TCRT5000 sensors that is mounted on a Printed Circuit Board (PCB) created by my teammate. Gearbox 1 is chosen by analysis to provide sufficient torque whilist maximizing speed to climb an 18 degree slope. AEAT-601B-F06 Hall Effect Quadrature Encoder from Broadcom was used. HM-10 BLE module for bluetooth intervention capabilities. Chassis was constructed using Acetyl. Microcontroller STM32F401RE Nucleo was used with mBed application shield for debugging purposes.

### Footnotes
The mbed library allows C++ programming capability for STM32 microcontroller, this is a library in mbed not owned by me. The subsequent libraries of C12832, QEI library was not written by me. It is there to provide visibility that the program is functional with these libraries in place. Code written by me is main.cpp, motors.cpp, sensors.cpp, and encoder.cpp only. I do not own any of the library code nor files associated with it.

Thank you.

