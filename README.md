# Smart LED Display
This is the firmware for a smart LED display. The display consists of a 54 x 18 LED grid using red 5mm LEDs, 74HC595 shift registers, and 4017 decade counters as well additionall hardware for the timing circuitry, hardware I/O, and with the server microctonroller.

> Design goals, why did I build this project?
 
When deciding on this project there were 3 specific learning objectives I wanted to achieve:
1) Most of my previous projects were largely software and I wanted experience with electronic circuit design on a much larger scale than I had done previously
2) Create a peice of software designed specifically to act as firmware using C
3) Create a project that uses multiple microcontrollers for specific functions
After deciding on this project and working through it I decided on the following goals as well:
1) Gain experience creating hardware interfaces such as USB, ethernet/RJ-45, and/or RS-232

# The Hardware
- 972 red 5mm LEDs
- 7x 74HC595 shift registers
- 2x CD4017 decade counters
- 1x 74HC00 / CD4011 4x NAND gate
- 3.579545MHz Crystal OSC
- PIC1845K22 8-bit microcontroller

***Hardware currently being tested:***
- STM32 Blackpill microcontroller
- various flip-flip and binary counter IC's for the timing circuit

# Where is the project now?

> Recent Updates
- Initial commit with the PIC controlling 

> ToDo / Upcoming features
- Removing control of timing from the PIC and instead using a hardware circuit and interrupts on the PIC.
- Addition of basic transition features and dynamic effects over time
- Hardware intergration for:
  - Serial
  - USB
  - Programmable plug (Possibly using DB9, RJ45, JST-XH, or dupont)
- Interface with a network based microcontroller. PIC functions strictly as graphics processor.
- Start doing what this is all been for, have fun! Be creative! Some ideas I've had have been:
  - Video games controlled by:
    - RF / Wifi / BT using a custom remote controller
    - Serial
    - Custom glove/interface using MPU-6050

# Lessons learned
- There are ICs or special LEDs with built in microcontrollers for individual addressing, such as the SK6812, which can

# Next generation
- PCB based LED panel as well as hardware
- RGBW LEDs instead of monochrome
  - Reassment of indivudually addressable LEDs vs 16x PWM output type ICs while continuing to use multiplexing
