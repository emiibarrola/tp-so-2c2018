/*
 * connections.c
 *
 *  Created on: 14 sep. 2018
 *      Author: utnso
 */

#include "DAM.h"
#include "connection.h"
#include "error.h"
#include "proceso.h"

void aceptar(int socket_fm9, int* descriptor_mas_alto, fd_set* set_master);
void procesar(int n_descriptor, fd_set* set_master);

int connect_to_server(char* IP, char* PUERTO, pthread_mutex_t* lock) {

	int socket;

	if (pthread_mutex_init(lock, NULL) != 0)
		_exit_with_error("No se pudo incializar mutex",NULL);

	if((socket = definirSocket(logger))<= 0)
		_exit_with_error(NULL,NULL);

	if(conectarseAServidor(socket, IP, atoi(PUERTO), logger)<=0)
		_exit_with_error(NULL,NULL);

	loggear(logger,LOG_LEVEL_INFO, "INICIO Handshake(%d)...", diego);
	enviarMensaje(diego, handshake, 0, NULL, socket, logger);
	t_mensaje* msg = recibirMensaje(socket, logger);
	destruirMensaje(msg);
	loggear(logger,LOG_LEVEL_INFO, "FIN Handshake(%d)", diego);
	return socket;
}

int listen_connexions(char* PUERTO)
{
	int socket_diego = definirSocket(logger);
	if(bindearSocketYEscuchar(socket_diego,"127.0.0.1",atoi(PUERTO),logger)<= 0)
		_exit_with_error("BIND",NULL);

	fd_set set_master, set_copia;
	FD_ZERO(&set_master);
	FD_SET(socket_diego, &set_master);
	int descriptor_mas_alto = socket_diego;

	while (true) {
		set_copia = set_master;
		int i = select(descriptor_mas_alto + 1, &set_copia, NULL, NULL, NULL);
		if (i == -1)
			_exit_with_error("SELECT",NULL);

		int n_descriptor = 0;
		while (n_descriptor <= descriptor_mas_alto) {
			if (FD_ISSET(n_descriptor,&set_copia)) {
				//ACEPTAR CONXIONES
				if (n_descriptor == socket_diego) {
					aceptar(socket_diego, &descriptor_mas_alto, &set_master);
				}
				//PROCESAR MENSAJE
				else {
					procesar(n_descriptor,&set_master);
				}
			}
			n_descriptor++;
		}
	}

	return socket_diego;
}

void aceptar(int socket_diego, int* descriptor_mas_alto, fd_set* set_master) {
	int client_socket;
	if ((client_socket = aceptarConexiones(socket_diego,logger)) == -1) {
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
		destruirMensaje(msg);
		return;
	}

	loggear(logger,LOG_LEVEL_INFO, "Proceso: %d", msg->header.tipoProceso);
	loggear(logger,LOG_LEVEL_INFO,"Procesar mensaje: %d", msg->header.tipoMensaje);

	switch(msg->header.tipoProceso) {
		case cpu:;
			procesar_CPU(msg, n_descriptor, set_master);
			break;
		default:
			loggear(logger,LOG_LEVEL_INFO,"No se reconoce el proceso");
			close(n_descriptor);
			FD_CLR(n_descriptor, set_master);
			break;
	}
	destruirMensaje(msg);
}
