# rpi-driver-collection

## Raspberry Pi Driver Collection

[![Linux](https://img.shields.io/badge/Linux-6.x-blue.svg)]()
[![Language](https://img.shields.io/badge/Language-C-orange.svg)]()
[![Platform](https://img.shields.io/badge/Platform-Raspberry%20Pi-red.svg)]()
[![License](https://img.shields.io/badge/License-MIT-green.svg)]()

A collection of Linux Device Drivers developed for Raspberry Pi and Embedded Linux systems.

This repository documents my journey through Linux Kernel and Device Driver Development, starting from simple kernel modules and progressing to more advanced drivers such as GPIO, PWM, I2C, SPI, UART, Device Tree and Ethernet.

The goal is to provide practical examples, learning resources and reusable driver implementations for embedded Linux development.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Platform](#hardware-platform)
- [Repository Structure](#repository-structure)
- [Driver Roadmap](#driver-roadmap)
- [Getting Started](#getting-started)
- [Building Drivers](#building-drivers)
- [Loading a Driver](#loading-a-driver)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

---

# Overview

Linux device drivers are responsible for enabling communication between the operating system and hardware peripherals.

This repository focuses on:

- Linux Kernel Programming
- Character Device Drivers
- GPIO Programming
- Interrupt Handling
- Timers and Workqueues
- PWM Subsystem
- I2C Drivers
- SPI Drivers
- UART Drivers
- Device Tree Integration
- Network Drivers
- Ethernet Drivers

Each driver includes:

- Source code
- Build instructions
- Usage examples
- Technical documentation
- Architecture diagrams

---

# Features

✅ Linux Kernel Modules

☐ Character Device Drivers

☐ GPIO Drivers

☐ Interrupt Handlers

☐ Timers

☐ Workqueues

☐ PWM Drivers

☐ I2C Drivers

☐ SPI Drivers

☐ UART Drivers

☐ Device Tree Examples

☐ Ethernet Drivers

☐ Raspberry Pi Support

---

# Hardware Platform

Current development targets:

| Board |
|---------|
| Raspberry Pi 4 |
| Raspberry Pi 5 |

Supported Linux versions:

```text
Linux Kernel 6.x
```

---

# Repository Structure

```text
rpi-driver-lab/
│
├── docs/
│   ├── architecture/
│   ├── diagrams/
│   └── tutorials/
│
├── drivers/
│   ├── 01-first-driver/
│   ├── 02-char-driver/
│   ├── 03-gpio/
│   ├── 04-interrupts/
│   ├── 05-timers/
│   ├── 06-workqueues/
│   ├── 07-pwm/
│   ├── 08-i2c/
│   ├── 09-spi/
│   ├── 10-uart/
│   ├── 11-device-tree/
│   ├── 12-network/
│   └── 13-ethernet/
│
├── projects/
│
├── scripts/
│
├── README.md
└── LICENSE
```

---

# Driver Roadmap

## Beginner

- [x] Hello World Kernel Module
- [ ] Character Driver
- [ ] GPIO Control
- [ ] GPIO Interrupts

## Intermediate

- [ ] Timers
- [ ] Workqueues
- [ ] PWM Driver
- [ ] Device Tree Integration

## Advanced

- [ ] I2C Driver
- [ ] SPI Driver
- [ ] UART Driver
- [ ] Network Driver
- [ ] Ethernet Driver

## Future Goals

- [ ] CAN Bus Driver
- [ ] USB Device Driver
- [ ] DMA Support
- [ ] Yocto Integration
- [ ] Buildroot Integration

---

# Getting Started

Clone the repository:

```bash
git clone https://github.com/<your-user>/rpi-driver-lab.git
```

Enter the project directory:

```bash
cd rpi-driver-lab
```

---

# Building Drivers

Example:

```bash
cd drivers/01-first-driver

make
```

Expected output:

```text
first_driver.ko
```

---

# Loading a Driver

Insert module:

```bash
sudo insmod first_driver.ko
```

Check kernel messages:

```bash
dmesg | tail
```

Remove module:

```bash
sudo rmmod first_driver
```

---

# Design Philosophy

This repository follows a progressive learning approach.

Instead of presenting only final implementations, drivers are organized from basic to advanced concepts, allowing readers to understand how Linux drivers evolve from simple kernel modules to complete hardware interfaces.

The objective is not only to provide working code but also to explain the design decisions behind each implementation.

---

# Example Learning Path

```text
Kernel Module
      │
      ▼
Character Driver
      │
      ▼
GPIO
      │
      ▼
Interrupts
      │
      ▼
PWM
      │
      ▼
I2C / SPI / UART
      │
      ▼
Network Driver
      │
      ▼
Ethernet Driver
```

---

# Documentation

Documentation is available inside the `docs/` directory.

Topics include:

- Linux Kernel Basics
- Driver Development Workflow
- Device Tree
- Raspberry Pi Hardware
- Debugging Techniques
- Driver Architecture

---

# Contributing

Contributions, bug reports and feature requests are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Submit a Pull Request

---

# References

The learning process follows the path laid out by the  [Linux Device Driver Tutorials](https://embetronicx.com/linux-device-driver-tutorials/) from EmbetronicX.

Thank you for your great work ! 

And be sure to check out his work on [GitHub](https://github.com/Embetronicx/Tutorials/tree/master/Linux/Device_Driver) as well. 


---

# License

This project is licensed under the MIT License.

See the LICENSE file for details.

---

## Author

Embedded Linux & Kernel Development Portfolio Project

If you find this repository useful, consider giving it a ⭐.
