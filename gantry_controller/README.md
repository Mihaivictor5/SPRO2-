# Gantry Controller (Arduino Uno + CNC Shield + GRBL)

This module represents the XY gantry controller side.

- Runs GRBL firmware on Arduino Uno.
- Receives G-code from Raspberry Pi over USB serial.
- Handles homing and motion planning inside GRBL.

## Setup (placeholder)

1. Flash GRBL to Arduino Uno.
2. Set machine parameters (`$100`, `$101`, max travel, etc.).
3. Connect CNC shield stepper drivers and limit switches.

## Notes

- Raspberry Pi is the main state machine owner.
- This folder only keeps project-level scaffold docs and scripts.
