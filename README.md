# Smart-Glove
IoT smart glove simulation built with C++ and ESP32. Monitors thumb, index and middle finger flexes to send notifications.


![Smart Glove Prototype](<img width="1647" height="951" alt="Screenshot 2026-04-14 014939" src="https://github.com/user-attachments/assets/1ebd1217-a472-443f-8ab5-c1279542b721" />
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
