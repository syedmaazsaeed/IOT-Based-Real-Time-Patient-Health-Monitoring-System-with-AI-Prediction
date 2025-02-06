# IOT-Based-Real-Time-Patient-Health-Monitoring-System

Welcome to the IoT-Based Real-Time Patient Health Monitoring System! This system uses IoT technology to continuously monitor vital health parameters such as body temperature, ECG, heart rate, and pulse rate. The collected data is then transmitted to the cloud for analysis and easy monitoring. 🏥🌐

An advanced IoT-powered system that tracks heart rate ❤️, temperature 🌡, SpO2 ⏳, and ECG in real-time. 🚨 Alerts doctors instantly in emergencies, stores data securely in the cloud ☁, and provides remote patient monitoring 📊📱. Revolutionizing healthcare with AI-driven insights! ⭐

## **1. Project Overview 🚀**

This health monitoring system is designed to provide real-time monitoring of patients' key health metrics. Using MAX30100 (for pulse oximetry), DS18B20 (for temperature), and an ECG sensor, the system ensures continuous tracking of a patient's heart rate, oxygen saturation, body temperature, and ECG readings. Alerts are triggered if any of the values go out of the safe range. 🚑

## **2. Key Features**

### **2.1 Real-Time Data Monitoring** : Track key health parameters like temperature, heart rate, SpO2, and ECG. 💓📈
### **2.2 Abnormal Condition Alerts** :  Get immediate alerts (LED/Buzzer) when any vital sign goes outside normal limits. 🚨
### **2.3 Cloud Integration** :  Seamless data transmission to Ubidots for real-time cloud monitoring. 🌐
### **2.4 LCD Display** :  A real-time LCD display for quick health data visualization. 🖥️
### **2.5 Easy Wi-Fi Connectivity**:  Connects easily to Wi-Fi for cloud communication. 📡

## **3. Tech Stack**

### **3.1 Hardware**

- **MAX30100**: For heart rate and SpO2 measurement.  
- **DS18B20**: For body temperature measurement.  
- **ECG Sensor**: For capturing ECG data.  
- **ESP8266**: For Wi-Fi connectivity.  
- **LCD Display**: For displaying live data.

### **3.2 Software**

- **Arduino IDE** for writing the firmware.  
- **Ubidots** for cloud integration.

### **3.3 Libraries**

- Wire.h  
- LiquidCrystal_I2C.h  
- ESP8266WiFi.h  
- Ubidots.h  
- MAX30100_PulseOximeter.h  
- DallasTemperature.h  
- OneWire.h.

## **4. How It Works**

### **4.1 Sensor Data Collection**

The system collects data from **MAX30100** (heart rate, SpO2), **DS18B20** (temperature), and **ECG sensor**.

### **4.2 Data Analysis**

The health metrics are continuously monitored for any abnormal readings.

### **4.3 Alert Mechanism**

If abnormal conditions are detected (e.g., high temperature, low oxygen levels, irregular heart rate), the system activates a red LED and buzzer for alerting. 🆘

### **4.4 Cloud Transmission**

Every 16 seconds, the data is sent to **Ubidots** for storage and further analysis.

### **4.5 LCD Visualization**

The real-time readings are displayed on the LCD for quick checks. 🖥️


## **5. Setup Instructions**

### **5.1 Clone the Repository 🖥️**


git clone https://github.com/syedmaazsaeed/IOT-Based-Real-Time-Patient-Health-Monitoring-System

5.2 Install Libraries 📚

Download and install the following libraries from the Arduino IDE Library Manager:

1. LiquidCrystal_I2C
2. ESP8266WiFi
3. Ubidots
4. MAX30100_PulseOximeter
5. DallasTemperature
6. OneWire

5.3 Connect Hardware 🔌

1. Connect the MAX30100 sensor to your ESP8266 (pins configured in the code).
2. Connect the DS18B20 sensor to the OneWire bus.
3. Connect the ECG sensor to the appropriate analog pin.
4. Connect the LCD for real-time display.

5.4 Upload the Code

Upload the code to your ESP8266 using the Arduino IDE.

5.5 View Data 📊

1. Open the serial monitor to view the console output.
2. Connect to the Ubidots dashboard to view real-time health data.
3. Monitor the LCD for immediate feedback on the patient's condition. 📱


## **6: 🎯 Future Improvements 🔮 **:

6.1.  Machine Learning Integration: Use AI to analyze patterns in health data and predict potential health issues. 🤖
6.2.  Mobile Application: Build a mobile app to receive real-time health data and alerts. 📲
6.3.  Expand Sensor Suite: Add more detectors like ECG or pulse wave sensors for deeper health insights. 📊

## **7:💬 Connect with Us**:

Have questions or suggestions? Feel free to reach out via issues or email! Let’s innovate healthcare together! 🌍💡..
