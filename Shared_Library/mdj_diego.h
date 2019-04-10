/*
 * msg_cpu.h
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#ifndef MDJ_DIEGO_H_
#define MDJ_DIEGO_H_

#include "shared.h"

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_mdj_sol;

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_mdj_rsp;

typedef struct {
	uint32_t 	dtb;
}__attribute__((packed)) obtener_sol;

typedef struct {
	char 		response;
	uint32_t	dtb;
	uint32_t	largo_data;
	void*		data;
}__attribute__((packed)) obtener_rsp;

typedef struct {
	uint32_t 	dtb;
}__attribute__((packed)) verificar_sol;

typedef struct {
	char 		response;
	uint32_t	dtb;
}__attribute__((packed)) verificar_rsp;

int s_diego_mdj_hadshake_sol(void** buffer);
int s_mdj_diego_hadshake_rsp(void** buffer);
int s_diego_mdj_obtener_sol(void** buffer, uint32_t dtb);
int s_mdj_diego_obtener_rsp(void** buffer, char response, uint32_t dtb, uint32_t largo_data, void* data);
int s_diego_mdj_verificar_sol(void** buffer, uint32_t dtb);
int s_mdj_diego_verificar_rsp(void** buffer, char response, uint32_t dtb);

handshake_mdj_sol d_diego_mdj_hadshake_sol(void* buffer);
handshake_mdj_rsp d_mdj_diego_hadshake_rsp(void* buffer);
obtener_sol d_diego_mdj_obtener_sol(void* buffer);
/**
* @NAME: d_mdj_diego_obtener_rsp
* @DESC: Requiere eliminar buffer
*/
obtener_rsp d_mdj_diego_obtener_rsp(void* buffer);
void destroy_obtener_rsp(obtener_rsp o_rsp);
verificar_sol d_diego_mdj_verificar_sol(void* buffer);
verificar_rsp d_mdj_diego_verificar_rsp(void* buffer);

#endif /* MSG_CPU_H_ */
