## 🚀 Arduino Opta PLC – WiFi, Digital Input & HTTP API Integration

This project demonstrates how to use Arduino Opta with Arduino IDE to:

- Connect to Wi-Fi

- Read a PLC digital input (button)

- Send HTTP GET API calls

- Send HTTP POST API calls

- Integrate with cloud services (Blynk / Flask / REST APIs)

This is useful for Industrial IoT, PLC + Cloud integration, and automation projects.

## 📌 Features

  - Wi-Fi connection status check

  - Digital input (button) read using digitalRead()

  - HTTP GET API call (example: Blynk Cloud update)

  - HTTP POST API call (example: Flask server / custom backend)

  - HTTPS support using WiFiSSLClient

  - Edge detection to avoid repeated API calls

  - Serial Monitor debug logs

## 🧰 Hardware Requirements

- Arduino Opta WiFi PLC

- Button (connected to Digital Input)

- 2.4 GHz Wi-Fi Network

- PC / Server for API (optional – Flask)

🧪 Software Requirements

- Arduino IDE (latest)

- Board Package: Arduino Mbed OS Opta

- Libraries:

  - WiFi

  - ArduinoHttpClient

## 📡 Wi-Fi Connection Logic

The program:

1. Connects Arduino Opta to Wi-Fi

2. Prints connection status and IP address

3. Continues only after successful connection

```
 WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

  delay(500);

}
```

## 🧠 Use Cases

- PLC → Cloud data transfer

- Button / sensor based automation

- Blynk dashboard integration

- Custom REST API integration

- Industrial IoT proof-of-concept

## 👤 Author

[Karthickraja M](https://github.com/karthickrajathedeveloper)

- Embedded Systems & IoT Engineer
- Arduino
- PLC
- ESP32
- Cloud Integration
