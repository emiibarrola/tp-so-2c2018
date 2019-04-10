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
  char *IP_SAFA;
  char *PUERTO_SAFA;
  char *IP_MDJ;
  char *PUERTO_MDJ;
  char *IP_FM9;
  char *PUERTO_FM9;
  uint32_t TRANSFER_SIZE;
} t_DAM_CONF;

t_DAM_CONF DAM_CONF;

void get_config();

#endif /* FILE_CONF_H_ */
