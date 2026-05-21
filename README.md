# Fruit Sorting Gantry Robot - Initial Scaffold

This repository now contains a clean, minimal architecture scaffold for a fruit-sorting gantry robot:

- `pi_controller`: Raspberry Pi main controller (`C`) with finite state machine.
- `gantry_controller`: Arduino Uno + CNC Shield + GRBL integration placeholder.
- `claw_controller`: Seeeduino PlatformIO project scaffold.
- `shared_protocol`: shared serial command constants.
- `tests`: mock-mode FSM smoke test.
- `docs`: architecture and serial protocol documents.

## Current Scope

This is **scaffold only** (no full hardware functionality yet).

- FSM states and transitions are defined.
- Hardware interfaces are abstracted.
- Mock implementations are provided for local testing.
- TODO markers identify where real hardware integration must be added.
- `serial_router` isolates FSM logic from direct serial command details.

## Quick Start

Build and run Raspberry Pi mock controller:

```bash
make pi
cd pi_controller && ./pi_controller_app
```

Run smoke test:

```bash
make tests
```

## State Machine

Implemented scaffold states:

1. `IDLE`
2. `WAIT_FOR_FRUIT`
3. `READ_WEIGHT`
4. `DECIDE_BOX`
5. `MOVE_TO_FRUIT`
6. `CLOSE_CLAW`
7. `CHECK_GRIP`
8. `MOVE_TO_BOX`
9. `OPEN_CLAW`
10. `RETURN_HOME`
11. `ERROR_STATE`

## Next Hardware Steps

- Wire Raspberry Pi serial ports to GRBL and Seeeduino.
- Implement real serial driver in `pi_controller/src/serial_posix.c`.
- Replace mock behavior in `pi_controller/src/serial_router.c`.
- Add GRBL machine configuration and calibration values.

## Serial Router Layer

`pi_controller/src/serial_router.c` is the single routing layer between FSM and serial devices.

- FSM uses high-level calls (`gantry_move_to`, `gantry_home`, `claw_open`, `claw_close`, `claw_read_pressure`).
- Router decides mock vs real serial using `SERIAL_ROUTER_USE_MOCK` (default: mock enabled).
- In mock mode, actions return deterministic simulated values.
- In real mode, TODO-marked sections will send/receive USB serial frames to GRBL and the claw board.

This keeps state logic clean and hardware code localized.
