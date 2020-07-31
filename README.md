# Boards_Speak
Raspberry Pi, ESP32 and a smartphone talk on a common platform.
One can use only one board instead of two as both have inbuilt WiFi adaptors. Here we choose to use two boards to demonstrate a example where the sensor (LDR connected to WROOM32) and the actuator (Relay, through current driver connected to Raspberry Pi) are at two different places. Also,one has to keep in mind that Raspberry Pi doesn't have a inbuilt ADC, so external ADC like MCP3008 SPI output ADC can be used to interface LDR to RPi.
The user with the help of his android app gives a voice command to turn the lights ON/OFF.
The app updates the corresponding tag in the firebase database as per the command received by the user.
Now, We have a Light (one can have appliances connected with the help of relay and current driver circuit) connected to Raspberry Pi board, which has access to the database page.
It reads the tag and turns the light (here LED) ON/OFF accordingly.
In order to inform the user about the status of the lights (here LED), We have a LDR sensor connected to ESP WROOM 32 to sense the status of light (it has been pre calibrated by checking sensor data when LED ON and LED OFF).
ESP wroom 32 accesses the status tag in the database firebase webpage and updates it according to the light intensity, thereby giving a immediate feedback.
Limitations: Anyone with the App can control the lights. can be overcomed by setting the required access permissions in the firebase database.
Suggested extensions: External interrupt pin can be used to interface the sensor, inorder to save processor from continuously look for change in the status. (This will need use of a comparator as signal conditioning and converting the sensor data into digital signal).
