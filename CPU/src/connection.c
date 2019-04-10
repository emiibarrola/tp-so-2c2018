/*
 * connections.c
 *
 *  Created on: 14 sep. 2018
 *      Author: utnso
 */
#include "CPU.h"

#include "connection.h"
#include "error.h"

int connect_to_server(char* IP, char* PUERTO) {

	int socket;

	if((socket = definirSocket(logger))<= 0)
		_exit_with_error(NULL,NULL);

	if(conectarseAServidor(socket, IP, atoi(PUERTO), logger)<=0)
		_exit_with_error(NULL,NULL);

	loggear(logger, LOG_LEVEL_INFO, "INICIO Handshake(%d)...", cpu);
	enviarMensaje(cpu, handshake, 0, NULL, socket, logger);
	t_mensaje* msg = recibirMensaje(socket, logger);
	destruirMensaje(msg);
	loggear(logger, LOG_LEVEL_INFO, "FIN Handshake(%d)", cpu);
	return socket;
}
