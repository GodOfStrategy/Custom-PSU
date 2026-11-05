# 2026-06-28: Finished CAD

**Total time spent: 30 minutes**
# Custom Programmable Bench Power Supply

## About This Project

This project is my attempt at designing a fully programmable bench power supply from the ground up.

Most hobbyist power supplies are either simple fixed-voltage supplies or rely heavily on pre-built modules. I wanted to understand the entire system myself, from power conversion and feedback control to measurement, user interface, and digital regulation. The result is a custom-designed power supply capable of generating an adjustable output of approximately 0V to 30V at up to 5A from a standard 24V DC adapter.

The design combines modern switching power electronics with digital control, allowing the power supply to behave more like a commercial laboratory instrument than a traditional adjustable supply.

---

# Motivation

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
| Input Voltage | 24V DC |
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
24V Adapter
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

More than anything, it demonstrated how many different disciplines come together in a single real-world electronic product.

---

# Future Improvements

If this design were to be revised, possible improvements would include:

- Constant Current (CC) and Constant Voltage (CV) operating modes
- Fan and thermal management
- Preset storage
- OLED or TFT menu system
- USB software interface
- Data logging
- Remote programming
- Output relay control
- Calibration menu

---

# Final Thoughts

This project was designed as much for learning as it was for practicality. The goal was not simply to build another adjustable power supply, but to understand how a modern digitally controlled laboratory PSU is designed from the component level upward.

From the switching converters and measurement circuitry to the display system and firmware-controlled regulation, every major subsystem was intentionally designed and integrated into a single platform. The result is a custom programmable bench power supply capable of delivering up to 30V and 5A while providing a user experience similar to that of commercial laboratory equipment.

---
title: "Custom Bench Power Supply"
author: "shaurya11.baitule"
description: "A custom bench power supply to blow up capacitors ; ) "
created_at: "2026-06-05"
---

# 2026-06-28: Finished CAD

**Total time spent: 2 hours 10 minutes**

[content missing due to database mishap]

# 2026-06-24: CAD

**Total time spent: 2 hours 21 minutes**

[content missing due to database mishap]

# 2026-06-23: 3d Modelling

**Total time spent: 2 hours 18 minutes**

[content missing due to database mishap]

# 2026-06-22: JLCPCBA

**Total time spent: 58 minutes**

[content missing due to database mishap]

# 2026-06-21: Finished PCB+JLCPCB qoute

**Total time spent: 2 hours 13 minutes**

[content missing due to database mishap]

# 2026-06-20: PCB.............

**Total time spent: 1 hour 16 minutes**

[content missing due to database mishap]

# 2026-06-19: More PCB!

**Total time spent: 55 minutes**

Routed the Buck and its peripherals, also gave a though on how I am going to wire the Banana Jack, and I decided that just like the 7 segment displays, I will run it through 2 wires separate from the PCB, so that I can mount it onto the main face plate of my case when I build one. Thats it for today, the link for the jack and its connector /adapter are below along with the lapse.

Banna Jack- https://www.amazon.in/Electronic-Spices-Binding-Terminal-Amplifier/dp/B0DSJH277R/ref=pd_sbs_d_sccl_2_4/525-3724482-2774332?pd_rd_w=yP47I&content-id=amzn1.sym.d1406b44-aa69-47e4-9270-f613e12d52dc&pf_rd_p=d1406b44-aa69-47e4-9270-f613e12d52dc&pf_rd_r=SM57Z9HM59FYX4WFSXNW&pd_rd_wg=ssXon&pd_rd_r=edf089d4-948e-4d24-8527-9e297d67e865&pd_rd_i=B0DSJH277R&psc=1

Banna jack to alligator- https://www.amazon.in/CentIoT-Banana-Alligator-Crocodile-Probes/dp/B0CPV4W386/ref=bmx_dp_d_sccl_1_4/525-3724482-2774332?pd_rd_w=P9GgW&content-id=amzn1.sym.a5646ec7-a2de-49f1-8d39-15f8f2eef501&pf_rd_p=a5646ec7-a2de-49f1-8d39-15f8f2eef501&pf_rd_r=SM57Z9HM59FYX4WFSXNW&pd_rd_wg=ssXon&pd_rd_r=edf089d4-948e-4d24-8527-9e297d67e865&pd_rd_i=B0CPV4W386&psc=1
https://lapse.hackclub.com/timelapse/oVXfl4zkjr_p![{DF3716FD-FD87-465C-B160-F26AF21B82D1}.png](https://cdn.hackclub.com/019ee095-b2a8-7dcf-bd7c-99cb4f818a63/%7BDF3716FD-FD87-465C-B160-F26AF21B82D1%7D.png)

