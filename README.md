# vehicle-speed-monitoring-MiniProject
# 🐘 Vehicle Speed Monitoring and Wildlife Protection System

> A smart embedded system to monitor vehicle speed in forest road areas and trigger alerts to protect wildlife from road accidents.

---

## 📌 Project Overview

Forest roads pass through wildlife habitats where animals frequently cross. Vehicles exceeding the speed limit pose a serious threat to wildlife safety. This system automatically detects vehicle speed using two IR sensors placed at a fixed distance on the road, calculates the speed, and immediately triggers audio-visual alerts and SMS notifications when the speed exceeds the defined limit.

---

## 🎯 Objectives

- Detect vehicle speed in real-time using dual IR sensors
- Compare detected speed against a predefined safe speed limit (40 km/h)
- Trigger buzzer and LED warning when overspeed is detected
- Display live speed and status on a 16x2 LCD
- Send alert notifications to forest officials via GSM module
- Promote wildlife safety on forest roads

---

## ⚙️ Hardware Components

| Component | Specification | Quantity |
|---|---|---|
| Arduino Uno | ATmega328P, 16MHz | 1 |
| IR Sensor | Digital output, 5V | 2 |
| LCD Display | 16x2 with I2C module (0x27) | 1 |
| Buzzer | Piezo, 5V active | 1 |
| LED | Red, 5mm | 1 |
| Resistor | 220Ω | 1 |
| GSM Module | SIM800L | 1 |
| Power Supply | 5V DC | 1 |

---

## 🔌 Pin Connections

| Component | Pin | Arduino Pin |
|---|---|---|
| IR Sensor 1 | OUT | Digital Pin 2 |
| IR Sensor 2 | OUT | Digital Pin 3 |
| Buzzer | + | Digital Pin 8 |
| LED | Anode (+) | Digital Pin 9 |
| LCD I2C | SDA | A4 |
| LCD I2C | SCL | A5 |
| GSM SIM800L | TX | Digital Pin 10 |
| GSM SIM800L | RX | Digital Pin 11 |

---

## 💻 Software Components

| Tool | Purpose |
|---|---|
| Arduino IDE | Code development and upload |
| Wokwi Simulator | Online circuit simulation |
| Streamlit | Real-time web dashboard |
| Telegram Bot API | GSM alert simulation |
| Google Colab | Python alert script execution |

---

## 🧠 Working Principle

```
Vehicle Enters Road
        ↓
IR Sensor 1 Triggered → Timer Starts
        ↓
IR Sensor 2 Triggered → Timer Stops
        ↓
Speed = Distance ÷ Time × 3.6  (m/s → km/h)
        ↓
    Speed > 40 km/h?
    /             \
  YES              NO
   ↓                ↓
LCD: OVERSPEED    LCD: Speed OK
Buzzer + LED ON   Green LED blink
GSM Alert Sent    No alert
```

---

## 📐 Speed Calculation Formula

```
Speed (m/s)  = Distance (m) ÷ Time (s)
Speed (km/h) = Speed (m/s) × 3.6

Example:
  Distance between sensors = 10 meters
  Time taken by vehicle    = 0.5 seconds
  Speed = (10 ÷ 0.5) × 3.6 = 72 km/h → OVERSPEED ALERT
```


🚨 OVERSPEED ALERT!
━━━━━━━━━━━━━━━━
🚗 Vehicle No : #7
📍 Location   : Forest Road Sector 4
⚡ Speed      : 68.3 km/h
🚦 Limit      : 40 km/h
⬆️ Excess     : 28.3 km/h over limit
━━━━━━━━━━━━━━━━
📢 Notify Forest Officials
⏰ Action Required Immediately!
```

---

## 🛠️ Libraries Required

```
LiquidCrystal I2C  (by Frank de Brabander) - v1.1.2
Wire.h             (built-in with Arduino IDE)
```


**Institution:** EGS Pillay Engineering College
**Department:** Electronics and Communication Engineering
**Year / Semester:** II Year / IV Semester
**Academic Year:** 2024–2025

---

## 📄 License

This project is submitted as part of the Mini Project requirement for the B.E. ECE programme. All rights reserved © 2025 EGS Pillay Engineering College.

---

## 🔗 References

- Arduino Official Documentation — [arduino.cc](https://www.arduino.cc)
- Wokwi Simulator — [wokwi.com](https://wokwi.com)
- Streamlit Documentation — [docs.streamlit.io](https://docs.streamlit.io)
- Indian Forest Road Safety Guidelines — Ministry of Environment, Forest and Climate Change
