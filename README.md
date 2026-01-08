# Greenhouse Automation using Arduino

An Arduino-based Greenhouse Automation System developed as part of the ECE-279 course project.  
This system automatically monitors and controls key greenhouse parameters to reduce manual effort and improve plant growth efficiency.

---

## Project Overview

In traditional greenhouses, temperature, humidity, irrigation, and lighting are often managed manually.  
This can lead to delays, human errors, and inconsistent growing conditions.

The Greenhouse Automation System uses sensors and automated control logic to continuously monitor environmental conditions and maintain optimal parameters in real time, ensuring healthier plant growth with minimal human intervention.

---

## Features

### Automatic Monitoring
- Temperature  
- Humidity  
- Soil Moisture  
- Light Intensity  

### Automatic Control
- Cooling fan for ventilation  
- Water pump for irrigation  
- Grow lights for artificial lighting  

### System Capabilities
- Live sensor data display on 16×2 LCD  
- Relay-based safe switching of high-power devices  
- Reduced manual intervention  
- Improved energy efficiency  

---

## Components Used

| Component | Description |
|---------|-------------|
| Arduino Uno R3 | Main controller |
| DHT22 Sensor | Temperature and humidity measurement |
| Soil Moisture Sensor | Soil water level detection |
| LDR | Light intensity sensing |
| 4-Channel Relay Module | Control high-power devices |
| DC Fan | Ventilation |
| Water Pump | Automatic irrigation |
| LED Grow Lights | Artificial lighting |
| 16×2 LCD (I2C) | Display sensor data |
| External 12V Power Supply | Power for actuators |
| Jumper Wires and Breadboard | Circuit connections |

---

## Working Principle

1. Sensors continuously collect data for:
   - Temperature  
   - Humidity  
   - Soil moisture  
   - Light intensity  

2. The Arduino compares sensor readings with predefined threshold values.

3. Based on conditions:
   - Fan turns ON or OFF for temperature and humidity control  
   - Pump turns ON or OFF based on soil moisture  
   - Grow lights turn ON or OFF based on ambient light  

4. Live sensor readings and device status are displayed on the LCD.

---

## LCD Display Format

- T → Temperature (°C)  
- H → Humidity (%)  
- S → Soil moisture value  
- F / P / L → Fan, Pump, Light status (ON/OFF)

---

## Learning Outcomes

This project provided hands-on experience in:
- Embedded systems fundamentals  
- Sensor interfacing with Arduino  
- Relay-based actuator control  
- Automation logic implementation  
- Hardware wiring and debugging  
- Team-based project collaboration  

---

## Future Scope

- IoT-based remote monitoring  
- Mobile application or web dashboard  
- Cloud-based data logging and analytics  
- Alert and notification system  
- Advanced climate control techniques  

---

## Team Members

- Satyam Kumar  
- Prince Patel  
