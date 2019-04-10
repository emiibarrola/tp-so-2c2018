/*
 * connection.c
 *
 *  Created on: 21 sep. 2018
 *      Author: utnso
 */
#include"FM9.h"

#include "connection.h"
#include "error.h"

void aceptar(int socket_fm9, int* descriptor_mas_alto, fd_set* set_master);
void procesar(int n_descriptor, fd_set* set_master);

int listen_connexions(char* PUERTO)
{
	int socket_fm9 = definirSocket(logger);
	if(bindearSocketYEscuchar(socket_fm9,"127.0.0.1",atoi(PUERTO),logger)<= 0)
		_exit_with_error("BIND",NULL);

	fd_set set_master, set_copia;
	FD_ZERO(&set_master);
	FD_SET(socket_fm9, &set_master);
	int descriptor_mas_alto = socket_fm9;

	while (true) {
		set_copia = set_master;
		int i = select(descriptor_mas_alto + 1, &set_copia, NULL, NULL, NULL);
		if (i == -1)
			_exit_with_error("SELECT",NULL);

		int n_descriptor = 0;
		while (n_descriptor <= descriptor_mas_alto) {
			if (FD_ISSET(n_descriptor,&set_copia)) {
				//ACEPTAR CONXIONES
				if (n_descriptor == socket_fm9) {
					aceptar(socket_fm9, &descriptor_mas_alto, &set_master);
				}
				//PROCESAR MENSAJE
				else {
					procesar(n_descriptor,&set_master);
				}
			}
			n_descriptor++;
		}
	}

	return socket_fm9;
}

void aceptar(int socket_fm9, int* descriptor_mas_alto, fd_set* set_master) {
	int client_socket;
	if ((client_socket = aceptarConexiones(socket_fm9,logger)) == -1) {
		loggear(logger,LOG_LEVEL_ERROR,"Error en el accept");
		return;
	}
	FD_SET(client_socket, set_master);
	if (client_socket > *descriptor_mas_alto) {
		*descriptor_mas_alto = client_socket;
	}
}

void procesar(int n_descriptor, fd_set* set_master) {
	t_mensaje* msg;
	if((msg = recibirMensaje(n_descriptor, logger))== NULL) {
		close(n_descriptor);
		FD_CLR(n_descriptor, set_master);
		return;
	}

	loggear(logger, LOG_LEVEL_INFO, "Proceso: %d", msg->header.tipoProceso);
	loggear(logger, LOG_LEVEL_INFO,"Procesar mensaje: %d", msg->header.tipoMensaje);
	destruirMensaje(msg);

	if (enviarMensaje(diego, handshake, 0,
			NULL, n_descriptor, logger) <= 0) {
		close(n_descriptor);
		FD_CLR(n_descriptor, set_master);
		return;
	}
}

