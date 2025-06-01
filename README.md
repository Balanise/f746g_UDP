# STM32F746G UDP Dummy Data Sender

This project demonstrates how to send dummy UDP packets from the STM32F746G Discovery board to a target device (e.g., a PC). The data is sent in a `Counter: N` format every second, useful for testing embedded Ethernet or network interfaces.

## Features

- Sends incremental counter values over UDP (e.g., `Counter: 1`, `Counter: 2`, ...)
- Fixed 1-second interval transmission using `HAL_GetTick`
- Lightweight and reusable UDP socket handling with LWIP

## Hardware

- STM32F746G-DISCO
- Ethernet cable connection to router

## Software Used

- STM32CubeMX
- STM32CubeIDE
- LWIP middleware
- Ncat

![UDP Output Example](<Ekran görüntüsü 2025-05-31 214628.png>)


