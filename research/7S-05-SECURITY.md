# 7S-05: SECURITY - simple_ipc

**Library**: simple_ipc
**Date**: 2026-01-23
**Status**: BACKWASH (reverse-engineered from implementation)

## Security Considerations

### Threat Model

| Threat | Risk | Mitigation |
|--------|------|------------|
| Unauthorized connection | Medium | OS-level permissions |
| Data interception | Low | Local-only communication |
| Denial of service | Medium | Timeout handling |
| Buffer overflow | Low | Managed memory via Eiffel |

### Windows Named Pipes Security

- Uses default security descriptor
- Pipe accessible to same user by default
- No custom DACL support currently

### Unix Socket Security

- File system permissions control access
- Socket file typically in /var/run with appropriate permissions
- No credential passing implemented

## Security Best Practices

1. **Use unique pipe names**: Avoid predictable names
2. **Validate input**: Check data before processing
3. **Handle timeouts**: Prevent blocking forever
4. **Clean up sockets**: Remove Unix socket files on exit

## Security Limitations

- No built-in encryption (use simple_crypto on top)
- No authentication mechanism
- No access control beyond OS defaults
- Server trusts any connected client

## Recommendations

For sensitive data:
1. Add application-level authentication
2. Encrypt payload with simple_crypto
3. Validate message format before processing
