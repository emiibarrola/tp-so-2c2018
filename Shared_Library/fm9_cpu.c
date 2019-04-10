/*
 * fm9_cpu.c
 *
 *  Created on: 11 oct. 2018
 *      Author: utnso
 */

#include "fm9_cpu.h"

int s_cpu_fm9_hadshake_sol(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_fm9_cpu_hadshake_rsp(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_cpu_fm9_leer_sol(void** buffer, uint32_t dtb) {

	*buffer = malloc(sizeof(dtb));

	memcpy(*buffer,&dtb,sizeof(dtb));

	return sizeof(dtb);
}

int s_cpu_fm9_leer_rsp(void** buffer, uint32_t dtb, uint32_t largo_data, void* data) {

	*buffer = malloc(sizeof(dtb)+sizeof(largo_data)+largo_data);

	memcpy(*buffer,&dtb,sizeof(dtb));
	memcpy(*buffer+sizeof(dtb),&largo_data,sizeof(largo_data));
	memcpy(*buffer+sizeof(dtb)+sizeof(largo_data),data,largo_data);

	return sizeof(dtb)+sizeof(largo_data)+largo_data;
}

handshake_fmcpu_sol d_cpu_fm9_hadshake_sol(void* buffer) {

	handshake_fmcpu_sol hs_sol = { .hs = buffer};

	return hs_sol;
}

handshake_fmcpu_rsp d_dm9_cpu_hadshake_rsp(void* buffer) {

	handshake_fmcpu_rsp hs_rsp = { .hs = buffer};

	return hs_rsp;
}

leer_sol d_cpu_fm9_leer_sol(void* buffer) {

	leer_sol l_sol;

	memset(&l_sol,0x00,sizeof(l_sol));

	memcpy(&l_sol.dtb,buffer,sizeof(l_sol.dtb));

	return l_sol;
}

/*
 * Requier destrui mensaje
 */
leer_rsp d_fm9_cpu_leer_rsp(void* buffer) {

	leer_rsp l_rsp;

	memset(&l_rsp,0x00,sizeof(l_rsp));

	memcpy(&l_rsp.dtb,buffer,sizeof(l_rsp.dtb));
	memcpy(&l_rsp.largo_data,buffer+sizeof(l_rsp.dtb),sizeof(l_rsp.largo_data));
	l_rsp.data = malloc(l_rsp.largo_data);
	memset(l_rsp.data,0x00,l_rsp.largo_data);
	memcpy(l_rsp.data,buffer+sizeof(l_rsp.dtb)+sizeof(l_rsp.largo_data),l_rsp.largo_data);


	return l_rsp;
}

void destroy_leer_rsp(leer_rsp l_rsp) {

	free(l_rsp.data);

	return;
}
