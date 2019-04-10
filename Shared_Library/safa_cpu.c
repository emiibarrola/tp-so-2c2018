/*
 * msg_safa_cpu.c
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#include "safa_cpu.h"

int s_cpu_safa_hadshake_sol(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_safa_cpu_hadshake_rsp(void** buffer,char quantum ,uint32_t largo_algoritmo, char* algoritmo) {

	*buffer = malloc(sizeof(quantum)+sizeof(largo_algoritmo)+largo_algoritmo);

	memcpy(*buffer,&quantum,sizeof(quantum));
	memcpy(*buffer+sizeof(quantum),&largo_algoritmo,sizeof(largo_algoritmo));
	memcpy(*buffer+sizeof(quantum)+sizeof(largo_algoritmo),algoritmo,largo_algoritmo);

	return sizeof(quantum)+sizeof(largo_algoritmo)+largo_algoritmo;
}

int s_safa_cpu_cargar_sol(void** buffer, uint32_t dtb, uint32_t largo_data, void* data) {

	*buffer = malloc(sizeof(dtb)+sizeof(largo_data)+largo_data);

	memcpy(*buffer,&dtb,sizeof(dtb));
	memcpy(*buffer+sizeof(dtb),&largo_data,sizeof(largo_data));
	memcpy(*buffer+sizeof(dtb)+sizeof(largo_data),data,largo_data);

	return sizeof(dtb)+sizeof(largo_data)+largo_data;
}

int s_cpu_safa_cargar_rsp(void** buffer, char response, uint32_t dtb) {

	*buffer = malloc(sizeof(response)+sizeof(dtb));

	memcpy(*buffer,&response,sizeof(response));
	memcpy(*buffer+sizeof(dtb),&response,sizeof(response));

	return sizeof(response)+sizeof(dtb);
}

handshake_safa_sol d_cpu_safa_hadshake_sol(void* buffer) {

	handshake_safa_sol hs_sol = { .hs = buffer};

	return hs_sol;
}

/*
 * Requiere destruir mensaje
 */
handshake_safa_rsp d_safa_cpu_hadshake_rsp(void* buffer) {

	handshake_safa_rsp hs_rsp;

	memset(&hs_rsp,0x00,sizeof(hs_rsp));

	memcpy(&hs_rsp.quantum,buffer,sizeof(hs_rsp.quantum));
	memcpy(&hs_rsp.largo_algoritmo,buffer+sizeof(hs_rsp.quantum),sizeof(hs_rsp.largo_algoritmo));
	hs_rsp.algritmo = malloc(hs_rsp.largo_algoritmo+1);
	memset(hs_rsp.algritmo,0x00,hs_rsp.largo_algoritmo+1);
	strncpy(hs_rsp.algritmo,buffer+sizeof(hs_rsp.quantum)+sizeof(hs_rsp.largo_algoritmo),hs_rsp.largo_algoritmo);

	return hs_rsp;
}

void destroy_handshake_safa_rsp(handshake_safa_rsp hs_rsp) {

	free(hs_rsp.algritmo);

	return;
}

/*
 * Requiere destruir mensaje
 */
ejecutar_sol d_safa_cpu_cargar_sol(void* buffer) {

	ejecutar_sol e_sol;

	memset(&e_sol,0x00,sizeof(e_sol));

	memcpy(&e_sol.dtb,buffer,sizeof(e_sol.dtb));
	memcpy(&e_sol.largo_data,buffer+sizeof(e_sol.dtb),sizeof(e_sol.largo_data));
	e_sol.data = malloc(e_sol.largo_data);
	memset(e_sol.data,0x00,e_sol.largo_data);
	memcpy(e_sol.data,buffer+sizeof(e_sol.dtb)+sizeof(e_sol.largo_data),e_sol.largo_data);

	return e_sol;
}

void destroy_ejecutar_sol(ejecutar_sol e_sol) {

	free(e_sol.data);

	return;
}

ejecutar_rsp d_cpu_safa_cargar_rsp(void* buffer) {

	ejecutar_rsp e_rsp;

	memset(&e_rsp,0x00,sizeof(e_rsp));

	memcpy(&e_rsp,buffer,sizeof(ejecutar_rsp));

	return e_rsp;
}
