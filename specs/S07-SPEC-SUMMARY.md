# S07: SPECIFICATION SUMMARY - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Executive Summary

simple_ipc provides cross-platform inter-process communication with a simple, contract-driven API. It abstracts Windows named pipes and Unix domain sockets behind a unified interface.

## Key Specifications

### Architecture

- **Pattern**: Factory + Facade
- **Classes**: 4 (1 facade, 1 deferred, 2 platform)
- **LOC**: ~1,200

### API Surface

- **Creation**: 2 constructors (server, client)
- **Operations**: 8 main operations
- **Queries**: 10 status queries

### Contract Coverage

| Area | Preconditions | Postconditions |
|------|---------------|----------------|
| Creation | 2 | 2 |
| Read | 6 | 4 |
| Write | 4 | 0 |
| Status | 2 | 0 |

### Platform Support

| Platform | Client | Server |
|----------|--------|--------|
| Windows | Full | Full |
| Linux | Full | Stub |
| macOS | Full | Stub |

## Design Decisions

1. **Factory creation**: Platform detection in make_*
2. **Delegation pattern**: Facade delegates to connection
3. **Error model**: last_error pattern (no exceptions)
4. **Buffer management**: MANAGED_POINTER for C interop

## Quality Attributes

| Attribute | Rating | Notes |
|-----------|--------|-------|
| Reliability | High | Contracts + error handling |
| Usability | High | Simple API |
| Portability | Medium | Unix server incomplete |
| Performance | Medium | Synchronous only |
| Testability | High | Clear contracts |
