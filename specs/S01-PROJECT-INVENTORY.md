# S01: PROJECT INVENTORY - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Project Overview

| Attribute | Value |
|-----------|-------|
| Library Name | simple_ipc |
| Purpose | Inter-process communication |
| Phase | Production |
| Void Safety | Full |
| SCOOP Ready | Yes |

## File Inventory

### Source Files

| File | Path | Purpose |
|------|------|---------|
| simple_ipc.e | src/ | Main facade class |
| ipc_connection.e | src/ | Deferred base class |
| named_pipe_connection.e | src/ | Windows implementation |
| unix_socket_connection.e | src/ | Unix implementation |

### Test Files

| File | Path | Purpose |
|------|------|---------|
| test_app.e | testing/ | Test application root |
| lib_tests.e | testing/ | Test cases |

### Configuration

| File | Purpose |
|------|---------|
| simple_ipc.ecf | Library ECF |
| simple_ipc_tests.ecf | Test target ECF |

## External Dependencies

### C Header Files

| Header | Platform | Purpose |
|--------|----------|---------|
| simple_ipc.h | Windows | Named pipe functions |
| unix_socket.h | Unix | Socket functions |

### Eiffel Libraries

| Library | Purpose |
|---------|---------|
| base | Core Eiffel types |

## Build Artifacts

| Target | Output |
|--------|--------|
| simple_ipc | Library (linkable) |
| simple_ipc_tests | Test executable |
