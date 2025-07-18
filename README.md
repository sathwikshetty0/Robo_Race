
# RC Race Bot Build Guide

This guide provides a detailed breakdown of the components and connections required to build your own RC Race Bot. It now covers three distinct build paths, offering a range of control options from standard hobby-grade to custom DIY electronics.

1.  **Version 1: Flysky Controller with Servo Steering (Recommended)** - The standard, high-performance racing setup.
2.  **Version 2: Flysky Controller with Tank-Style Steering** - A powerful skid-steer build using two motors.
3.  **Version 3: Custom ESP-NOW Controller (Servo Steering)** - An advanced DIY version that replaces the Flysky system with a custom-built wireless controller.

---

## **1. Option 1: The High-Speed Race Bot (Servo Steering)**

This build focuses on speed, agility, and precise control, making it ideal for racing on a track or in an open area.

### **1.1. Required Components**

| Component | Quantity | What to look for |
| :--- | :--- | :--- |
| **Chassis** | 1 | 1/10 scale, designed for a single rear motor. Plastic (ABS), Aluminum, or Carbon Fiber. |
| **Brushless Motor** | 1 | 1/10 scale, **Sensored**, **3000KV - 4500KV**. Sensored provides smoother control. |
| **ESC** | 1 | **Sensored**, with an amp rating higher than the motor's max draw (e.g., 60A-120A). |
| **Steering Servo** | 1 | **Standard size**, with **metal gears** for durability. Speed: ~0.12s or faster. |
| **Wheels & Tires** | 1 set (4) | 1/10 scale with **12mm hex** mounts. Choose "on-road" tires for pavement. |
| **LiPo Battery** | 1 | **2S (7.4V)**, **4000-5000mAh**, **50C+** discharge rate. |
| **LiPo Balance Charger**| 1 | **ESSENTIAL.** Must be specifically for LiPo batteries. |
| **Flysky Controller** | 1 set | Transmitter (e.g., FS-GT3B/GT5) and a matching Receiver. |
| **Pinion Gear** | 1 | A small gear that attaches to the motor shaft. Must match the motor shaft diameter. |

### **1.2. Wiring and Connections (Pura Detailed!)**

Follow these connections step-by-step. The heart of your bot is the **Receiver**, where everything plugs in.

**Step 1: Motor to ESC**
* Your brushless motor has three wires (usually Blue, Yellow, Orange).
* The ESC has three corresponding motor output wires.
* **If your system is SENSORED:** Connect the small sensor wire from the motor to the sensor port on the ESC. Then, connect the three main motor wires to the ESC (A to A, B to B, C to C).
* **If SENSORLESS:** Connect the three motor wires to the three ESC wires. The order doesn't matter right now. If the motor spins the wrong way later, you can just swap any two of the three wires.

**Step 2: Connect ESC and Servo to the Receiver**
* Your receiver has multiple channels, usually marked CH1, CH2, CH3, etc., and VCC/BATT.
* Each plug from the ESC and Servo has three pins: Signal, Positive (+), and Negative (-). The plug is keyed to only fit one way.
* **Steering Servo -> Channel 1 (ST):** Plug the steering servo's 3-pin connector into the pins marked **CH1** (or "ST" for Steering).
* **ESC -> Channel 2 (TH):** Plug the ESC's 3-pin connector into the pins marked **CH2** (or "TH" for Throttle). The ESC's connector also powers the receiver and the servo (this is called a BEC - Battery Eliminator Circuit).

**Receiver Connection Summary:**

| Port on Receiver | What Plugs In? | Purpose |
| :--- | :--- | :--- |
| **CH1 / ST** | Steering Servo | Controls Left / Right steering |
| **CH2 / TH** | ESC | Controls Forward / Brake / Reverse |
| **CH3, CH4...** | *Empty* | Used for lights or other accessories |
| **BATT / VCC** | *Empty* | The ESC provides power through CH2 |

**Step 3: Battery to ESC**
* This is the main power connection.
* Connect your fully charged LiPo battery to the main power connector on the ESC.
* **Be ready!** The bot may beep or chime when it first gets power. Keep the wheels off the ground.

### **1.3. Flysky Controller Setup**
1.  **Binding:** Make sure your transmitter is "bound" to your receiver. The process is in your controller's manual but usually involves holding a bind button on the receiver while powering it on.
2.  **Check Controls:** With the wheels off the ground, turn on your transmitter **FIRST**, then plug in the battery to the bot.
    * Turn the steering wheel on the controller. The front wheels should turn left and right. If they turn the wrong way, use the "Servo Reverse" (ST.REV) function on your controller for Channel 1.
    * Gently pull the throttle trigger. The motor should spin. If it spins the wrong way, use the "Throttle Reverse" (TH.REV) function for Channel 2.

