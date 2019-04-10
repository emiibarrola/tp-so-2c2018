/*
 * DAM.h
 *
 *  Created on: 25 sep. 2018
 *      Author: utnso
 */

#ifndef DAM_H_
#define DAM_H_

#include <shared.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // Para close
#include <stdint.h>
#include <readline/readline.h> // Para usar readline
#include <commons/log.h>
#include <commons/config.h>
#include <commons/collections/list.h>

t_log* logger;

int socket_safa;
int socket_fm9;
int socket_mdj;

pthread_mutex_t lock_socket_safa;
pthread_mutex_t lock_socket_fm9;
pthread_mutex_t lock_socket_mdj;

#endif /* DAM_H_ */
