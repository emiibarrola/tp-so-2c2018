/*
 * msg_cpu.h
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#ifndef FM9_DIEGO_H_
#define FM9_DIEGO_H_

#include "shared.h"

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_fm9_sol;

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_fm9_rsp;

typedef struct {
	char		response;
	uint32_t 	dtb;
}__attribute__((packed)) cargar_sol;

typedef struct {
	uint32_t	dtb;
	uint32_t	largo_data;
	void*		data;
}__attribute__((packed)) cargar_rsp;

int s_diego_fm9_hadshake_sol(void** buffer);
int s_fm9_diego_hadshake_rsp(void** buffer);
int s_diego_fm9_cargar_sol(void** buffer, uint32_t dtb, uint32_t largo_data, void* data);
int s_fm9_diego_cargar_rsp(void** buffer, char response, uint32_t dtb);

handshake_fm9_sol d_diego_fm9_hadshake_sol(void* buffer);
handshake_fm9_rsp d_fm9_diego_hadshake_rsp(void* buffer);
cargar_sol d_diego_fm9_cargar_sol(void* buffer);
cargar_rsp d_fm9_diego_cargar_rsp(void* buffer);

#endif /* MSG_CPU_H_ */
