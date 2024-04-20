# mobile-controlled-home
This system allows controlling home by mobile phone using Bluetooth, system allows 10 users to control the home.
Two subsystems are controlled by the system ( controlling door & light On or Off) . To be able to control this system you should log in correctly using your username and password . If user enters the password 3 times wrong System will give a warning that there is  something wrong . 

Peripherals :
DIO : used to control the pins of DIO.
UART : used to communicate with Bluetooth module.
Timer 0 : used to generate PWM signal on buzzer as a warning.

Services :
Bit_math : to control the pins (SET or CLEAR) .
STD_TYPES :contain all the data type used .

Hardware :
1- Bluetooth module HC-05 .
2- Solenoid : works as a door .
3- Light .
4- Relay : controlling the voltage of LED and Solenoid.
5- Buzzer : to give a warning .
