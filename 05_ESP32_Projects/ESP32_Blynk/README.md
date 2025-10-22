# 💡 ESP32 IoT LED Control — Blynk Cloud Example

This project demonstrates how to connect an **ESP32** board to the **Blynk IoT Cloud** platform using Wi-Fi and send a virtual message ("Hello") to the mobile dashboard. It serves as a basic foundation for IoT communication between microcontrollers and cloud-based dashboards.

---

## 🧠 Project Overview

This project establishes an IoT connection between:
- **ESP32 Microcontroller**
- **Blynk IoT Cloud Platform**
- **Wi-Fi Network**

Once connected, the ESP32 sends a string `"Hello"` to **Virtual Pin V0** in your Blynk dashboard.

---

## 🧰 Components Used

| Component | Description |
|------------|-------------|
| **ESP32 Development Board** | Wi-Fi + Bluetooth microcontroller |
| **Blynk IoT Cloud App** | Mobile dashboard for IoT control |
| **Wi-Fi Network** | For Internet connection |
| **USB Cable** | For programming ESP32 |

---

## 🔧 Software & Libraries

- **Arduino IDE**
- **Blynk Library (v1.3.2 or above)**  
- **WiFi.h** and **WiFiClient.h** (built-in ESP32 core libraries)

---

## ⚙️ Configuration Steps

1. **Install Blynk Library:**
   - Go to **Sketch → Include Library → Manage Libraries**  
   - Search and install **“Blynk”**

2. **Set Up Blynk Cloud:**
   - Create a new device in the **Blynk IoT Web Dashboard**
   - Copy:
     - `BLYNK_TEMPLATE_ID`
     - `BLYNK_TEMPLATE_NAME`
     - `BLYNK_AUTH_TOKEN`

3. **Replace Wi-Fi Credentials:**
   ```cpp
   char ssid[] = "Your_WiFi_Name";
   char pass[] = "Your_WiFi_Password";
