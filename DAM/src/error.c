/*
 * error.c
 *
 *  Created on: 14 sep. 2018
 *      Author: utnso
 */

#include "DAM.h"

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
  close(socket_mdj);
  close(socket_fm9);

  pthread_mutex_destroy(&lock_socket_safa);
  pthread_mutex_destroy(&lock_socket_fm9);
  pthread_mutex_destroy(&lock_socket_mdj);

  loggear(logger, LOG_LEVEL_INFO, "********* FIN DEL PROCESO DIEGO *********");

  destruir_logger(logger);
  destroy_config(config);

  exit(return_nr);
}
