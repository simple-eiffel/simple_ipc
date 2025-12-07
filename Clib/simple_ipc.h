/*
 * simple_ipc.h - Inter-process communication for Eiffel (Named Pipes)
 * Copyright (c) 2025 Larry Rix - MIT License
 */

#ifndef SIMPLE_IPC_H
#define SIMPLE_IPC_H

#include <windows.h>

/* Pipe handle wrapper */
typedef struct {
    HANDLE pipe_handle;
    int is_server;
    int is_connected;
    char* error_message;
} sipc_pipe;

/* Create a named pipe server.
 * name should be in format "\\.\pipe\PipeName"
 * Returns NULL on failure.
 */
sipc_pipe* sipc_create_server(const char* name);

/* Connect client to a named pipe.
 * Returns NULL on failure.
 */
sipc_pipe* sipc_connect_client(const char* name);

/* Wait for a client to connect (server only).
 * Returns 1 on success, 0 on failure.
 */
int sipc_wait_for_connection(sipc_pipe* pipe, int timeout_ms);

/* Disconnect and prepare for new client (server only).
 * Returns 1 on success.
 */
int sipc_disconnect(sipc_pipe* pipe);

/* Read data from pipe.
 * Returns number of bytes read, or -1 on error.
 */
int sipc_read(sipc_pipe* pipe, void* buffer, int buffer_size);

/* Write data to pipe.
 * Returns number of bytes written, or -1 on error.
 */
int sipc_write(sipc_pipe* pipe, const void* data, int data_size);

/* Read a line from pipe (up to newline or buffer_size-1).
 * Returns number of bytes read, or -1 on error.
 */
int sipc_read_line(sipc_pipe* pipe, char* buffer, int buffer_size);

/* Write a string to pipe.
 * Returns number of bytes written, or -1 on error.
 */
int sipc_write_string(sipc_pipe* pipe, const char* str);

/* Check if data is available to read.
 * Returns 1 if data available, 0 if not, -1 on error.
 */
int sipc_data_available(sipc_pipe* pipe);

/* Check if pipe is connected.
 * Returns 1 if connected, 0 if not.
 */
int sipc_is_connected(sipc_pipe* pipe);

/* Check if pipe is server.
 * Returns 1 if server, 0 if client.
 */
int sipc_is_server(sipc_pipe* pipe);

/* Get last error message.
 * Returns NULL if no error.
 */
const char* sipc_get_error(sipc_pipe* pipe);

/* Close and free the pipe.
 */
void sipc_close(sipc_pipe* pipe);

/* Helper: Build full pipe name from simple name.
 * Caller must free the returned string.
 */
char* sipc_make_pipe_name(const char* simple_name);

#endif /* SIMPLE_IPC_H */
