#include "error.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "net/socket.h"

#define DEFAULT_PORT "80"

void
setup(char *port);
void
usage(char *name);
void
die(void);
void
clean(void);

socket_t server_socket;
socket_address_t *address;

int
main(int argc, char *argv[])
{
	int i;
	char *port;
	port = DEFAULT_PORT;
	for (i = 1; i < argc; i++) {
		if (i + 1 == argc) {
			usage(argv[0]);
		} else if (!strcmp(argv[i], "-p")) {
			i++;
			port = argv[i];
		} else {
			usage(argv[0]);
		}
	}
	setup(port);
	printf("server listening on port %s\n", port);
	clean();
	return 0;
}

void
setup(char *port)
{
	if (socket_setup()) {
		ERRORF("socket_setup: %s\n", socket_error());
		die();
	}

	address = socket_address(port);
	if (address == NULL) {
		ERRORF("socket_address: %s\n", socket_error());
		die();
	}

	server_socket = socket_socket(address);
	if (server_socket < 0) {
		ERRORF("socket_socket: %s\n", socket_error());
		die();
	}

	if (socket_bind(server_socket, address)) {
		ERRORF("socket_bind: %s\n", socket_error());
		die();
	}
}

void
usage(char *name)
{
	printf("usage: %s [-p port]\n", name);
	die();
}

void
die(void)
{
	clean();
	exit(1);
}

void
clean(void)
{
	socket_close(server_socket);
	socket_address_free(address);
	socket_clean();
}
