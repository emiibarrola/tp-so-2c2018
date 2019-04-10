/*
 ============================================================================
 Name        : CPU.c
 Author      : Emiliano Ibarrola
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <shared.h>

#include "CPU.h"

#include "connection.h"
#include "file_conf.h"
#include "error.h"
#include "commons/string.h"
#include "diego_cpu.h"

int main(int argc, char *argv[]) {
	logger = configurar_logger("CPU.log", "CPU");

	if(argc<2)
		_exit_with_error("Ingrese el path del archivo de configuracion",NULL);

	get_config(argv[1]);

	//socket_fm9 = connect_to_server(CPU_CONF.IP_FM9,CPU_CONF.PUERTO_FM9);
	socket_diego = connect_to_server(CPU_CONF.IP_DIEGO,CPU_CONF.PUERTO_DIEGO);
	//socket_safa = connect_to_server(CPU_CONF.IP_SAFA,CPU_CONF.PUERTO_SAFA);

	//send_content(socket_dma, &cpu);
	CPU.iOperacion= buscar;
	execute();
	exit_gracefully(EXIT_SUCCESS);
}

void retardo(int iRetardo) {
	sleep(iRetardo/1000);
}

void execute() {
	void* buffer_msg = NULL;
	int largo = 0;

	retardo(CPU_CONF.RETARDO);

	switch(CPU.iOperacion)
	{
		case buscar:
			loggear(logger, LOG_LEVEL_INFO, "Incio de Operacion: '%d'", CPU.iOperacion);
			largo = s_cpu_diego_buscar_sol(&buffer_msg,1,strlen("Test.txt"),"Test.txt");
			if (enviarMensaje(cpu,buscar,largo,buffer_msg,socket_diego,logger) <= 0) {
				_exit_with_error("Ocurrio un error con DIEGO",buffer_msg);
			}
			destruirBuffer(buffer_msg);
			break;
		default:
			loggear(logger, LOG_LEVEL_INFO, "Return Operacion");
			return;
	}
}
