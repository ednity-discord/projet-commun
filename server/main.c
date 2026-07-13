#include "error.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _WIN32 /* TODO: add support for win32 */
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#else /* _WIN32 */
#error "win32 socket not supported"
#endif /* _WIN32 */

#define DEFAULT_PORT 80

void
setup(uint16_t port);
void
usage(char *name);
void
die(void);
void
clean(void);

int server_fd;
struct sockaddr_in address;
socklen_t addrlen = sizeof(address);

int
main(int argc, char *argv[])
{
	int i;
	uint16_t port;
	port = DEFAULT_PORT;
	for (i = 1; i < argc; i++) {
		if (i + 1 == argc) {
			usage(argv[0]);
		} else if (!strcmp(argv[i], "-p")) {
			i++;
			port = atoi(argv[i]); /* TODO: safe atoi */
		} else {
			usage(argv[0]);
		}
	}
	setup(port);
	printf("server listening on port %d\n", port);
	clean();
	return 0;
}

void
setup(uint16_t port)
{
	int opt;
	opt = 1;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) {
		PERROR("socket");
		die();
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt,
		       sizeof(opt))) {
		PERROR("setsockopt");
		die();
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		PERROR("bind");
		die();
	}
	if (listen(server_fd, 3) < 0) {
		PERROR("listen");
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
	close(server_fd);
}
