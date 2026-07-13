#ifndef _WIN32

#include "net/socket.h"
#include <netinet/in.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int
socket_setup(void)
{
	return 0;
}

void
socket_clean(void)
{
	return;
}

socket_address_t *
socket_address(char *port)
{
	struct sockaddr_in *address;
	address = calloc(1, sizeof(struct sockaddr_in));
	if (address == NULL) {
		return NULL;
	}
	address->sin_family = AF_INET;
	address->sin_addr.s_addr = INADDR_ANY;
	address->sin_port = htons(atoi(port));
	return address;
}

void
socket_address_free(socket_address_t *address)
{
	free(address);
}

int
socket_bind(socket_t s, socket_address_t *address)
{
	if (bind(s, (struct sockaddr *)address, sizeof(*address)) < 0) {
		return 1;	
	}
	return 0;
}

socket_t
socket_socket(socket_address_t *address)
{
	int fd;
	int opt;

	((void)address);
	opt = 1;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		return -1;
	}

	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
		return -1;
	}

	return fd;
}

void
socket_close(socket_t s)
{
	close(s);
}

char *
socket_error(void)
{
	return strerror(errno);
}

#endif /* _WIN32 */
