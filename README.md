# Waste Segregation System

This project is designed to segregate waste into three categories: **Dry**, **Wet**, and **Metal**. The system utilizes sensors and servo motors to automate the segregation process, making it efficient and environmentally friendly.

---

## Features
- **Automated Segregation:** Classifies waste as dry, wet, or metal.
- **Metal Detection:** Custom-built circuit due to the unavailability of an inductive proximity sensor.
- **Moisture Analysis:** Determines wet waste using a soil moisture sensor.
- **LCD Display:** Provides real-time status updates for better user interaction.
- **Ultrasonic Sensor:** Measures waste distance and triggers the segregation process.
- **Future Upgrade:** Capability to segregate multiple types of waste simultaneously using advanced sensors.

---

## Components Required

1. **Sensors:**
   - Soil Moisture Sensor (to detect wet waste)
   - Ultrasonic Sensor (for waste detection)
2. **Motors:**
   - 2 x Servo Motors (to move waste to designated bins)
3. **Circuit Components:**
   - Custom Metal Detection Circuit
   - 7805 Voltage Regulator (for power supply stabilization)
4. **Display:**
   - LCD Display (for system updates and feedback)

---

## Working Principle
1. **Detection:**
   - The ultrasonic sensor detects the presence of waste and its distance.
2. **Classification:**
   - If metal is detected by the custom circuit or magnetic sensor, the waste is categorized as metal.
   - If the soil moisture sensor reads high moisture, the waste is categorized as wet.
   - Otherwise, the waste is categorized as dry.
3. **Actuation:**
   - Servo motors direct the waste to the appropriate bin based on the classification.
4. **Feedback:**
   - The LCD displays the waste type and the status of the segregation process.

---

## Future Improvements
- Integrate a system to handle bulk waste segregation using multiple sensors simultaneously.
- Use advanced capacitive sensors to accurately detect plastic materials.
- Introduce IoT capabilities for real-time monitoring and notifications.
- Explore machine learning algorithms to optimize segregation accuracy.

---

## How to Use
1. Assemble all the components as per the circuit diagram.
2. Power the system using the 7805 voltage regulator.
3. Place the waste in the input compartment.
4. Observe the LCD display for waste type and status.
5. The waste is directed to the appropriate bin automatically.

---

## Circuit Design
Due to the unavailability of an inductive proximity sensor, a **custom circuit** has been designed for metal detection. This circuit uses basic components to determine if the waste is metallic and sends a signal to the microcontroller(Arduino Uno).

---
