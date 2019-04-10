/*
 ============================================================================
 Name        : MDJ.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <shared.h>
#include "MDJ.h"


int main() {
	logger = configurar_logger("MDJ.log","MDJ");
	get_config();

	int socket = definirSocket(logger);

	pthread_t consola;
	pthread_create(&consola, NULL, *abrirConsola, NULL);

	bindearSocketYEscuchar(socket, MDJ_CONF.IP, MDJ_CONF.PUERTO, logger);

	DAM_handler(socket);

	pthread_join(consola,NULL);

	exit_gracefully(0);
}


void *abrirConsola(){
	char *linea;
	while(1){
		linea = readline(">");

		if(linea)
			add_history(linea);
			char **comando = string_split(linea, " ");
			char *directory = comando[1];



		t_tipoComando c = convert(comando[0]);

		switch(c)
		{

		case cd:
			printf("Estas cambiando al directorio: %s\n",directory);
			chdir(directory);
			char cwd[PATH_MAX];
			if (getcwd(cwd, sizeof(cwd)) != NULL){
				printf("Current working dir: %s\n", cwd);
			} else {
				perror("getcwd() error");
			}
			break;

		case ls:
			system(comando[0]);
			break;

		case cat:
			printf("ingresaste el comando %s\n", comando[0]);
			break;

		case md5:
			printf("ingresaste el comando %s\n", comando[0]);
			break;

		default:
			exit(EXIT_FAILURE);
			break;

		}




		free(linea);
		free(comando);

	}
	return 0;
}


void get_config(){


	t_config *config = cargarConfiguracion("../MDJ.conf", logger);


		if(config_has_property(config,"IP")) {
			MDJ_CONF.IP= config_get_string_value(config, "IP");
			remove_quotes(MDJ_CONF.IP);
		}


		if(config_has_property(config,"PUERTO")) {
			MDJ_CONF.PUERTO= config_get_int_value(config, "PUERTO");
		}

}


t_tipoComando convert(char* str)
{
	if(!strncmp(str,"ls",2)) return ls;
	else if(!strncmp(str,"cd",2)) return cd;
	else if(!strncmp(str,"cat",3))return cat;
	else if(!strncmp(str,"md5",3)) return md5;
	else return -1;
}

void exit_gracefully(int return_nr){
	log_destroy(logger);
	config_destroy(config);
	close(clientSocket);
	loggear(logger, LOG_LEVEL_INFO, "Fin proceso MDJ.");
	exit(return_nr);
}

void DAM_handler(int socket){
	clientSocket = aceptarConexiones(socket, logger);
	t_mensaje* msg = recibirMensaje(clientSocket, logger);

	loggear(logger,LOG_LEVEL_INFO, "Proceso: %d", msg->header.tipoProceso);
	loggear(logger,LOG_LEVEL_INFO,"Procesar mensaje: %d", msg->header.tipoMensaje);


	switch(msg->header.tipoProceso){
		case diego:
			loggear(logger,LOG_LEVEL_INFO, "Proceso DAM Conectado");
			enviarMensaje(mdj, handshake, 0, NULL, clientSocket, logger);
			break;
		default:
			exit_with_error(clientSocket, "El cliente conectado no es DAM", NULL);
			break;
	}

	destruirMensaje(msg);

}

void exit_with_error(int socket, char *error, void *buffer){
	if(buffer!= NULL){
		free(buffer);
	}
	log_error(logger, error);
	close(socket);
	exit_gracefully(1);
}