# 2026-06-18: More routing

**Total time spent: 46 minutes**

[content missing due to database mishap]

# 2026-06-17: Started PCB

**Total time spent: 1 hour 10 minutes**

[content missing due to database mishap]

# 2026-06-16: Footprint assignment issues

**Total time spent: 33 minutes 49 seconds**

[content missing due to database mishap]

# 2026-06-15: Actually completed scheamtics

**Total time spent: 1 hour 2 minutes 30 seconds**

[content missing due to database mishap]

# 2026-06-12: Finished Schematics

**Total time spent: 1 hour**

[content missing due to database mishap]

# 2026-06-10: More schematics

**Total time spent: 1 hour 10 minutes**

[content missing due to database mishap]

# 2026-06-09: LM51232

**Total time spent: 1 hour 14 minutes**

[content missing due to database mishap]

# 2026-06-08: Further schematics

**Total time spent: 2 hours 36 mintes**

[content missing due to database mishap]

# 2026-06-07: Started schematics and added a few more components

**Total time spent: 5 hours 30 minutes**

[content missing due to database mishap]

# 2026-06-06: Proj init

**Total time spent: 10 mins**

[content missing due to database mishap]

# 2026-06-05: Rough Idea of the project and Parts needed

**Total time spent: 1 hour 30 minuts**

So, I was wondering what a useful project could be, and then I remembered that ElectroBOOM blows up capacitors in his free time. And I want to do the same, but he has a bench ps and I dont :( and I cannot use 220VAC at my home (too dangerous). So I now want to make my own Bench Power Supply (❁´◡`❁) and blow some capacitors up! (jk blwoing capacitors is just a fun feature, but the main purpose is building hardware and testing it in the prototyping stage).
So I chose the following components for my Bench PSU ƪ(˘⌣˘)ʃ:
Buck regulator ICs (LM5116, LTC3891).

Boost regulator ICs (LM5122, LTC3787).

DACs (MCP4725A0T‑E/CH) for setpoints.

ADC/monitors (ADS1115, INA219) for precision measurement.

Microcontroller (ATmega328‑PU) for control/UI.

Now you might ask why am I choosing so many ICs? the plan behind this is that I will be using a step down and ac to dc adapter (https://www.amazon.in/Shapure-Adapter-Purifier-Converter-Warranty/dp/B09B2QC5DG/ref=sr_1_3?crid=SXV7ZEUICP5O&dib=eyJ2IjoiMSJ9.nV5FOm1ZurNoh01-sMJr8a6H3QZrpVkPC7r3a1uMubQwvwDpYeVtdGvyapmM14N_cyx8Cl-erGWK1lr773Fw0kb7-f7gLJIuiKB82Y6F90Zvb1QcIbULg8SbCgHNL3PZOexi0mFf7kuhzpqZ21PiLugDfAAI-VlePijXj6Tlet9JFarWpEv0li-h3kDRcGkUnxHy79d702CaeNg3m-L-277ABvumrJv20Ij3A63llg0.SWjZzbYLb28lcM3UgNHs0CCFPtrwOhdNJO3bJtU9o-M&dib_tag=se&keywords=ac%2B240%2Bto%2Bdc%2B24V%2Badapter&qid=1780663996&sprefix=ac%2B240%2Bto%2Bdc%2B24v%2Badapte%2Caps%2C305&sr=8-3&th=1), that will output 24V at 2.5A (because transformers are too dangerous to be making yourself 💀) and I want Voltage, Current control (with precise adjustments up to 0.1V/A) with the output of the bench PSU being 1V-30V DC with 5A of output!! that is 150W max powerrrrrrrrr!!

So I did some LCSC scouting to make sure the ICs I aim to use are in stock![image.png](https://cdn.hackclub.com/019e9803-e25b-79c0-a15b-7678df1e4fc2/image.png) like this. And called it a day for today. 
^_____^

