/*
 * log.h
 *
 *  Created on: 14 sep. 2018
 *      Author: Emiliano Ibarrola
 */

#ifndef FILE_LOG_H_
#define FILE_LOG_H_

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


t_log * logger;

void get_logger();

#endif /* FILE_LOG_H_ */
