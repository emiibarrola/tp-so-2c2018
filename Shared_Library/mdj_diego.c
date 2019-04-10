/*
 * msg_cpu.c
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#include "mdj_diego.h"

int s_diego_mdj_hadshake_sol(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_mdj_diego_hadshake_rsp(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_diego_mdj_verificar_sol(void** buffer, uint32_t dtb) {

	*buffer = malloc(sizeof(dtb));

	memcpy(*buffer,&dtb,sizeof(dtb));

	return sizeof(dtb);
}

int s_mdj_diego_verificar_rsp(void** buffer, char response, uint32_t dtb) {

	*buffer = malloc(sizeof(response)+sizeof(dtb));

	memcpy(*buffer,&response,sizeof(response));
	memcpy(*buffer+sizeof(response),&dtb,sizeof(dtb));

	return sizeof(response)+sizeof(dtb);
}

int s_diego_mdj_obtener_sol(void** buffer, uint32_t dtb) {

	*buffer = malloc(sizeof(dtb));

	memcpy(*buffer,&dtb,sizeof(dtb));

	return sizeof(dtb);
}

int s_mdj_diego_obtener_rsp(void** buffer, char response, uint32_t dtb, uint32_t largo_data, void* data) {

	*buffer = malloc(sizeof(response)+sizeof(dtb)+sizeof(largo_data)+largo_data);

	memcpy(*buffer,&response,sizeof(response));
	memcpy(*buffer+sizeof(response),&dtb,sizeof(dtb));
	memcpy(*buffer+sizeof(response)+sizeof(dtb),&largo_data,sizeof(largo_data));
	memcpy(*buffer+sizeof(response)+sizeof(dtb)+sizeof(largo_data),data,largo_data);

	return sizeof(response)+sizeof(dtb)+sizeof(largo_data)+largo_data;
}

handshake_mdj_sol d_diego_mdj_hadshake_sol(void* buffer) {

	handshake_mdj_sol hs_sol = { .hs = buffer};

	return hs_sol;
}

handshake_mdj_rsp d_mdj_diego_hadshake_rsp(void* buffer) {

	handshake_mdj_rsp hs_rsp = { .hs = buffer};

	return hs_rsp;
}

obtener_sol d_diego_mdj_obtener_sol(void* buffer) {

	obtener_sol o_sol;

	memcpy(&o_sol,buffer,sizeof(obtener_sol));

	return o_sol;
}

/*
 * Requiere destruir mensaje
 */
obtener_rsp d_mdj_diego_obtener_rsp(void* buffer) {

	obtener_rsp o_rsp;

	memset(&o_rsp,0x00,sizeof(o_rsp));

	memcpy(&o_rsp.response,buffer,sizeof(o_rsp.response));
	memcpy(&o_rsp.dtb,buffer+sizeof(o_rsp.response),sizeof(o_rsp.dtb));
	memcpy(&o_rsp.largo_data,buffer+sizeof(o_rsp.response)+sizeof(o_rsp.dtb),sizeof(o_rsp.largo_data));
	o_rsp.data = malloc(o_rsp.largo_data);
	memset(o_rsp.data,0x00,o_rsp.largo_data);
	memcpy(o_rsp.data,buffer+sizeof(o_rsp.response)+sizeof(o_rsp.dtb)+sizeof(o_rsp.largo_data),o_rsp.largo_data);

	return o_rsp;
}

void destroy_obtener_rsp(obtener_rsp o_rsp) {

	free(o_rsp.data);

	return;
}

verificar_sol d_diego_mdj_verificar_sol(void* buffer) {

	verificar_sol v_sol;

	memcpy(&v_sol,buffer,sizeof(verificar_sol));

	return v_sol;
}

verificar_rsp d_mdj_diego_verificar_rsp(void* buffer) {

	verificar_rsp v_rsp;

	memcpy(&v_rsp,buffer,sizeof(verificar_rsp));

	return v_rsp;
}
