#ifndef FILE_CONF_H_
#define FILE_CONF_H_

#include <shared.h>

#include <stdio.h>
#include <readline/readline.h>
#include <commons/log.h>
#include <commons/config.h>
#include <stdint.h>

t_config * config;

typedef struct  {
  char *PUERTO;
  char *MODO;
  uint32_t TAMANIO;
  uint32_t MAX_LINEA;
  uint32_t TAM_PAGINA;
} t_FM9_CONF;

t_FM9_CONF FM9_CONF;

void get_config(char* path);

#endif /* FILE_CONF_H_ */
