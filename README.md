# Grow Room Automation (Arduino + Home Assistant)

Automate your grow room with Arduino and Home Assistant!  
- **Features**: Motion-triggered lighting, sound event logging, constant temperature & humidity monitoring.
- **Integrates**: Arduino UNO (DFRobot v3.0), DHT11, PIR sensor, sound sensor, Sonoff 3ch switch, I/O expansion, and Home Assistant.

---

## Features

- 🕴️ **Motion Detection**: PIR sensor detects movement.  
- 💡 **Automatic Light Control**: Light (via Sonoff 3ch on Home Assistant) switches on when motion is detected.
- 🎙 **Sound Recording**: Log/record sound events when motion occurs.
- 🌡️ **Temp/Humidity Monitoring**: Constant DHT11 monitoring (display via serial, expandable for logging/dashboard).
- 🔗 **Network Control**: Easily communicates with Home Assistant for automations.

## Hardware List

- Arduino UNO (DFRobot v3.0)
- I/O Expansion Shield V7.1 (with XBee S1 installed)
- PIR Motion Sensor v1.0 (connected to D13)
- DHT11 Temperature & Humidity Sensor (connected to D12)
- Analog Sound Sensor v2.2 (A0)
- Sonoff 3CH Switch (controlled via Home Assistant)
- (Optional): XBee S1 (for wireless/logging, not used in base code)

## Wiring Summary

| Sensor/Module   | Arduino Pin (Shield)          |
|-----------------|------------------------------|
| PIR             | Digital Pin D13              |
| DHT11           | Digital Pin D12              |
| Sound Sensor    | Analog Pin A0                |

All components plug into the I/O expansion shield, which mounts on the Arduino. The XBee module sits on the shield’s XBee socket. The Arduino connects to your PC with USB. Adjust pins above if needed for your shield version.

## Setup

### Arduino
1. Connect the hardware as described above.
2. Download libraries (`DHT.h` for DHT11, e.g. via Library Manager).
3. Upload `Arduino/growroom_automation.ino` to your Arduino UNO.

### Home Assistant
- Import the automation YAML example (`home-assistant/automation_light.yaml`) to automate lights via Sonoff and motion events.

### Serial Monitoring
- The Arduino sends current temp/humidity, motion, and sound detection logs via Serial.

---

## Project Structure

```
├── Arduino/
│   └── growroom_automation.ino
├── home-assistant/
│   └── automation_light.yaml
├── README.md
└── docs/
    └── hardware-connections.png  (add a schematic if available)
```

---

## License

MIT License (add LICENSE file as needed)