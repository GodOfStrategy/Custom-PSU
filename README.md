# Custom Programmable Bench Power Supply

## About This Project

This project is my attempt at designing a fully programmable bench power supply from the ground up.

Most hobbyist power supplies are either simple fixed-voltage supplies or rely heavily on pre-built modules. I wanted to understand the entire system myself, from power conversion and feedback control to measurement, user interface, and digital regulation. The result is a custom-designed power supply capable of generating an adjustable output of approximately 0V to 30V at up to 5A from a standard 12V DC adapter.

The design combines modern switching power electronics with digital control, allowing the power supply to behave more like a commercial laboratory instrument than a traditional adjustable supply.

---

# Motivation
I love watching ElectroBOOM and he loves to blow up capacitors so I got some FOMO and needed a way to safely blow some capacitors up! (jk)
During electronics prototyping, I often found myself needing different voltages and current limits depending on the project being tested. Instead of purchasing a commercial bench supply, I decided to design one myself.

The primary objectives were:

- Wide adjustable voltage range
- Current limiting capability
- Digital control instead of analog potentiometers
- Real-time voltage and current monitoring
- Large and readable displays
- USB connectivity for future expansion
- Learning advanced power electronics in the process

This project was intended not only as a practical tool but also as a way to gain hands-on experience with high-power DC-DC converter design.

---

# Design Goals

| Parameter | Target |
|------------|------------|
| Input Voltage | 12V DC |
| Output Voltage | ~0V - 30V |
| Maximum Current | 5A |
| Maximum Power | 150W |
| Regulation Method | Digital |
| User Interface | Rotary Encoders |
| Display | LED 7-Segment Displays |
| Communication | USB |

---

# System Overview

The power supply can be divided into several major sections:

1. Power Input and Protection
2. Power Conversion
3. Measurement System
4. Control Electronics
5. User Interface

The overall concept is shown below:

```text
12V Adapter
     │
     ▼
Input Protection
     │
     ▼
Buck / Boost Power Stage
     │
     ▼
Current & Voltage Measurement
     │
     ▼
Microcontroller Control Loop
     │
     ├── DAC Voltage Control
     ├── Display Interface
     ├── USB Communication
     └── User Input
     │
     ▼
 Adjustable Output
     0V - 30V @ 5A
```

---

# Power Conversion

One of the biggest challenges in the project is that the output voltage can be significantly higher than the input voltage.

Since the system is powered from a 12V adapter but needs to produce up to 30V at the output, a boost-capable power architecture is required.

The power stage is built around:

- LM5116 synchronous controller
- LM51231 synchronous boost controller
- High-current MOSFETs
- Shielded power inductors
- Precision current sensing

These components allow efficient conversion while minimizing heat generation.

The theoretical maximum output power was designed around:

```text
30V × 5A = 150W
```

making the supply suitable for most low- and medium-power electronics projects.

---

# Digital Control

Rather than using traditional potentiometers for voltage adjustment, this design uses a digital control system.

At the center of the project is an:

### ATmega328P

The microcontroller is responsible for:

- Reading user inputs
- Monitoring output voltage/current
- Controlling the output setpoint
- Driving the displays
- Managing system behavior

This allows settings to be consistent, repeatable, and expandable through software.

---

# Digital Voltage Regulation

Output voltage adjustment is performed using an MCP4725 12-bit DAC.

Instead of physically changing a potentiometer, the microcontroller generates a precise reference voltage that controls the converter feedback loop.

This approach enables:

- Fine output adjustment
- Accurate calibration
- Software-defined voltage control
- Future preset storage functionality

---

# Measurement and Monitoring

A bench power supply is only useful if the user can see exactly what is happening at the output.

To achieve this, the design includes an INA260 power monitor.

The INA260 measures:

- Output voltage
- Output current
- Output power

These measurements are available digitally through I²C and can be displayed directly to the user.

This reduces complexity while improving overall measurement accuracy.

---

# User Interface

The user interface was designed to feel similar to a commercial bench power supply.

## Input Controls

Two EC11 rotary encoders are used for:

- Voltage adjustment
- Current limit adjustment
- Menu navigation

Rotary encoders were chosen because they allow precise control without requiring multiple buttons or large potentiometers.

---

## Display System

The display system uses:

- 3 × MAX7219 display drivers
- 3 × large seven-segment LED displays

The intended display arrangement is:

### Display 1
Output Voltage

### Display 2
Output Current

### Display 3
Additional information such as:

- Power
- Current limits
- Menu settings
- Calibration data

The large displays were selected for visibility and ease of use from across a workbench.

---

# Connectivity

USB support is provided through a CH340G USB-to-UART converter.

This opens possibilities for:

- Firmware updates
- Serial debugging
- Data logging
- Computer-based monitoring
- Future remote control functionality

While not essential for operation, USB greatly expands the potential capabilities of the power supply.

---

# Protection Features

Reliability and safety were important considerations throughout the design.

The PSU includes:

- TVS diodes for surge suppression
- Polyfuse protection
- Current monitoring
- Precision current sensing
- Input filtering
- Noise suppression through ferrite beads

These features help protect both the power supply and any connected loads.

---

# What I Learned

This project exposed me to several advanced engineering topics, including:

- High-power DC-DC converter design
- Switching power supply compensation
- Current sensing techniques
- Digital control of analog systems
- PCB layout for power electronics
- Mixed-signal design
- Microcontroller firmware integration


---

# Final Thoughts

This project was designed as much for learning as it was for practicality. The goal was not simply to build another adjustable power supply, but to understand how a modern digitally controlled laboratory PSU is designed from the component level upward.

From the switching converters and measurement circuitry to the display system and firmware-controlled regulation, every major subsystem was intentionally designed and integrated into a single platform. The result is a custom programmable bench power supply capable of delivering up to 30V and 5A while providing a user experience similar to that of commercial laboratory equipment.