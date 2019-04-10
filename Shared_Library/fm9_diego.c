/*
 * msg_cpu.c
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#include "fm9_diego.h"

int s_diego_fm9_hadshake_sol(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_fm9_diego_hadshake_rsp(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_diego_fm9_cargar_sol(void** buffer, uint32_t dtb, uint32_t largo_data, void* data) {

	*buffer = malloc(sizeof(dtb)+sizeof(largo_data)+largo_data);

	memcpy(*buffer,&dtb,sizeof(dtb));
	memcpy(*buffer+sizeof(dtb),&largo_data,sizeof(largo_data));
	memcpy(*buffer+sizeof(dtb)+sizeof(largo_data),data,largo_data);

	return sizeof(dtb)+sizeof(largo_data)+largo_data;
}

int s_fm9_diego_cargar_rsp(void** buffer, char response, uint32_t dtb) {

	*buffer = malloc(sizeof(response)+sizeof(dtb));

	memcpy(*buffer,&response,sizeof(response));
	memcpy(*buffer+sizeof(response),&dtb,sizeof(dtb));

	return sizeof(response)+sizeof(dtb);
}

handshake_fm9_sol d_diego_fm9_hadshake_sol(void* buffer) {

	handshake_fm9_sol hs_sol = { .hs = buffer};

	return hs_sol;
}

handshake_fm9_rsp d_fm9_diego_hadshake_rsp(void* buffer) {

	handshake_fm9_rsp hs_rsp = { .hs = buffer};

	return hs_rsp;
}

cargar_sol d_diego_fm9_cargar_sol(void* buffer) {

	cargar_sol c_sol;

	memset(&c_sol,0x00,sizeof(c_sol));

	memcpy(&c_sol,buffer,sizeof(cargar_sol));

	return c_sol;
}

/*
 * Requiere destruir mensaje
 */
cargar_rsp d_fm9_diego_cargar_rsp(void* buffer) {

	cargar_rsp c_rsp;

	memset(&c_rsp,0x00,sizeof(c_rsp));

	memcpy(&c_rsp.dtb,buffer,sizeof(c_rsp.dtb));
	memcpy(&c_rsp.largo_data,buffer+sizeof(c_rsp.dtb),sizeof(c_rsp.largo_data));
	c_rsp.data = malloc(c_rsp.largo_data);
	memset(c_rsp.data,0x00,c_rsp.largo_data);
	memcpy(c_rsp.data,buffer+sizeof(c_rsp.dtb)+sizeof(c_rsp.largo_data),c_rsp.largo_data);

	return c_rsp;
}

void destroy_cargar_rsp(cargar_rsp c_rsp) {

	free(c_rsp.data);

	return;
}
