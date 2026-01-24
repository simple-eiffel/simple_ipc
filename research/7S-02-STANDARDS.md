# 7S-02: STANDARDS - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Applicable Standards

### Windows Named Pipes

- **Win32 API**: CreateNamedPipe, ConnectNamedPipe, ReadFile, WriteFile
- **Naming Convention**: \\.\pipe\pipename
- **Documentation**: MSDN Named Pipes documentation

### Unix Domain Sockets

- **POSIX Standard**: AF_UNIX socket family
- **IEEE Std 1003.1**: POSIX.1 socket interface
- **System Calls**: socket(), connect(), bind(), listen(), accept(), read(), write()

## Standards Compliance

### Windows Implementation

| Standard | Compliance |
|----------|------------|
| Named Pipe API | Full (via inline C) |
| Overlapped I/O | Not implemented |
| Security descriptors | Default only |

### Unix Implementation

| Standard | Compliance |
|----------|------------|
| POSIX sockets | Partial (client only) |
| AF_UNIX addressing | Full |
| Non-blocking I/O | Not implemented |

## Design Patterns Applied

1. **Factory Pattern**: SIMPLE_IPC creates platform-appropriate connection
2. **Template Method**: IPC_CONNECTION defines interface, descendants implement
3. **Facade Pattern**: SIMPLE_IPC presents unified interface

## Deviation from Standards

- Server-side Unix socket not yet implemented
- No support for abstract namespace sockets (Linux-specific)
- No credential passing (SO_PASSCRED)
