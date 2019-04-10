/*
 * fm9_cpu.h
 *
 *  Created on: 11 oct. 2018
 *      Author: utnso
 */

#ifndef FM9_CPU_H_
#define FM9_CPU_H_

#include "shared.h"

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_fmcpu_sol;

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_fmcpu_rsp;

typedef struct {
	uint32_t	dtb;
}__attribute__((packed)) leer_sol;

typedef struct {
	uint32_t 	dtb;
	uint32_t	largo_data;
	void*		data;
}__attribute__((packed)) leer_rsp;

int s_cpu_fm9_hadshake_sol(void** buffer);
int s_fm9_cpu_hadshake_rsp(void** buffer);
int s_cpu_fm9_leer_sol(void** buffer, uint32_t dtb);
int s_cpu_fm9_leer_rsp(void** buffer, uint32_t dtb, uint32_t largo_data, void* data);

handshake_fmcpu_sol d_cpu_fm9_hadshake_sol(void* buffer);
handshake_fmcpu_rsp d_fm9_cpu_hadshake_rsp(void* buffer);
leer_sol d_cpu_fm9_leer_sol(void* buffer);
leer_rsp d_fm9_cpu_leer_rsp(void* buffer);
/**
* @NAME: destroy_leer_rsp
* @DESC: Requiere eliminar buffer
*/
void destroy_leer_rsp(leer_rsp l_rsp);

#endif /* FM9_CPU_H_ */
