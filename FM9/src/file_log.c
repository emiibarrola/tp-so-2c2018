/*
 * log.c
 *
 *  Created on: 14 sep. 2018
 *      Author: utnso
 */

#include "file_log.h"

void get_logger() {
	logger = log_create("FM9.log", "FM9", true, LOG_LEVEL_INFO);
}
