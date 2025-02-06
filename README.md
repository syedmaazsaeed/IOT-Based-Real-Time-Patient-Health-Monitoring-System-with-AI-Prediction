# IOT-Based-Real-Time-Patient-Health-Monitoring-System

Welcome to the IoT-Based Real-Time Patient Health Monitoring System! This system uses IoT technology to continuously monitor vital health parameters such as body temperature, ECG, heart rate, and pulse rate. The collected data is then transmitted to the cloud for analysis and easy monitoring. 🏥🌐

An advanced IoT-powered system that tracks heart rate ❤️, temperature 🌡, SpO2 ⏳, and ECG in real-time. 🚨 Alerts doctors instantly in emergencies, stores data securely in the cloud ☁, and provides remote patient monitoring 📊📱. Revolutionizing healthcare with AI-driven insights! ⭐

🚀 Project Overview:

This health monitoring system is designed to provide real-time monitoring of patients' key health metrics. Using MAX30100 (for pulse oximetry), DS18B20 (for temperature), and an ECG sensor, the system ensures continuous tracking of a patient's heart rate, oxygen saturation, body temperature, and ECG readings. Alerts are triggered if any of the values go out of the safe range. 🚑

Key Features:

Real-Time Data Monitoring: Track key health parameters like temperature, heart rate, SpO2, and ECG. 💓📈
Abnormal Condition Alerts: Get immediate alerts (LED/Buzzer) when any vital sign goes outside normal limits. 🚨
Cloud Integration: Seamless data transmission to Ubidots for real-time cloud monitoring. 🌐
LCD Display: A real-time LCD display for quick health data visualization. 🖥️
Easy Wi-Fi Connectivity: Connects easily to Wi-Fi for cloud communication. 📡

🔧 Tech Stack:

Hardware:
MAX30100: For heart rate and SpO2 measurement.
DS18B20: For body temperature measurement.
ECG Sensor: For capturing ECG data.
ESP8266: For Wi-Fi connectivity.
LCD Display: For displaying live data.

Software:
Arduino IDE for writing the firmware.
Ubidots for cloud integration.

Libraries:
Wire.h, LiquidCrystal_I2C.h, ESP8266WiFi.h, Ubidots.h, MAX30100_PulseOximeter.h, DallasTemperature.h, and OneWire.h.

⚡ How It Works:

1. Sensor Data Collection: The system collects data from MAX30100 (heart rate, SpO2), DS18B20 (temperature), and ECG sensor.
2. Data Analysis: The health metrics are continuously monitored for any abnormal readings.
3. Alert Mechanism: If abnormal conditions are detected (e.g., high temperature, low oxygen levels, irregular heart rate), the system activates a red LED and buzzer for alerting. 🆘
4. Cloud Transmission: Every 16 seconds, the data is sent to Ubidots for storage and further analysis.
5. LCD Visualization: The real-time readings are displayed on the LCD for quick checks. 🖥️

🛠️ Setup Instructions:

Clone the Repository:

git clone https://github.com/yourusername/IoT-Patient-Health-Monitoring.git

Install Libraries:

Download and install the following libraries from the Arduino IDE Library Manager:

LiquidCrystal_I2C
ESP8266WiFi
Ubidots
MAX30100_PulseOximeter
DallasTemperature
OneWire

Connect Hardware:

Connect the MAX30100 sensor to your ESP8266 (pins configured in the code).
Connect the DS18B20 sensor to the OneWire bus.
Connect the ECG sensor to the appropriate analog pin.
Connect the LCD for real-time display.

Upload the Code:

Upload the code to your ESP8266 using the Arduino IDE.

View Data:

Open the serial monitor to view the console output.
Connect to the Ubidots dashboard to view real-time health data.
Monitor the LCD for immediate feedback on the patient's condition. 📱

🎯 Future Improvements:

Machine Learning Integration: Use AI to analyze patterns in health data and predict potential health issues. 🤖
Mobile Application: Build a mobile app to receive real-time health data and alerts. 📲
Expand Sensor Suite: Add additional sensors like ECG or pulse wave sensors for deeper health insights. 📊

💬 Connect with Us:

Have questions or suggestions? Feel free to reach out via issues or email! Let’s innovate healthcare together! 🌍💡






