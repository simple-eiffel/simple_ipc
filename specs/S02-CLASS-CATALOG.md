# S02: CLASS CATALOG - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Class Hierarchy

```
IPC_CONNECTION (deferred)
    |
    +-- NAMED_PIPE_CONNECTION
    |
    +-- UNIX_SOCKET_CONNECTION

SIMPLE_IPC (facade, uses IPC_CONNECTION)
```

## Class Descriptions

### SIMPLE_IPC

| Attribute | Value |
|-----------|-------|
| Type | Effective class |
| Role | Facade for IPC operations |
| Pattern | Factory + Facade |
| Creates | Platform-appropriate IPC_CONNECTION |

**Purpose**: Main entry point. Detects platform and creates appropriate connection type.

### IPC_CONNECTION

| Attribute | Value |
|-----------|-------|
| Type | Deferred class |
| Role | Abstract interface |
| Pattern | Template Method |

**Purpose**: Defines common interface for all IPC implementations.

### NAMED_PIPE_CONNECTION

| Attribute | Value |
|-----------|-------|
| Type | Effective class |
| Role | Windows implementation |
| Platform | Windows only |

**Purpose**: Windows named pipe implementation using Win32 API.

### UNIX_SOCKET_CONNECTION

| Attribute | Value |
|-----------|-------|
| Type | Effective class |
| Role | Unix implementation |
| Platform | Linux, macOS |

**Purpose**: Unix domain socket implementation using POSIX sockets.

## Class Metrics

| Class | LOC | Features | Contracts |
|-------|-----|----------|-----------|
| SIMPLE_IPC | 236 | 20 | 12 |
| IPC_CONNECTION | 165 | 14 | 8 |
| NAMED_PIPE_CONNECTION | 359 | 24 | 5 |
| UNIX_SOCKET_CONNECTION | 433 | 24 | 4 |