---

## **2. Option 2: The Tank-Style Bot (Skid Steering)**

This build uses differential speed between the left and right wheels to turn. It is mechanically simple but requires more complex electronic setup and is less stable for racing.

### **2.1. Required Components**

| Component | Quantity | What to look for |
| :--- | :--- | :--- |
| **Chassis** | 1 | Must be designed to mount **two separate motors**, one for each side. |
| **Brushless Motors** | **2** | **Identical models.** Lower KV might be easier to control (e.g., 2500-3500KV). |
| **ESCs** | **2** | **Identical models.** Must match the motors. |
| **Wheels & Tires** | 1 set (4) | All four wheels will be driven. |
| **LiPo Battery** | 1 | **2S (7.4V)**, **4000-5000mAh**, **50C+**. Same as Option 1. |
| **LiPo Balance Charger**| 1 | **ESSENTIAL.** |
| **Flysky Controller** | 1 set | Transmitter and Receiver. The transmitter **must have channel mixing** (V-Tail/Elevon). |
| **Power Y-Harness** | 1 | A cable that splits one battery connector into two ESC connectors (e.g., one female Deans to two male Deans). |
| **Pinion Gears** | **2** | Identical gears for each motor. |

### **2.2. Wiring and Connections (Pura Detailed!)**

**IMPORTANT:** In this setup, you must disable the BEC on one of the ESCs to avoid sending conflicting power to the receiver. To do this, carefully lift the plastic tab on the ESC's receiver plug and pull out the **RED (+) wire**. Fold it back and cover it with electrical tape. Leave the red wire intact on the *other* ESC.

**Step 1: Motors to ESCs**
* Connect the **Left Motor** to the **Left ESC**.
* Connect the **Right Motor** to the **Right ESC**.

**Step 2: Connect ESCs to the Receiver**
* **Left ESC -> Channel 1 (ST):** Plug the Left ESC's connector into **CH1**. This will be your left-side drive.
* **Right ESC -> Channel 2 (TH):** Plug the Right ESC's connector (the one that still has its red wire) into **CH2**. This will be your right-side drive and will power the receiver.

**Receiver Connection Summary:**

| Port on Receiver | What Plugs In? | Purpose |
| :--- | :--- | :--- |
| **CH1 / ST** | Left Side ESC | Controls the Left Motor |
| **CH2 / TH** | Right Side ESC | Controls the Right Motor (and powers receiver) |
| **SERVO PORT** | **NOTHING** | **NO SERVO IS CONNECTED** |

**Step 3: Battery to ESCs**
* Connect the **Power Y-Harness** to your LiPo Battery.
* Connect the two ends of the Y-Harness to the **Left ESC** and the **Right ESC**.

### **2.3. Flysky Controller Setup (Channel Mixing)**
This is the most critical step for a skid-steer bot. You need to program your transmitter to control two channels with one stick/wheel.

1.  **Find the Mixing Menu:** On your Flysky controller, navigate through the menu to find a function called **"Mix"**, **"V-Tail"**, or **"Elevon"**. This is usually in a "Functions" or "Setup" menu.
2.  **Activate Mixing:** Turn the mixing function ON.
3.  **Configure the Mix:**
    * The goal is to have the throttle control (up/down) affect both CH1 and CH2 equally for forward/reverse motion.
    * The steering control (left/right) should *subtract* speed from one channel and *add* speed to the other to make the bot turn.
    * You will typically see settings like `Mix 1`, `Source`, `Destination`, `Up Rate`, `Down Rate`.
    * A common setup is to mix Channel 1 and Channel 2. You may need to experiment with the rate percentages (e.g., setting them to 100%) to get the bot to drive straight and turn correctly. Refer to your controller's manual for specific instructions on V-Tail mixing.

-----

## **Version 3: Custom ESP-NOW Controller (Servo Steering)**

This advanced version replaces the standard Flysky radio system with a custom-built, low-latency wireless controller using ESP32 boards. This build is for the **servo steering chassis** (the same hardware as Version 1) and offers maximum customizability, such as the trim functions included in your code. It requires a good understanding of electronics and coding.

-----

### **3.1. Required Components**

