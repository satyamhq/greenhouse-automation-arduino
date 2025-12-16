# 🌱 Greenhouse Automation using Arduino

This project is an **Arduino-based Greenhouse Automation System** developed as part of our **ECE-279 course project**.  
The system automatically monitors and controls important greenhouse parameters to reduce manual work and improve plant growth.

---

## 📌 Project Overview

In traditional greenhouses, temperature, humidity, watering, and lighting are controlled manually.  
This often causes **delays, human errors, and inconsistent plant growth**.

Our project solves this problem by using **sensors and automatic control** to maintain optimal greenhouse conditions in real time.

---

## ⚙️ Features

- Automatic monitoring of:
  - 🌡️ Temperature
  - 💧 Humidity
  - 🌱 Soil moisture
  - 💡 Light intensity
- Automatic control of:
  - Cooling fan (ventilation)
  - Water pump (irrigation)
  - Grow lights
- Live sensor data display on **16×2 LCD**
- Relay-based safe control of high-power devices
- Reduces manual intervention and energy wastage

---

## 🧰 Components Used

- Arduino Uno R3  
- DHT22 Temperature & Humidity Sensor  
- Soil Moisture Sensor  
- LDR (Light Dependent Resistor)  
- 4-Channel Relay Module  
- DC Fan  
- Water Pump  
- Grow Lights (LED)  
- 16×2 LCD with I2C module  
- External 12V Power Supply  
- Jumper wires & breadboard  

---

## 🔁 Working Principle

1. Sensors continuously read temperature, humidity, soil moisture, and light levels.
2. Arduino compares sensor values with predefined threshold values.
3. Based on conditions:
   - Fan turns ON/OFF for temperature & humidity control
   - Pump turns ON/OFF based on soil moisture
   - Grow lights turn ON/OFF based on light intensity
4. Live values and device status are shown on the LCD.

---

## 📊 LCD Display Format

- **T:** Temperature (°C)  
- **H:** Humidity (%)  
- **S:** Soil moisture value  
- **F / P / L:** Fan, Pump, Light status (ON/OFF)

---

## 🧠 Learning Outcomes

Through this project, we learned:
- Embedded systems basics
- Sensor interfacing with Arduino
- Relay-based control of actuators
- Practical automation logic
- Hardware wiring and debugging
- Team-based project development

---

## 🚀 Future Scope

- IoT integration for remote monitoring
- Mobile app or web dashboard
- Data logging and analytics
- SMS / notification alerts
- PID-based climate control

---

## 👨‍💻 Team Members

- **Satyam Kumar**  
- **Prince Patel**

---

## 📚 Course Information

- Course: **ECE-279**
- Project Type: **Mini Project**
- Domain: **Embedded Systems / Smart Agriculture**

---

## 📜 License

This project is licensed under the **MIT License**.

---

⭐ If you find this project helpful, feel free to star the repository!
