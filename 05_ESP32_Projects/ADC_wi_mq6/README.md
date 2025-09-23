MQ6 Gas Sensor with ESP32 and LCD

This project demonstrates how to interface an MQ6 Gas Sensor with an ESP32 microcontroller, read analog values using ADC, display the gas level on an LCD, and print real-time data on the Serial Monitor. An LED indicator is also used to signal when the gas concentration exceeds a defined threshold.

📌 Components Required

ESP32 Development Board

MQ6 Gas Sensor

16x2 LCD Display (I²C module recommended)

1 × LED

1 × Resistor (220Ω for LED)

Jumper wires

Breadboard

⚡ Circuit Connections

MQ6 Sensor

VCC → 5V

GND → GND

AOUT → GPIO 32 (Analog input)

LED Indicator

Anode (+) → GPIO 2 (via 220Ω resistor)

Cathode (–) → GND

LCD Display (I²C)

VCC → 5V

GND → GND

SDA → GPIO 21

SCL → GPIO 22

💻 Code Explanation
void setup() {
  Serial.begin(115200);   // Start Serial Monitor
  pinMode(2, OUTPUT);     // LED output
  pinMode(32, INPUT);     // MQ6 analog input
}

void loop() {
  int x = analogRead(32);   // Read ADC value (0-4095 on ESP32)
  
  if (x > 3000) {
    digitalWrite(2, HIGH);  // Turn ON LED if threshold crossed
  } else {
    digitalWrite(2, LOW);   // Turn OFF LED otherwise
  }

  Serial.println(x);        // Print gas level on Serial Monitor
  delay(1000);              // 1 second delay
}

📊 Working Principle

The MQ6 sensor detects LPG, butane, propane, and other gases.

The analog output is fed into ESP32 ADC pin (GPIO 32).

If the gas concentration exceeds the threshold (here 3000), the LED turns ON.

The real-time sensor data is displayed on the LCD and printed in the Serial Monitor.

🔧 Required Libraries

For LCD (I²C):

LiquidCrystal_I2C

Wire.h (already included with Arduino IDE)

🚀 How to Run

Install Arduino IDE with ESP32 board support.

Connect the ESP32 and MQ6 sensor as per the circuit.

Upload the code to ESP32.

Open Serial Monitor at 115200 baud to see live readings.

Observe the LCD display for gas level updates.

📈 Applications

Gas leakage detection systems

Smart home safety devices

Industrial safety monitoring
