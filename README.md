# RC Race Bot Build Guide

This guide provides a detailed breakdown of the components and connections required to build your own RC Race Bot. It covers two distinct build paths:

1.  **Option 1: The High-Speed Race Bot (Recommended)** - Uses a steering servo for precise, high-speed control. This is the standard for racing.
2.  **Option 2: The Tank-Style Bot (Skid Steer)** - Uses two motors for movement and steering, without a servo. This is simpler mechanically but harder to control for racing.

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

---

## **3. Critical Safety Information (READ THIS!)**

* **LiPo Batteries are Dangerous if Mishandled.**
    * **ALWAYS** use a proper LiPo Balance Charger.
    * **NEVER** leave a charging LiPo unattended.
    * **NEVER** use a puffy, swollen, or damaged LiPo battery.
    * Store LiPo batteries in a fire-proof bag or container.
* **Always turn your TRANSMITTER ON FIRST**, before plugging in the battery on the bot.
* **Always UNPLUG THE BOT FIRST**, before turning your transmitter off.
* Keep your hands and loose clothing away from the moving parts (gears, wheels) when the bot is powered on.
