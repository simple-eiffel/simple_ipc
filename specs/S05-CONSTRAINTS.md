# S05: CONSTRAINTS - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Platform Constraints

### Windows

| Constraint | Value | Reason |
|------------|-------|--------|
| Pipe name format | \\.\pipe\NAME | Win32 requirement |
| Max pipe name | 256 chars | Windows limit |
| Min pipe instances | 1 | Default |
| Buffer size | 4096 bytes | Read line buffer |

### Unix

| Constraint | Value | Reason |
|------------|-------|--------|
| Socket path max | 108 chars | sockaddr_un.sun_path |
| File descriptor | > 0 for valid | Unix convention |
| Socket family | AF_UNIX | Domain sockets only |

## Operational Constraints

### Connection States

```
CREATED --> CONNECTED --> CLOSED
    |                       ^
    +--------> (failed) ----+
```

### Valid State Transitions

| From | To | Trigger |
|------|-----|---------|
| Created | Connected | Successful connection |
| Created | Invalid | Connection failure |
| Connected | Disconnected | disconnect() |
| Disconnected | Connected | wait_for_connection() |
| Any | Closed | close() |

## Memory Constraints

| Operation | Memory | Notes |
|-----------|--------|-------|
| read_bytes | O(count) | Managed via MANAGED_POINTER |
| write_bytes | O(count) | Temporary buffer |
| read_line | O(4096) | Fixed buffer |

## Threading Constraints

- Single connection per SIMPLE_IPC instance
- Thread-safe when using SCOOP separate
- C externals are thread-unsafe by default
