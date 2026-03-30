
---

# 🚗 RC Race Bot – Simple Build Guide (Final Version)

This project supports **2 main bot types** with **3 control approaches**.

---

## 🔗 ESP-NOW Controller (Used in All ESP Builds)

👉 [https://github.com/sathwikshetty0/ESP-NOW-Controller](https://github.com/sathwikshetty0/ESP-NOW-Controller)

---

# 🧠 FINAL STRUCTURE

## ✅ Only TWO Bot Types:

### 1. **Brushless (BLDC) Bot**

* Rear-wheel drive
* Servo steering (front wheels)

### 2. **Brushed Motor Bot**

* Tank drive ONLY (no servo steering)
* Differential steering

---

# ⚡ OPTION 1: BRUSHLESS BOT (SERVO STEERING)

## ✅ Description

* High-speed racing bot
* Rear-wheel drive
* Front wheels controlled using **servo + steering rack**

---

## 🔩 Hardware Required

* 1x Brushless Motor (BLDC)
* 1x ESC (Brushless ESC)
* 1x Steering Servo
* 1x Chassis (RWD)
* 1x LiPo Battery (2S)
* Wheels (rear drive + front steering)

---

## 🎮 Control Options (ONLY 2)

### 🔹 1. FlySky Controller

### 🔹 2. ESP-NOW Controller

👉 [https://github.com/sathwikshetty0/ESP-NOW-Controller](https://github.com/sathwikshetty0/ESP-NOW-Controller)

---

## 🔌 CONNECTIONS

### Motor → ESC

* 3 wires from motor → ESC

---

### ESC → Controller

| Wire   | FlySky Receiver | ESP32   |
| ------ | --------------- | ------- |
| Signal | CH2             | GPIO 26 |
| VCC    | CH2             | VIN     |
| GND    | CH2             | GND     |

---

### Servo → Controller

| Wire   | FlySky Receiver | ESP32   |
| ------ | --------------- | ------- |
| Signal | CH1             | GPIO 27 |
| VCC    | CH1             | VIN     |
| GND    | CH1             | GND     |

---

### Battery → ESC

* Direct connection

---

## ⚙️ Steering

* Servo → steering rack → front wheels

---

# 🔋 OPTION 2: BRUSHED BOT (TANK DRIVE ONLY)

## ✅ Description

* Uses **2 motors (left + right)**
* No servo
* Turning via speed difference

---

## 🔩 Hardware Required

* 2x Brushed DC Motors
* Battery (2S/3S)
* Chassis (differential drive)
* Wheels

---

# 🎮 CONTROL METHODS (3 OPTIONS)

---

## 🔹 METHOD 1: Brushed ESC + FlySky (Simplest ✅)

### 🔩 Components:

* 2x Brushed ESC
* FlySky Controller

---

### 🔌 Connections:

**Motors → ESCs**

* Left motor → ESC1
* Right motor → ESC2

---

**ESCs → Receiver**

| ESC       | Receiver |
| --------- | -------- |
| Left ESC  | CH1      |
| Right ESC | CH2      |

---

### ⚠️ Important:

* Remove **RED wire** from one ESC

---

### Battery:

* Use **Y connector** to power both ESCs

---

---

## 🔹 METHOD 2: BTS7960 + Arduino + FlySky

## ✅ Description

* Custom control using Arduino
* FlySky still used for input

---

### 🔩 Components:

* 2x BTS7960 Motor Drivers
* Arduino (Uno/Nano)
* FlySky Receiver

---

### 🔌 Connections

### FlySky → Arduino

| Receiver | Arduino |
| -------- | ------- |
| CH1      | Pin 3   |
| CH2      | Pin 5   |

---

### Arduino → BTS7960 (Each Motor)

| BTS7960 | Arduino |
| ------- | ------- |
| RPWM    | Pin 9   |
| LPWM    | Pin 10  |
| R_EN    | 5V      |
| L_EN    | 5V      |
| GND     | GND     |

---

### Motor → BTS7960

* Output terminals → motor

---

---

## 🔹 METHOD 3: ESP-NOW Controller (No FlySky) 🔥

👉 [https://github.com/sathwikshetty0/ESP-NOW-Controller](https://github.com/sathwikshetty0/ESP-NOW-Controller)

---

## ✅ Description

* Fully custom wireless control
* No receiver required

---

### 🔩 Components:

* 2x ESP32 (TX + RX)
* Motor Driver (BTS7960 or similar)

---

### 🔌 Connections

### ESP32 → Motor Driver

| ESP32   | Driver |
| ------- | ------ |
| GPIO 26 | RPWM   |
| GPIO 27 | LPWM   |
| GND     | GND    |

---

### Motor → Driver

* Output → motor

---

---

# 🔥 FINAL SUMMARY

## Bot Types:

* ✅ Brushless → Servo Steering
* ✅ Brushed → Tank Drive ONLY

---

## Control Options:

| System        | Brushless | Brushed |
| ------------- | --------- | ------- |
| FlySky        | ✅         | ✅       |
| ESP-NOW       | ✅         | ✅       |
| Arduino (BTS) | ❌         | ✅       |

---

# ⚠️ SAFETY

* 🔋 Use proper LiPo charger
* ⚡ Turn ON controller FIRST
* 🛑 Test with wheels lifted
* ❌ Avoid short circuits

---

# 👨‍💻 AUTHOR

**Sathwik Shetty**

ESP-NOW Controller Repo:
👉 [https://github.com/sathwikshetty0/ESP-NOW-Controller](https://github.com/sathwikshetty0/ESP-NOW-Controller)

---


Just tell 👍
