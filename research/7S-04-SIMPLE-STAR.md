# 7S-04: SIMPLE-STAR INTEGRATION - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Ecosystem Position

simple_ipc provides inter-process communication for the simple_* ecosystem.

## Dependencies (Inbound)

| Library | Usage |
|---------|-------|
| EiffelBase | Core types, PLATFORM detection |

## Dependents (Outbound)

| Library | How It Uses simple_ipc |
|---------|----------------------|
| simple_docker | Unix socket communication with Docker daemon |
| simple_oracle | (potential) Multi-process oracle communication |

## Integration Patterns

### Typical Usage Pattern

```eiffel
-- Server side
create ipc.make_server ("my_service")
ipc.wait_for_connection (5000)
if ipc.is_connected then
    message := ipc.read_line
    ipc.write_string ("ACK")
end

-- Client side
create ipc.make_client ("my_service")
if ipc.is_connected then
    ipc.write_string ("HELLO")
    response := ipc.read_line
end
```

### Protocol Integration

- Works naturally with simple_json for structured data
- Byte arrays compatible with simple_crypto for encrypted channels

## Ecosystem Conventions Followed

1. **Naming**: SIMPLE_ prefix on facade class
2. **Contracts**: Full preconditions/postconditions
3. **Error handling**: last_error pattern
4. **Void safety**: Fully void-safe
5. **SCOOP compatibility**: Designed for concurrent use
