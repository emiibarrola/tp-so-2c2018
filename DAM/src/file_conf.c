/*
 * file_conf.c
 *
 *  Created on: 14 sep. 2018
 *      Author: Emiliano Ibarrola
 */

#include "DAM.h"
#include "file_conf.h"
#include "error.h"

void get_config(char* path) {
	config = cargarConfiguracion(path,logger);

	if(config == NULL)
		_exit_with_error("No se encontro el archivo de configuracion", NULL);

	if(config_has_property(config,"PUERTO")) {
		DAM_CONF.PUERTO = config_get_string_value(config, "PUERTO");
		remove_quotes(DAM_CONF.PUERTO);
	}
	if(config_has_property(config,"IP_SAFA")) {
		DAM_CONF.IP_SAFA = config_get_string_value(config, "IP_SAFA");
		remove_quotes(DAM_CONF.IP_SAFA);
	}
	if(config_has_property(config,"PUERTO_SAFA")) {
		DAM_CONF.PUERTO_SAFA = config_get_string_value(config, "PUERTO_SAFA");
		remove_quotes(DAM_CONF.PUERTO_SAFA);
	}
	if(config_has_property(config,"IP_MDJ")) {
		DAM_CONF.IP_MDJ = config_get_string_value(config, "IP_MDJ");
		remove_quotes(DAM_CONF.IP_MDJ);
	}
	if(config_has_property(config,"PUERTO_MDJ")) {
		DAM_CONF.PUERTO_MDJ = config_get_string_value(config, "PUERTO_MDJ");
		remove_quotes(DAM_CONF.PUERTO_MDJ);
	}
	if(config_has_property(config,"IP_FM9")) {
		DAM_CONF.IP_FM9 = config_get_string_value(config, "IP_FM9");
		remove_quotes(DAM_CONF.IP_FM9);
	}
	if(config_has_property(config,"PUERTO_FM9")) {
		DAM_CONF.PUERTO_FM9 = config_get_string_value(config, "PUERTO_FM9");
		remove_quotes(DAM_CONF.PUERTO_FM9);
	}
	if(config_has_property(config,"TRANSFER_SIZE"))
		DAM_CONF.TRANSFER_SIZE = config_get_int_value(config, "TRANSFER_SIZE");
}
