/*
 * file_conf.c
 *
 *  Created on: 14 sep. 2018
 *      Author: Emiliano Ibarrola
 */
#include "CPU.h"

#include "file_conf.h"
#include "error.h"

void get_config(char* path) {
	config = cargarConfiguracion(path,logger);

	if(config == NULL)
		_exit_with_error("No se encontro el archivo de configuracion", NULL);

	if(config_has_property(config,"IP_SAFA")) {
		CPU_CONF.IP_SAFA = config_get_string_value(config, "IP_SAFA");
		remove_quotes(CPU_CONF.IP_SAFA);
	}
	if(config_has_property(config,"PUERTO_SAFA")) {
		CPU_CONF.PUERTO_SAFA = config_get_string_value(config, "PUERTO_SAFA");
		remove_quotes(CPU_CONF.PUERTO_SAFA);
	}
	if(config_has_property(config,"IP_DIEGO")) {
		CPU_CONF.IP_DIEGO = config_get_string_value(config, "IP_DIEGO");
		remove_quotes(CPU_CONF.IP_DIEGO);
	}
	if(config_has_property(config,"PUERTO_DIEGO")) {
		CPU_CONF.PUERTO_DIEGO = config_get_string_value(config, "PUERTO_DIEGO");
		remove_quotes(CPU_CONF.PUERTO_DIEGO);
	}
	if(config_has_property(config,"IP_FM9")) {
		CPU_CONF.IP_FM9 = config_get_string_value(config, "IP_FM9");
		remove_quotes(CPU_CONF.IP_FM9);
	}
	if(config_has_property(config,"PUERTO_FM9")) {
		CPU_CONF.PUERTO_FM9 = config_get_string_value(config, "PUERTO_FM9");
		remove_quotes(CPU_CONF.PUERTO_FM9);
	}
	if(config_has_property(config,"RETARDO"))
		CPU_CONF.RETARDO = config_get_int_value(config, "RETARDO");
}
