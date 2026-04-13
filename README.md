# Smart-Glove
IoT smart glove simulation built with C++ and ESP32. Monitors thumb, index and middle finger flexes to send notifications.


![Smart Glove prototype](https://github.com/user-attachments/assets/90114d6d-258e-4439-bde9-e95978599a7d)
)

## Features
* Tracks real-time finger movements using 3 linear slide potentiometers (Thumb, Index, Middle).
* Processes analog signals via ESP32.
* Triggers emergency network alerts using Blynk IoT integration.

## Tech Stack
* **Hardware:** ESP32, Linear Potentiometers
* **Software:** C++, Wokwi (Simulation), Blynk (IoT Cloud)

## Code Structure
The main logic is contained in `sketch.ino`, handling sensor polling and Wi-Fi/Blynk communication.
