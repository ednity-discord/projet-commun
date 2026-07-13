#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void
usage(char *name);
void
die(void);

int
main(int argc, char *argv[])
{
	int i;
	char *hostname = "localhost";
	char *port = "80";
	for (i = 1; i < argc; i++) {
		if (i + 1 == argc) {
			usage(argv[0]);
			die();
		} else if (!strcmp(argv[i], "-hn")) {
			i++;
			hostname = argv[i];
		} else if (!strcmp(argv[i], "-p")) {
			i++;
			port = argv[i];
		} else {
			usage(argv[0]);
			die();
		}
	}
	printf("server must be %s:%s\n", hostname, port);
	ERROR("this is an error\n");
	return 0;
}

void
usage(char *name)
{
	printf("usage: %s [-hn hostname] [-p port]\n", name);
}

void
die(void)
{
	exit(1);
}
