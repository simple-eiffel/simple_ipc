# S03: CONTRACTS - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## SIMPLE_IPC Contracts

### Creation Contracts

```eiffel
make_server (a_name: READABLE_STRING_GENERAL)
    require
        name_not_empty: not a_name.is_empty
    ensure
        connection_created: connection /= Void

make_client (a_name: READABLE_STRING_GENERAL)
    require
        name_not_empty: not a_name.is_empty
    ensure
        connection_created: connection /= Void
```

### Read Operation Contracts

```eiffel
read_bytes (a_count: INTEGER): ARRAY [NATURAL_8]
    require
        valid: is_valid
        connected: is_connected
        positive_count: a_count > 0
    ensure
        result_exists: Result /= Void

read_string (a_max_length: INTEGER): STRING_8
    require
        valid: is_valid
        connected: is_connected
        positive_length: a_max_length > 0
    ensure
        result_exists: Result /= Void
```

### Write Operation Contracts

```eiffel
write_bytes (a_bytes: ARRAY [NATURAL_8])
    require
        valid: is_valid
        connected: is_connected
        bytes_not_empty: not a_bytes.is_empty

write_string (a_string: READABLE_STRING_8)
    require
        valid: is_valid
        connected: is_connected
        string_not_empty: not a_string.is_empty
```

### Server Operation Contracts

```eiffel
wait_for_connection (a_timeout_ms: INTEGER)
    require
        valid: is_valid
        server: is_server

disconnect
    require
        valid: is_valid
        server: is_server
```

## Class Invariant

```eiffel
invariant
    connection_exists: connection /= Void
```

## NAMED_PIPE_CONNECTION Invariant

```eiffel
invariant
    handle_default_implies_not_connected:
        handle = default_pointer implies not is_connected
```
