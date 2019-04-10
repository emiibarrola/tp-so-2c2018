/*
 * consola.c
 *
 *  Created on: 20 oct. 2018
 *      Author: utnso
 */


#include "FM9.h"

#include "consola.h"
#include "commons/string.h"

t_tipoComando convert(char* str)
{
	if(str==NULL)
		return -1;
	else if(string_equals_ignore_case(str, "dump"))
		return dump;
	else
		return -2;
}

void *abrirConsola(){
	char *linea;
	while(1){
		linea = readline(">");

		if(linea)
			add_history(linea);

		char **comando = string_split(linea, " ");
		char *directory = comando[1];


		t_tipoComando c = convert(comando[0]);

		switch(c) {

			case dump:
				loggear(logger,LOG_LEVEL_INFO, "Estas haciendo un dump");
				break;

			default:
				loggear(logger,LOG_LEVEL_INFO, "No se reconoce el comando");
				break;

		}

		free(linea);
		free(comando);

	}
	return 0;
}
