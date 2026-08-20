# SpacePacketPipeline

## Overview

Ground-system pipeline for ingesting, decoding, validating, and archiving CCSDS Space Packets. Reads packets from a file, socket, or replayed archive, dispatches each to a type-specific validation strategy by APID, enforces a guarded transmission-state lifecycle, and routes each packet to an archive or reject sink. Built to start as a single-threaded modular monolith and grow module-by-module into threaded ingest, live TCP links, TLS transport, and command authentication.

## Domain Background

This project models a simplified ground-segment telemetry/command processing
chain of the kind used by open-source and mission ground systems such as
Yamcs, OpenC3 COSMOS, and NASA JPL's F Prime GDS, and standardized by the
Consultative Committee for Space Data Systems (CCSDS). Packet framing follows
the CCSDS Space Packet Protocol; command verification and event reporting
are loosely modeled on ECSS Packet Utilization Standard (PUS) services.

References:
- CCSDS 133.0-B, Space Packet Protocol — https://public.ccsds.org/Pubs/133x0b2e2.pdf
- CCSDS 355.0-B, Space Data Link Security Protocol — https://public.ccsds.org/Pubs/355x0b2.pdf
- ECSS-E-ST-70-41C, Telemetry and Telecommand Packet Utilization Standard

### Modes

| Mode | Description |
|---|---|
| `run` | Reads packets from a live source (file or socket), processes through the pipeline, archives or rejects each |
| `replay` | Reads previously archived packets back through the same pipeline, at original or accelerated timing |

### Usage

```bash
./SpacePacketPipeline run --source file --in captures/pass01.bin
./SpacePacketPipeline run --source socket --port 5555
./SpacePacketPipeline replay --archive archive/pass01.log --speed 10
```

### Build & Test

```bash
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure -V
```

