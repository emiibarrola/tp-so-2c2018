/*
 * msg_cpu.c
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#include "safa_diego.h"

int s_diego_safa_hadshake_sol(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_safa_diego_hadshake_rsp(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_diego_safa_listo_sol(void** buffer, char flag_error, uint32_t dtb) {

	*buffer = malloc(sizeof(flag_error)+sizeof(dtb));

	memcpy(*buffer,&flag_error,sizeof(flag_error));
	memcpy(*buffer+sizeof(flag_error),&dtb,sizeof(dtb));

	return sizeof(flag_error)+sizeof(dtb);
}

int s_safa_diego_listo_rsp(void** buffer, char flag_error, uint32_t dtb) {

	*buffer = malloc(sizeof(flag_error)+sizeof(dtb));

	memcpy(*buffer,&flag_error,sizeof(flag_error));
	memcpy(*buffer+sizeof(flag_error),&dtb,sizeof(dtb));

	return sizeof(flag_error)+sizeof(dtb);
}

handshake_sadie_sol d_diego_safa_hadshake_sol(void* buffer) {

	handshake_sadie_sol hs_sol = { .hs = buffer};

	return hs_sol;
}

handshake_sadie_rsp d_safa_diego_hadshake_rsp(void* buffer) {

	handshake_sadie_rsp hs_rsp = { .hs = buffer};

	return hs_rsp;
}

listo_sol d_diego_safa_listo_sol(void* buffer) {

	listo_sol l_sol;

	memset(&l_sol,0x00,sizeof(l_sol));

	memcpy(&l_sol,buffer,sizeof(listo_sol));

	return l_sol;
}

listo_rsp d_safa_diego_listo_rsp(void* buffer) {

	listo_rsp l_rsp;

	memset(&l_rsp,0x00,sizeof(l_rsp));

	memcpy(&l_rsp,buffer,sizeof(listo_rsp));

	return l_rsp;
}