| Component | Quantity | Notes |
| :--- | :--- | :--- |
| **(A) Transmitter** | | |
| ESP32 Board | 1 | e.g., ESP32 DEVKIT V1 |
| Joystick Module | 1 | 2-Axis Analog Joystick |
| Push Buttons | 2 | Momentary push buttons for trim control. |
| Power Source | 1 | USB Power Bank or a small LiPo with a 5V regulator. |
| Prototyping Board | 1 | A breadboard or perfboard to assemble the controller. |
| **(B) Bot / Receiver**| | |
| ESP32 Board | 1 | e.g., ESP32 DEVKIT V1 |
| **All Bot Components from Version 1** | 1 set | **Excluding the Flysky Controller.** You still need the chassis, motor, ESC, servo, battery, etc. |

-----

### **3.2. Step-by-Step Guide**

This process is broken down into three main phases: finding the bot's unique address, building the transmitter, and assembling the receiver on the bot.

#### **Phase 1: Find Your Bot's Unique MAC Address**

Every ESP32 has a unique hardware address called a MAC address. The transmitter needs to know this address to send data to the correct bot.

1.  **Get the Code:** Use a simple "MAC Address Finder" sketch. You can find one included with the ESP32 examples in the Arduino IDE or use the one provided in our earlier conversation.
2.  **Upload to Bot's ESP32:** Connect the ESP32 that will be on your bot to your computer and upload this sketch.
3.  **Find the Address:** Open the Arduino IDE's Serial Monitor (set to 115200 baud). Press the ESP32's `RST` button. The MAC address will be printed (e.g., `D8:BC:38:79:B9:98`).
4.  **Save the Address:** Copy this address. You will need it for the transmitter code.

#### **Phase 2: Build and Program the Transmitter**

The transmitter is your handheld remote control.

1.  **Hardware Assembly:**
      * Place the transmitter ESP32 on a breadboard or perfboard.
      * **Joystick:** Connect the joystick module's `VCC` pin to `3.3V` on the ESP32 and `GND` to `GND`. Connect the `VRx` (X-axis) and `VRy` (Y-axis) pins to the analog input pins specified in your transmitter code (e.g., GPIO 33 and 32).
      * **Trim Buttons:** Connect one leg of each push button to a GPIO pin specified in the code (e.g., GPIO 23 and 22). Connect the other leg of each button to `GND`. The code uses `INPUT_PULLUP`, so no external resistors are needed.
2.  **Software Setup:**
      * Open your transmitter sketch in the Arduino IDE.
      * **Update MAC Address:** Find the line `uint8_t receiverMacAddress[] = {...};` and replace the placeholder address with the one you copied from your bot.
      * **Check Pins:** Double-check that the pin numbers in the code match your wiring.
      * **Upload:** Upload the completed sketch to your transmitter ESP32.

#### **Phase 3: Assemble and Program the Bot's Receiver**

The receiver ESP32 replaces the Flysky receiver and acts as the bot's new brain.

1.  **Hardware Assembly:**

      * Mount the receiver ESP32 securely onto your bot's chassis.
      * **ESC Connection:** Locate the 3-pin connector from your brushless ESC. Connect its **signal wire** to the GPIO pin specified in your receiver code for the ESC (e.g., GPIO 26).
      * **Steering Servo Connection:** Connect the steering servo's **signal wire** to the GPIO pin specified for the servo (e.g., GPIO 27).
      * **Powering the System:** Connect the ESC's `5V` (red wire) and `GND` (black wire) pins to the `VIN` and `GND` pins on your ESP32 board. The ESC's internal BEC (Battery Eliminator Circuit) will power the ESP32 and the steering servo.
      * **Main Power:** The brushless motor and main battery connect to the ESC as they did in Version 1.

2.  **Software Setup:**

      * Open your receiver sketch in the Arduino IDE.
      * **Check Pins:** Ensure the servo and ESC pins defined in the code (27 and 26) match your connections.
      * **Upload:** Upload the sketch to the receiver ESP32 on the bot.

Your custom ESP-NOW controlled race bot is now complete. Turn on the transmitter first, then power up the bot. You should have full proportional control over steering and throttle.
-----

## **4. Critical Safety Information (READ THIS\!)**

  * **LiPo Batteries are Dangerous if Mishandled.**
      * **ALWAYS** use a proper LiPo Balance Charger.
      * **NEVER** leave a charging LiPo unattended or use a damaged battery.
  * **Always turn your TRANSMITTER ON FIRST**, before plugging in the battery on the bot.
  * **Always UNPLUG THE BOT FIRST**, before turning your transmitter off.
  * Keep hands and loose clothing away from moving parts.
