/*
 * error.c
 *
 *  Created on: 14 sep. 2018
 *      Author: utnso
 */
#include "CPU.h"

#include "error.h"
#include "file_conf.h"

void _exit_with_error(char* error_msg, void * buffer) {

  if (buffer != NULL)
    free(buffer);
  if (error_msg != NULL)
	loggear(logger,LOG_LEVEL_ERROR, error_msg);
  exit_gracefully(EXIT_FAILURE);
}


void exit_gracefully(int return_nr) {
  /*
          Siempre llamamos a esta funcion para cerrar el programa.
          Asi solo necesitamos destruir el logger y usar la llamada al
          sistema exit() para terminar la ejecucion
  */
  close(socket_safa);
  close(socket_diego);
  close(socket_fm9);

  loggear(logger, LOG_LEVEL_INFO, "********* FIN DEL PROCESO CPU *********");

  destruir_logger(logger);
  destroy_config(config);

  exit(return_nr);
}
