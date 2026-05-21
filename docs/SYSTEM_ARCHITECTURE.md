# System Architecture

## Overview

The system uses a simple split-controller architecture:

- **Raspberry Pi (`C`)**: owns application logic and state machine.
- **Arduino Uno + GRBL**: executes XY gantry motion via G-code.
- **Seeeduino (PlatformIO)**: controls claw open/close and status.
- **USB serial links**: communication between Pi and both microcontrollers.

## Module Responsibilities

### `pi_controller`
- High-level finite state machine and workflow.
- Decision logic (e.g., select target box by fruit weight).
- Abstraction layer for hardware actions.
- Mock mode for development without hardware.

### `gantry_controller`
- GRBL runtime host for motion control.
- Accepts G-code commands over serial.
- Handles homing and movement planning internally.

### `claw_controller`
- Parses simple serial commands (`CLAW:CLOSE`, `CLAW:OPEN`, etc.).
- Reports acknowledgements and current claw status.

### `shared_protocol`
- Shared constants for serial command strings and responses.

## Design Notes

- Keep files small and responsibilities clear.
- Keep protocol text-based for easy debugging.
- Keep hardware-specific code isolated behind interfaces.
- Keep FSM explicit and readable (switch-case).
