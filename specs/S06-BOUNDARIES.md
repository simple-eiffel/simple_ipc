# S06: BOUNDARIES - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## System Boundaries

### What simple_ipc IS

- Local inter-process communication
- Platform abstraction layer
- Synchronous I/O wrapper
- Named pipe and Unix socket support

### What simple_ipc IS NOT

- Network communication library
- Async I/O framework
- Message queue system
- Shared memory manager

## Interface Boundaries

### Public API (SIMPLE_IPC)

Everything exposed via SIMPLE_IPC facade:
- Connection creation
- Read/write operations
- Status queries
- Connection lifecycle

### Internal API (IPC_CONNECTION descendants)

Accessible via `connection` attribute:
- Platform-specific features
- Low-level operations
- Implementation details

## Platform Boundaries

### Windows Support

| Feature | Supported |
|---------|-----------|
| Named pipes | Yes |
| Server mode | Yes |
| Client mode | Yes |
| Timeout | Yes |

### Unix Support

| Feature | Supported |
|---------|-----------|
| Domain sockets | Yes |
| Server mode | No (stub) |
| Client mode | Yes |
| Timeout | No |

## Data Boundaries

### Input Limits

| Data Type | Limit | Reason |
|-----------|-------|--------|
| Pipe name | 256 chars | Windows |
| Socket path | 108 chars | Unix |
| Read size | INT_MAX | Memory |

### Output Guarantees

| Operation | Guarantee |
|-----------|-----------|
| read_bytes | Returns empty array on error |
| read_string | Returns empty string on error |
| write | Sets last_write_count |

## Integration Boundaries

### Compatible With

- simple_json (data serialization)
- simple_crypto (encryption layer)

### Incompatible With

- EiffelNet sockets (different abstraction)
- Direct Win32 pipe handles
