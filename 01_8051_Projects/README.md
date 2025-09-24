# 8051 Projects
This folder will contain some 8051-based projects.

- Each project folder contains source (`.c` / `.asm`) and header files.
- `common/` may include shared drivers, utility functions, or hardware abstraction code across multiple projects.
- Each project ideally has its own `README.md` explaining how to build, configure, and run it.

## Building & Running  

### Prerequisites  
- 8051-compatible compiler toolchain (e.g. Keil µVision, SDCC, or other)  
- Programmer / simulator for the 8051 microcontroller  
- Target 8051 board or emulator  

### Steps  
1. Open the project in your preferred IDE or load the makefile.  
2. Configure the target microcontroller settings (e.g. crystal frequency, memory model).  
3. Build / compile the code.  
4. Flash / upload the resulting hex / bin file to the 8051 board.  
5. Connect any required peripherals (LEDs, UART, sensors) as per the project schematic.  
6. Power up the board and observe/validate the behavior.

## Example Usage  

For example, in a “Hello UART” project:

- After flashing the firmware, open a serial terminal at the configured baud rate (e.g. 9600, 8N1).  
- You should receive the string `"Hello from 8051!"` periodically on the terminal.  

In a “LED Blink with Timer” project:

- An LED connected to a GPIO pin will toggle every 500 ms using Timer interrupt.

## Contribution & Extensions  
You or future contributors can add more 8051-based projects—for example:  
- Motor control (stepper, servo)  
- Wireless communication   
- Display modules (LCD)  
- IoT bridging (UART ↔ ESP8266 / ESP32 as WiFi / MQTT link)

Make sure to add a `README.md` inside each new project folder describing hardware connections, configuration, and usage.

## License  
This repository follows the licensing terms as described in the root `LICENSE` file of the main project. Unless otherwise stated, use is on an “AS-IS” basis.
