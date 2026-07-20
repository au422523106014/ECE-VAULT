# Smart IoT Oxygen Level Detection and Crowd Safety System

## 📌 Project Overview

The Smart IoT Oxygen Level Detection and Crowd Safety System is an IoT-based safety monitoring project designed to monitor oxygen levels in enclosed environments. The system continuously checks the sensor readings and alerts users whenever the oxygen level falls below the predefined threshold. It uses an ESP32 microcontroller with Blynk IoT for real-time monitoring and notifications.

## 🎯 Objective

To develop a smart safety monitoring system that detects low oxygen levels and provides instant alerts to improve public safety in enclosed or crowded environments.

## 🛠 Components Used

- ESP32 Development Board
- MQ2 Gas Sensor
- 16x2 I2C LCD Display
- Relay Module
- Buzzer
- Red LED
- Green LED
- Jumper Wires
- Breadboard
- Blynk IoT Platform

## ⚙️ Working Principle

1. The MQ2 sensor continuously monitors the surrounding environment.
2. The ESP32 reads the sensor values at regular intervals.
3. If the measured value falls below the predefined threshold, the system:
   - Activates the buzzer.
   - Turns on the red LED.
   - Switches the relay.
   - Displays an alert on the LCD.
   - Sends a notification through the Blynk IoT application.
4. When the environment returns to a safe condition, the alert is stopped, the green LED turns on, and the LCD displays a normal status message.

## ✨ Features

- Real-time monitoring using ESP32.
- LCD display for live sensor readings.
- Automatic buzzer alert during unsafe conditions.
- Relay activation for emergency response.
- Red and Green LED status indication.
- Remote monitoring through the Blynk IoT application.
- Low-cost prototype for smart safety monitoring.

## 📷 Project Image

![Smart IoT Oxygen Level Detection](Images/YOUR_IMAGE_NAME.jpg)
