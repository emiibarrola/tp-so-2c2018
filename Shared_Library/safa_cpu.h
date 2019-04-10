/*
 * msg_safa_cpu.h
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#ifndef SAFA_CPU_H_
#define SAFA_CPU_H_

#include "shared.h"

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_safa_sol;

typedef struct {
	char		quantum;
	uint32_t 	largo_algoritmo;
	char*		algritmo;
}__attribute__((packed)) handshake_safa_rsp;

typedef struct {
	uint32_t 	dtb;
	uint32_t	largo_data;
	void*		data;
}__attribute__((packed)) ejecutar_sol;

typedef struct {
	char		response;
	uint32_t	dtb;
}__attribute__((packed)) ejecutar_rsp;

int s_cpu_safa_hadshake_sol(void** buffer);
int s_safa_cpu_hadshake_rsp(void** buffer,char quantum ,uint32_t largo_algoritmo, char* algoritmo);
int s_safa_cpu_cargar_sol(void** buffer, uint32_t dtb, uint32_t largo_data, void* data);
int s_cpu_safa_cargar_rsp(void** buffer, char response, uint32_t dtb);

handshake_safa_sol d_cpu_safa_hadshake_sol(void* buffer);
handshake_safa_rsp d_safa_cpu_hadshake_rsp(void* buffer);
/**
* @NAME: destroy_handshake_safa_rsp
* @DESC: Requiere eliminar buffer
*/
void destroy_handshake_safa_rsp(handshake_safa_rsp hs_rsp);
ejecutar_sol d_safa_cpu_cargar_sol(void* buffer);
/**
* @NAME: destroy_ejecutar_sol
* @DESC: Requiere eliminar buffer
*/
void destroy_ejecutar_sol(ejecutar_sol e_sol);
ejecutar_rsp d_cpu_safa_cargar_rsp(void* buffer);

#endif /* SAFA_CPU_H_ */
