/*
 ============================================================================
 Name        : DAM.c
 Author      : Emiliano Ibarrola
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "DAM.h"

#include "connection.h"
#include "file_conf.h"
#include "error.h"

int main(int argc, char *argv[]) {
	logger = configurar_logger("DAM.log", "DAM");

	if(argc<2)
		_exit_with_error("Ingrese el path del archivo de configuracion",NULL);

	get_config(argv[1]);

	//socket_safa = connect_to_server(DAM_CONF.IP_SAFA, DAM_CONF.PUERTO_SAFA, &lock_socket_safa);
	//socket_fm9 = connect_to_server(DAM_CONF.IP_FM9, DAM_CONF.PUERTO_FM9, &lock_socket_fm9);
	socket_mdj = connect_to_server(DAM_CONF.IP_MDJ, DAM_CONF.PUERTO_MDJ, &lock_socket_mdj);

	listen_connexions(DAM_CONF.PUERTO);

	exit_gracefully(EXIT_SUCCESS);
}
