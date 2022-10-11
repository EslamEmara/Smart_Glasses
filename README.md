# Smart_Glasses
This project is created as a graduation project of FOE,Alexandria University </br>
Smart glasses specified for the blind </br>
________________________________________________________________________________________ </br>
This Repo contains the embedded systems part of the project </br>

Inputs: I2C Capacitive touch slider , 3 Sharp IR sensors . </br>
Outputs : 3 Vibration motors , USB-TTL. </br>
Function: </br>
1- Take gestures from the capactive touch slider </br>
   - Swipe Up and down increases and decreases the vibration motors senstivity </br>
   - Other button presses or holding certain button sends the mapped command through the USB-TTL to raspberryPI </br>
2- Measure analog distances from the 3 sharp IR sensors at the 3 sides of the glasses </br>
   - if the distance of nearby objects increases the vibration of the adjacent motor increases </br>
   
