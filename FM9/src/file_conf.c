/*
 * file_conf.c
 *
 *  Created on: 14 sep. 2018
 *      Author: Emiliano Ibarrola
 */
#include "FM9.h"

#include "file_conf.h"
#include "error.h"

void get_config(char* path) {
	config = cargarConfiguracion(path,logger);

	if(config == NULL)
		_exit_with_error("No se encontro el archivo de configuracion", config);

	if(config_has_property(config,"PUERTO")) {
		FM9_CONF.PUERTO = config_get_string_value(config, "PUERTO");
		remove_quotes(FM9_CONF.PUERTO);
	}
	if(config_has_property(config,"MODO")) {
		FM9_CONF.MODO = config_get_string_value(config, "MODO");
		remove_quotes(FM9_CONF.MODO);
	}
	if(config_has_property(config,"TAMANIO")) {
		FM9_CONF.TAMANIO = config_get_int_value(config, "TAMANIO");
	}
	if(config_has_property(config,"MAX_LINEA")) {
		FM9_CONF.MAX_LINEA = config_get_int_value(config, "MAX_LINEA");
	}
	if(config_has_property(config,"TAM_PAGINA")) {
		FM9_CONF.TAM_PAGINA = config_get_int_value(config, "TAM_PAGINA");
	}
}
