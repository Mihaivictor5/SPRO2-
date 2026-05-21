# Serial Protocol (Scaffold v0)

This document defines the initial text-based serial protocol between controllers.

## Transport

- ASCII lines terminated by `\n`
- `115200` baud (default scaffold value)
- One command per line

## Raspberry Pi <-> GRBL (Arduino Uno)

Pi sends standard G-code lines (examples):

- `G21` (millimeters)
- `G90` (absolute mode)
- `G0 X120 Y80`
- `$H` (home)

GRBL responses:

- `ok`
- `error:<code>`

## Raspberry Pi <-> Claw Controller (Seeeduino)

Pi commands:

- `CLAW:CLOSE`
- `CLAW:OPEN`
- `CLAW:STATUS?`

Claw responses:

- `ACK:CLAW:CLOSED`
- `ACK:CLAW:OPENED`
- `STATUS:CLOSED`
- `STATUS:OPEN`
- `ERR:UNKNOWN_CMD`

## Error Handling (initial)

- Timeout waiting for response -> transition to `ERROR_STATE`.
- Invalid response line -> transition to `ERROR_STATE`.
- Motion/grip failures -> transition to `ERROR_STATE`.

## Versioning

For now, protocol version is managed by repository version and docs.
