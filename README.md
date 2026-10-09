
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
This is what my Schematics are:<img width="992" height="706" alt="image" src="https://github.com/user-attachments/assets/940f5a36-26cc-49d0-92cb-4b0b9f444025" />
My PCB 1: <img width="1136" height="808" alt="image" src="https://github.com/user-attachments/assets/f67dfec9-7e2b-4582-9b87-fb185ff89411" />
This is how my assembled PCB is supposed to look like:<img width="775" height="583" alt="image" src="https://github.com/user-attachments/assets/b9cee57a-1dd5-4796-bfe4-ae0873af3c6f" />
My PCB 2 Schematics: <img width="1012" height="507" alt="image" src="https://github.com/user-attachments/assets/89664a26-3bea-422d-86d6-d74da3a49a03" />
My second PCB design:<img width="802" height="801" alt="image" src="https://github.com/user-attachments/assets/d3ce81d4-88bd-4bde-b472-731fd6fc09be" />
My second PCB assembled Look:<img width="758" height="757" alt="image" src="https://github.com/user-attachments/assets/ccc91687-56f0-44ed-a58b-bb29668ef952" />
How my Case and the finished product is supposed to look:
<img width="780" height="800" alt="image" src="https://github.com/user-attachments/assets/9342a92f-a7f2-4732-b25c-41be29fbdc78" />
<img width="686" height="822" alt="image" src="https://github.com/user-attachments/assets/4ae548f6-94f7-435b-b121-8e6bd0e4b150" />
<img width="503" height="677" alt="image" src="https://github.com/user-attachments/assets/df9c3501-745c-4bb7-b33d-4da8079fb5f0" />

BOM:
# Bill of Materials (BOM)

| Designator(s) | Component | Quantity | Description | Source |
|--------------|------------|----------|-------------|---------|
| U1 | ATmega328P | 1 | Main microcontroller | Robu.in |
| U2 | CH340G | 1 | USB-to-UART interface | JLCPCB |
| U3 | MCP4725A0T-E/CH | 1 | 12-bit DAC for voltage control | Robu.in |
| U4 | INA260 | 1 | Voltage, current, and power monitor | JLCPCB |
| U5 | LM5116MHX | 1 | Synchronous buck controller | JLCPCB |
| U6 | LM51231QRGRRQ1 | 1 | Synchronous boost controller | JLCPCB |
| U11 | TPS54202DDCR | 1 | Auxiliary buck regulator | Robu.in |
| U8, U9, U10 | MAX7219M/TR | 3 | LED display drivers | JLCPCB |
| Q1, Q2, Q5, Q6 | SI7850DP | 4 | Power MOSFETs | Robu.in |
| Q3, Q4 | BSC014N06NS | 2 | Boost stage power MOSFETs | JLCPCB |
| L1 | 10 µH Inductor | 1 | Power filtering inductor | JLCPCB |
| L2 | 8.2 µH Inductor | 1 | Main buck converter inductor | JLCPCB |
| L3 | 6 µH Inductor | 1 | Boost converter inductor | JLCPCB |
| D1, D2 | SMBJ33A | 2 | TVS surge protection diodes | JLCPCB |
| D3 | CMPD2003 | 1 | Signal diode | JLCPCB |
| U7 | 2920L500/30GR | 1 | Resettable polyfuse | JLCPCB |
| DC1 | DC-005-A200 | 1 | DC barrel jack input | JLCPCB |
| J1 | USB Type-C Receptacle | 1 | USB connectivity | JLCPCB |
| J2, J4, J5 | 2×6 Pin Header | 3 | Expansion/programming headers | JLCPCB |
| J3 | 2-Pin Screw Terminal | 1 | PSU output connector | JLCPCB |
| J6, J7 | 1×3 Pin Header | 2 | Auxiliary headers | JLCPCB |
| Y1 | 16 MHz Crystal | 1 | ATmega328P clock source | JLCPCB |
| Y2 | 12 MHz Crystal | 1 | CH340G clock source | JLCPCB |
| SW1, SW2 | EC11 Rotary Encoder | 2 | User input controls | JLCPCB |
| SW3 | RS601A-1020013BB | 1 | Power/control switch | JLCPCB |
| LED1, LED2, LED3 | SR420561N | 3 | Seven-segment LED displays | JLCPCB |
| FB1 | Ferrite Bead | 1 | EMI suppression | JLCPCB |
| FID1, FID2, FID3 | Fiducials | 3 | PCB assembly alignment markers | JLCPCB |
| All Capacitors (C1–C41) | Mixed Values | 41 | Decoupling, filtering, compensation, and bulk storage capacitors | JLCPCB |
| All Resistors (R1–R31) | Mixed Values | 31 | Feedback, sensing, compensation, pull-ups, and current measurement | JLCPCB |

---

## Custom Components Procured Separately

| Component | Quantity | Source | Product Link |
|------------|----------|---------|-------------|
| SI7850DP MOSFET | 4 | Robu.in | https://robu.in/product/si7850dp-xblw-60v-30a-34-7w-25m%CF%8910v15a-1-2v250ua-1-n-channel-dfn-8l5x6-mosfets-rohs/ |
| ATmega328-PU | 2 | Robu.in | https://robu.in/product/atmega328-pu-microchip-8-bit-microcontroller-avr-atmega-family-atmega328-series-microcontrollers-20-mhz-1-kb-32-kb/ |
| TPS54202DDCR | 2 | Robu.in | https://robu.in/product/tps54202ddcr-texas-instruments-step-down-type-adjustable-2a-4-5v28v-sot-23-6-dc-dc-converters-rohs/ |
| MCP4725A0T-E/CH | 2 | Robu.in | https://robu.in/product/mcp4725a0t-e-ch-microchip-tech-6us-i2c-2lsb-2-7v5-5v-12-sot-23-6-digital-to-analog-converters-dac-rohs/ |

---

## Manufacturing Cost

| Item | Cost |
|--------|--------:|
| PCB Fabrication | $4.00 |
| PCB Assembly (PCBA) | $165.19 |
| Shipping | $18.54 |
| **Total JLCPCB Cost** | **$187.73** |

---

## External Component Cost

| Source | Cost |
|---------|------:|
| Robu.in Components | $17.69 |

---

## Project Totals

| Category | Quantity |
|-----------|---------:|
| Integrated Circuits | 10 |
| MOSFETs | 6 |
| Diodes | 3 |
| Inductors | 3 |
| Crystals | 2 |
| Connectors | 7 |
| Displays | 3 |
| Rotary Encoders | 2 |
| Switches | 1 |
| Capacitors | 41 |
| Resistors | 31 |
| Protection Devices | 3 |

---

# Final Project Cost

| Cost Component | Total |
|----------------|--------:|
| JLCPCB Manufacturing (PCB + PCBA + Shipping) | $187.73 |
| Robu.in Components | $17.69 |
| **Total Project Cost** | **$205.42** |
