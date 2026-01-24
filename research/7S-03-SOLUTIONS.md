# 7S-03: SOLUTIONS - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Existing Solutions Comparison

### EiffelNet (ISE)

| Aspect | EiffelNet | simple_ipc |
|--------|-----------|------------|
| Network sockets | Yes | No |
| Named pipes | No | Yes |
| Unix sockets | Limited | Yes |
| Complexity | High | Low |
| Dependencies | EiffelBase | Minimal |

### Eiffel-Loop IPC

| Aspect | Eiffel-Loop | simple_ipc |
|--------|-------------|------------|
| Void safety | None | Full |
| Named pipes | Yes | Yes |
| Documentation | Extensive | Contracts |
| Learning curve | Steep | Gentle |

### Direct C Calls

| Aspect | Direct C | simple_ipc |
|--------|----------|------------|
| Type safety | None | Full |
| Portability | Manual | Automatic |
| Integration | Complex | Simple |

## Why simple_ipc?

1. **Void-safe**: Full void safety unlike Eiffel-Loop
2. **Platform abstraction**: Single API for Windows/Unix
3. **Simple contracts**: Clear preconditions/postconditions
4. **SCOOP-ready**: Designed for concurrent use
5. **Minimal dependencies**: Only standard Eiffel libraries

## Alternative Approaches Considered

1. **Wrapper over EiffelNet**: Too heavyweight, no named pipe support
2. **Pure Eiffel implementation**: Not possible for OS primitives
3. **External library binding**: Adds deployment complexity
4. **Shared memory**: More complex, less portable
