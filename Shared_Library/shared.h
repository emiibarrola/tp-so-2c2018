/*
 * shared.h
 *
 *  Created on: 22 sep. 2018
 *      Author: utnso
 */

#ifndef SHARED_H_
#define SHARED_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // Para close
#include <stdint.h>
#include <commons/config.h>
#include <commons/log.h>
#include <commons/string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdarg.h>


/* Estructuras de Hackers */
typedef enum tipoMensaje {
	handshake,
	/* A partir de aca vamos agregando lo que necesitemos */
//	ejecutar,
	buscar,
	verificar,
	obtener,
	cargar,
	listo,
	leer
}t_tipoMensaje;

typedef enum tipoProceso {
	safa, cpu, diego, fm9, mdj
} t_tipoProceso;

typedef struct {
	t_tipoProceso 	tipoProceso;
	t_tipoMensaje 	tipoMensaje;
	int32_t 		longitud;
}__attribute__((packed)) t_header;

typedef struct {
	t_header 		header;
	void* 			content;
}__attribute__((packed)) t_mensaje;

/*
typedef struct {
	int tamanio;
	int cantEntradas;
} t_configInstancia;
*/

/* Definición */

/*funciones de log*/
t_log* configurar_logger(char* nombreLog, char* nombreProceso);
void loggear(t_log* logger, t_log_level level, const char* message_format, ...);
void destruir_logger(t_log* logger);

/*funciones de configuracion*/
t_config* cargarConfiguracion(char *nombreArchivo, t_log* logger);
void remove_quotes(char *line);
void destroy_config(t_config* config);

/* funciones de socket */
int definirSocket(t_log* logger);
int bindearSocketYEscuchar(int socket, char *ip, int puerto, t_log* logger);
int aceptarConexiones(int socket, t_log* logger);
int conectarseAServidor(int socket, char* ip, int puerto, t_log* logger);
int enviarMensaje(int tipoProceso, int tipoMensaje, int len, void* content, int socketReceptor, t_log* logger);
t_mensaje* recibirMensaje(int socketEmisor, t_log* logger);
void destruirMensaje(t_mensaje* msg);
void destruirBuffer(void* buffer);

/* AUXiliares */
void* serializar(int tipoProceso, int tipoMensaje, int len, void* content);
t_mensaje* deserializar(void* buffer);

#endif /* SHARED_H_ */
