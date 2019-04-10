/*
 ============================================================================
 Name        : FM9.c
 Author      : Emiliano Ibarrola
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <shared.h>

#include "FM9.h"

#include "connection.h"
#include "file_conf.h"
#include "consola.h"
#include "error.h"

int main(int argc, char *argv[]) {
	logger = configurar_logger("FM9.log", "FM9");

	if(argc<2)
		_exit_with_error("Ingrese el path del archivo de configuracion",NULL);

	get_config(argv[1]);

	consola = pthread_create(&consola, NULL, *abrirConsola, NULL);

	listen_connexions(FM9_CONF.PUERTO);

	exit_gracefully(EXIT_SUCCESS);
}
