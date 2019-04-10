/*
 * msg_cpu.h
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#ifndef DIEGO_CPU_H_
#define DIEGO_CPU_H_

#include "shared.h"

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_diego_sol;

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_diego_rsp;

typedef struct {
	uint32_t 	dtb;
	uint32_t	largo_path;
	char* 		path;
}__attribute__((packed)) buscar_sol;

typedef struct {
	char		response;
	uint32_t	dtb;
}__attribute__((packed)) buscar_rsp;

int s_cpu_diego_hadshake_sol(void** buffer);
int s_diego_cpu_hadshake_rsp(void** buffer);
int s_cpu_diego_buscar_sol(void** buffer, uint32_t dtb, uint32_t largo_path, char* path);
int s_diego_cpu_buscar_rsp(void** buffer, char response, uint32_t dtb);

handshake_diego_sol d_cpu_diego_hadshake_sol(void* buffer);
handshake_diego_rsp d_diego_cpu_hadshake_rsp(void* buffer);
/**
* @NAME: d_cpu_diego_buscar_sol
* @DESC: Requiere eliminar buffer
*/
buscar_sol d_cpu_diego_buscar_sol(void* buffer);
void destroy_buscar_sol(buscar_sol b_sol);
buscar_rsp d_diego_cpu_buscar_rsp(void* buffer);

#endif /* DIEGO_CPU_H_ */
