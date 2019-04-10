/*
 * connections.h
 *
 *  Created on: 14 sep. 2018
 *      Author: utnso
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <stdio.h>
#include <openssl/md5.h>
#include <sys/socket.h>
#include <netdb.h> // Para getaddrinfo
#include <commons/log.h>
#include <commons/config.h>
#include <commons/collections/list.h>

int connect_to_server(char* IP, char* PUERTO);

#endif /* CONNECTION_H_ */
