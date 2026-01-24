# S04: FEATURE SPECIFICATIONS - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## SIMPLE_IPC Features

### Initialization

| Feature | Signature | Description |
|---------|-----------|-------------|
| make_server | (name: READABLE_STRING_GENERAL) | Create server IPC endpoint |
| make_client | (name: READABLE_STRING_GENERAL) | Connect to IPC server |

### Status Queries

| Feature | Return Type | Description |
|---------|-------------|-------------|
| is_valid | BOOLEAN | Is handle valid? |
| is_connected | BOOLEAN | Is connection established? |
| is_server | BOOLEAN | Is server mode? |
| has_data_available | BOOLEAN | Is data ready to read? |
| last_error | detachable STRING_32 | Last error message |

### Read Operations

| Feature | Signature | Description |
|---------|-----------|-------------|
| read_bytes | (count: INTEGER): ARRAY[NATURAL_8] | Read raw bytes |
| read_string | (max: INTEGER): STRING_8 | Read as string |
| read_line | (): STRING_8 | Read until newline |

### Write Operations

| Feature | Signature | Description |
|---------|-----------|-------------|
| write_bytes | (bytes: ARRAY[NATURAL_8]) | Write raw bytes |
| write_string | (str: READABLE_STRING_8) | Write string |

### Server Operations

| Feature | Signature | Description |
|---------|-----------|-------------|
| wait_for_connection | (timeout_ms: INTEGER) | Wait for client |
| disconnect | () | Disconnect client |

### Lifecycle

| Feature | Signature | Description |
|---------|-----------|-------------|
| close | () | Close and release |

### Status Report

| Feature | Return Type | Description |
|---------|-------------|-------------|
| last_read_count | INTEGER | Bytes read in last op |
| last_write_count | INTEGER | Bytes written in last op |
| last_wait_succeeded | BOOLEAN | Wait result |
| last_disconnect_succeeded | BOOLEAN | Disconnect result |

### Platform Query

| Feature | Return Type | Description |
|---------|-------------|-------------|
| is_using_named_pipes | BOOLEAN | Using Windows pipes? |
| is_using_unix_socket | BOOLEAN | Using Unix sockets? |
