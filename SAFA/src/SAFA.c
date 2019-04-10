/*
 ============================================================================
 Name        : SAFA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <shared.h>

/* Variables globales */
t_log logger;
t_config *config;
int socket_safa, socket_diego;

int main(void) {

	/* 1. Creación de logger */
	logger = configurar_logger("SAFA.log", "SAFA");

	/* 2. Cargar configuración desde archivo */
	config = cargarConfiguracion("SAFA.cfg", logger);

	/* 3. Creación de hilo para la consola */


	return EXIT_SUCCESS;
}
