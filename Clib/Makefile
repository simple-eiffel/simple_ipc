# POSIX build of the object simple_ipc.ecf expects on macOS and Linux.
# Usage: make -C Clib
CC ?= cc
CFLAGS ?= -O2 -fPIC

simple_ipc.o: simple_ipc.c simple_ipc.h
	$(CC) $(CFLAGS) -c simple_ipc.c -o simple_ipc.o

clean:
	rm -f simple_ipc.o

.PHONY: clean
