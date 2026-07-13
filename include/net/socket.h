#ifndef SOCKET_H
#define SOCKET_H

#ifndef _WIN32
typedef int socket_t;
typedef struct sockaddr_in socket_address_t;
#else /* _WIN32 */
typedef SOCKET socket_t;
typedef struct addrinfo socket_address_t;
#endif /* _WIN32 */

int
socket_setup(void);
void
socket_clean(void);
socket_address_t *
socket_address(char *port);
void
socket_address_free(socket_address_t *address);
int
socket_bind(socket_t s, socket_address_t *address);
socket_t
socket_socket(socket_address_t *address);
void
socket_close(socket_t s);
char *
socket_error(void);

#endif /* SOCKET_H */
