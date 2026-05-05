# Star-Tracking-System-using-Arduino-Uno-
This project uses two analog sensors to control a servo motor. The Arduino reads and compares sensor values; if the left value is higher, the servo turns left, and if the right value is higher, it turns right. If equal, the servo stays centered.
##logic:
If the value of the left sensor is greater than the value of the right sensor, then the servo turns left, and vice versa. If both the values of the sensors are equal, then the servo remains at the center with no movement.
##components:
1. Arduino Uno
2. Servo
3. Jumper wires
4. photoresistor ldr sensors 
##concept:
The Arduino reads the light intensity from the two sensors and compares the values; it rotates the servo corresponding to the direction with the higher value.
