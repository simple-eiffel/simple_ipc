/*
 * unix_socket.h - Platform-aware Unix socket headers
 *
 * On Windows: provides stub types so code compiles (but returns -1)
 * On Unix: includes actual socket headers
 */

#ifndef UNIX_SOCKET_H
#define UNIX_SOCKET_H

#if defined(EIF_WINDOWS) || defined(_WIN32)
    /* Windows stubs - Unix sockets not supported */
    #define AF_UNIX 1
    struct sockaddr_un { int sun_family; char sun_path[108]; };
    struct sockaddr { int dummy; };
#else
    /* Unix - include actual headers */
    #include <sys/socket.h>
    #include <sys/un.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <poll.h>
    #include <unistd.h>
#endif

#include <string.h>

#if !defined(EIF_WINDOWS) && !defined(_WIN32)

/* A write to a gone peer must not raise SIGPIPE, which would reach the Eiffel
   runtime. macOS turns it off per socket, Linux per send (see sus_send). */
static void sus_no_sigpipe(int a_fd)
{
#ifdef SO_NOSIGPIPE
    int l_on = 1;
    setsockopt(a_fd, SOL_SOCKET, SO_NOSIGPIPE, &l_on, sizeof(l_on));
#else
    (void) a_fd;
#endif
}

static int sus_send(int a_fd, const void* a_data, int a_size)
{
#ifdef MSG_NOSIGNAL
    return (int) send(a_fd, a_data, (size_t) a_size, MSG_NOSIGNAL);
#else
    return (int) send(a_fd, a_data, (size_t) a_size, 0);
#endif
}

static void sus_address(struct sockaddr_un* a_address, const char* a_path)
{
    memset(a_address, 0, sizeof(*a_address));
    a_address->sun_family = AF_UNIX;
    strncpy(a_address->sun_path, a_path, sizeof(a_address->sun_path) - 1);
}

/* Bind `a_fd' to `a_path' and listen. 0 on success, -1 on error. A live server
   on the path keeps it; a socket file left by a dead one is replaced. Only
   this user may connect, as with a default Windows pipe ACL. */
static int sus_listen(int a_fd, const char* a_path)
{
    struct sockaddr_un l_address;
    int l_probe;

    sus_address(&l_address, a_path);
    if (bind(a_fd, (struct sockaddr*) &l_address, sizeof(l_address)) != 0) {
        if (errno != EADDRINUSE) return -1;
        l_probe = socket(AF_UNIX, SOCK_STREAM, 0);
        if (l_probe < 0) return -1;
        if (connect(l_probe, (struct sockaddr*) &l_address, sizeof(l_address)) == 0) {
            close(l_probe);
            errno = EADDRINUSE;
            return -1;
        }
        close(l_probe);
        unlink(a_path);
        if (bind(a_fd, (struct sockaddr*) &l_address, sizeof(l_address)) != 0) return -1;
    }
    chmod(a_path, 0600);
    return listen(a_fd, 16);
}

/* Wait up to `a_timeout_ms' (negative: forever) for a client. Its descriptor,
   or -1. */
static int sus_accept(int a_fd, int a_timeout_ms)
{
    struct pollfd l_wait;
    int l_result;

    l_wait.fd = a_fd;
    l_wait.events = POLLIN;
    l_wait.revents = 0;
    do {
        l_result = poll(&l_wait, 1, a_timeout_ms);
    } while (l_result < 0 && errno == EINTR);
    if (l_result <= 0) return -1;
    do {
        l_result = accept(a_fd, NULL, NULL);
    } while (l_result < 0 && errno == EINTR);
    if (l_result >= 0) sus_no_sigpipe(l_result);
    return l_result;
}

#endif

#endif /* UNIX_SOCKET_H */
