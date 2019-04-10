/*
 * msg_cpu.h
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#ifndef SAFA_DIEGO_H_
#define SAFA_DIEGO_H_

#include "shared.h"

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_sadie_sol;

typedef struct {
	void* hs;
}__attribute__((packed)) handshake_sadie_rsp;

typedef struct {
	char		flag_error;
	uint32_t 	dtb;
}__attribute__((packed)) listo_sol;

typedef struct {
	char		respose;
	uint32_t	dtb;
}__attribute__((packed)) listo_rsp;

int s_diego_safa_hadshake_sol(void** buffer);
int s_safa_diego_hadshake_rsp(void** buffer);
int s_diego_safa_listo_sol(void** buffer, char flag_error, uint32_t dtb);
int s_safa_diego_listo_rsp(void** buffer, char flag_error, uint32_t dtb);

handshake_sadie_sol d_diego_safa_hadshake_sol(void* buffer);
handshake_sadie_rsp d_safa_diego_hadshake_rsp(void* buffer);
listo_sol d_diego_safa_listo_sol(void* buffer);
listo_rsp d_safa_diego_listo_rsp(void* buffer);

#endif /* MSG_CPU_H_ */
