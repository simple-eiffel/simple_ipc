# 7S-01: SCOPE - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Problem Domain

Inter-process communication (IPC) for Eiffel applications on Windows and Unix platforms.

### What Problem Does This Solve?

1. **Process Isolation Communication**: Allows separate Eiffel processes to communicate
2. **Platform Abstraction**: Hides platform-specific IPC mechanisms (named pipes vs Unix sockets)
3. **Simple API**: Provides straightforward read/write operations for IPC

### Target Users

- Eiffel developers building multi-process applications
- Systems requiring daemon/service communication
- Applications needing to communicate with external processes (e.g., Docker daemon)

### Use Cases

1. Client-server applications where server runs as daemon
2. Inter-tool communication in development environments
3. Communication with system services via Unix sockets

## Boundaries

### In Scope

- Windows named pipes (\\.\pipe\name format)
- Unix domain sockets (/var/run/name.sock format)
- Synchronous read/write operations
- Client and server connection modes
- String and byte array transfer

### Out of Scope

- Network sockets (TCP/UDP) - see simple_http
- Shared memory IPC
- Message queues
- Asynchronous I/O
- Advanced pipe security (Windows ACLs)

## Domain Vocabulary

| Term | Definition |
|------|------------|
| Named Pipe | Windows IPC mechanism using \\.\pipe\name namespace |
| Unix Socket | Unix domain socket for local IPC (AF_UNIX) |
| Connection | Established IPC channel between processes |
| Server | Process creating and listening on IPC endpoint |
| Client | Process connecting to existing IPC endpoint |

## Success Criteria

1. Transparent platform abstraction - code works on Windows and Unix
2. Simple API - create, read, write, close
3. Reliable byte-level communication
4. Clear error reporting
