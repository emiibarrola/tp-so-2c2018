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
  char *IP_SAFA;
  char *PUERTO_SAFA;
  char *IP_DIEGO;
  char *PUERTO_DIEGO;
  char *IP_FM9;
  char *PUERTO_FM9;
  uint32_t RETARDO;
} t_CPU_CONF;

t_CPU_CONF CPU_CONF;

void get_config(char* path);

#endif /* FILE_CONF_H_ */
