**SMART PARKING SYSTEM**

**OBJECTIVE**

Design a parking management system that uses ultrasonic sensors to detect free slots and display them in real-time on an LCD and Blynk dashboard.

**COMPONENTS USED**

- ESP32 microcontroller  
- Ultrasonic Sensor ( since IR sensor is not available in wokwi )  
- 16x2 LCD Display with I2C module  
- Blynk IoT App / Web Dashboard  
- Jumper wires and breadboard  


**CIRCUIT**

![image](https://github.com/user-attachments/assets/e595bf24-5fc9-47f7-9821-002694a0e126)


**WORKING**

1. An ultrasonic sensor is used to detect the presence or absence of a vehicle in a parking slot by measuring the distance.
2. The ESP32 receives the sensor input and determines whether the slot is free or occupied.
3. The slot status is displayed live on:
   - **A 16x2 LCD display (e.g., “Slot: Occupied” / “Slot: Free”)**
   - **Blynk dashboard (both mobile and web) using labeled value widgets or virtual indicators**
4. The system updates in real time as the distance changes based on car movement in or out of the slot.
5. This setup can be scaled by using more ultrasonic sensors to monitor multiple slots

**WHAT I LEARNED**
- Using ultrasonic sensors to detect vehicle presence by measuring distance  
- Sending sensor readings to Blynk for live dashboard updates  
- Displaying real-time parking slot status on both LCD and online platforms  
- Building a scalable and responsive IoT-based smart parking system


**TOOLS USED**

- Wokwi – for circuit simulation  
- Blynk – for real-time monitoring  
- GitHub – for project hosting
