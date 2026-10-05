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

