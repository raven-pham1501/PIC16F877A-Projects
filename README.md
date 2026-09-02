# PIC16F877A Projects

A learning repository for the **PIC16F877A** microcontroller, built and tested with **Visual Studio Code**. The goal is to progress from single-peripheral experiments to complete, product-like applications, with each stage building on the skills learned in the previous one.

## Overview

| | |
|---|---|
| **Target MCU** | PIC16F877A |
| **Editor** | Visual Studio Code |
| **Compiler / Toolchain** | Microchip XC8 (MPLAB toolchain) |
| **Language** | Embedded C |
| **Purpose** | Structured, hands-on learning of the PIC16F877A peripherals and their use in real applications |
| **DevKit** |A: KIT-PIC-V1.2-BLK |

## Repository Structure

The projects are organized into five parts, ordered by increasing complexity and integration.

### Part I — Single Peripheral Modules

Standalone projects that explore one peripheral or module at a time (e.g. GPIO, Timer, ADC, UART, PWM, I2C, SPI, LCD, Interrupts). Each project is kept minimal and focused so the behavior of that one module is easy to isolate and understand.

- PIC1_01_CooperativeOS_StupidOS
- _(to be added)_

### Part II — Integrating Multiple Modules

Projects that combine two or more peripherals from Part I to build small interacting systems (e.g. ADC + UART, Timer + PWM, I2C + LCD). The focus here is on how modules work together and how to structure code cleanly as complexity grows.

- _(to be added)_

### Part III — Small Specific Applications

Small, purpose-built applications that solve one clear task, built on top of the integrated modules from Part II (e.g. a simple data logger, a sensor reader, a basic motor speed controller).

- _(to be added)_

### Part IV — Specific Applications

Larger, more complete applications with more realistic requirements — closer to what a real embedded task would demand (e.g. multi-sensor monitoring, communication with a host, closed-loop control).

- _(to be added)_

### Part V — Complete Products

End-to-end, product-like projects that bring together hardware design, firmware architecture, and application logic into a finished, demonstrable system.

- _(to be added)_

## How to Use This Repository

1. Open a project folder in **Visual Studio Code**.
2. Build with the Microchip **XC8** compiler and flash it to a PIC16F877A target board (via PICkit or equivalent programmer).
3. Refer to each project's own notes/comments for wiring and configuration details.
4. Work through the parts in order (I → V) for a progressive learning path, or jump to whichever part matches your current focus.

## Status

This repository is actively being built out as part of an ongoing self-study process. Project lists in each part will be filled in as they are completed.

## License

MIT
