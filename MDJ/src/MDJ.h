/*
 * MDJ.h
 *
 *  Created on: 29 sep. 2018
 *      Author: utnso
 */

#ifndef MDJ_H_
#define MDJ_H_


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <limits.h>

t_log *logger;
int clientSocket;
t_config * config;

typedef struct  {
  char *IP;
  int   PUERTO;
  char *PUNTO_MONTAJE;
  uint32_t RETARDO;
} t_MDJ_CONF;

t_MDJ_CONF MDJ_CONF;

typedef enum t_tipoComando {
	ls, cd, md5, cat
} t_tipoComando;


void *abrirConsola();
void get_config();
void exit_gracefully(int return_nr);
void DAM_handler(int socket);
void exit_with_error(int socket, char *error, void *buffer);

t_tipoComando convert(char* str);

#endif /* MDJ_H_ */
