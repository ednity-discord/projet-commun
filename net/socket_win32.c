#ifdef _WIN32

#include "net/socket.h"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int
socket_setup(void)
{
	const WORD version = MAKEWORD(2, 2);
	WSADATA wsadata;
	if (WSAStartup(version, &wsadata)) {
		return 1;
	}
	return 0;
}

void
socket_clean(void)
{
	WSACleanup();
}

socket_address_t *
socket_address(char *port)
{
	struct addrinfo *result, hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if (getaddrinfo(NULL, port, &hints, &result) != 0) {
		return NULL;
	}
	return result;
}

void
socket_address_free(socket_address_t *address)
{
	freeaddrinfo(address);
}

int
socket_bind(socket_t s, socket_address_t *address)
{
	return bind(s, address->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR);
}

socket_t
socket_socket(socket_address_t *address)
{
	socket_t s;
	s = socket(address->ai_family, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET) {
		return -1;
	}
	return s;
}

void
socket_close(socket_t s)
{
	closesocket(s);
}

char *
socket_error(void)
{
	wchar_t *s = NULL;
	FormatMessageW(
	    FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
	    NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
	    (LPWSTR)&s, 0, NULL);
	/* TODO: free it somewhere */
	return s;
}

#endif /* _WIN32 */
