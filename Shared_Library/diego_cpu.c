/*
 * msg_cpu.c
 *
 *  Created on: 8 oct. 2018
 *      Author: utnso
 */

#include "diego_cpu.h"

int s_cpu_diego_hadshake_sol(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_diego_cpu_hadshake_rsp(void** buffer) {

	*buffer = NULL;

	return 0;
}

int s_cpu_diego_buscar_sol(void** buffer, uint32_t dtb, uint32_t largo_path, char* path) {

	*buffer = malloc(sizeof(dtb)+sizeof(largo_path)+largo_path);

	memcpy(*buffer,&dtb,sizeof(dtb));
	memcpy(*buffer+sizeof(dtb),&largo_path,sizeof(largo_path));
	memcpy(*buffer+sizeof(dtb)+sizeof(largo_path),path,largo_path);

	return sizeof(dtb)+sizeof(largo_path)+largo_path;
}

int s_diego_cpu_buscar_rsp(void** buffer, char response, uint32_t dtb) {

	*buffer = malloc(sizeof(response)+sizeof(dtb));

	memcpy(*buffer,&response,sizeof(response));
	memcpy(*buffer+sizeof(response),&dtb,sizeof(dtb));

	return sizeof(response)+sizeof(dtb);
}

handshake_diego_sol d_cpu_diego_hadshake_sol(void* buffer) {

	handshake_diego_sol hs_sol = { .hs = buffer};

	return hs_sol;
}

handshake_diego_rsp d_diego_cpu_hadshake_rsp(void* buffer) {

	handshake_diego_rsp hs_rsp = { .hs = buffer};

	return hs_rsp;
}

buscar_sol d_cpu_diego_buscar_sol(void* buffer) {

	buscar_sol b_sol;

	memset(&b_sol,0x00,sizeof(b_sol));

	memcpy(&b_sol.dtb,buffer,sizeof(b_sol.dtb));
	memcpy(&b_sol.largo_path,buffer+sizeof(b_sol.dtb),sizeof(b_sol.largo_path));
	b_sol.path = malloc(b_sol.largo_path+1);
	memset(b_sol.path,0x00,b_sol.largo_path+1);
	strncpy(b_sol.path,buffer+sizeof(b_sol.dtb)+sizeof(b_sol.largo_path),b_sol.largo_path);


	return b_sol;
}

void destroy_buscar_sol(buscar_sol b_sol) {

	free(b_sol.path);

	return;
}

buscar_rsp d_diego_cpu_buscar_rsp(void* buffer) {

	buscar_rsp b_rsp;

	memset(&b_rsp,0x00,sizeof(b_rsp));

	memcpy(&b_rsp,buffer,sizeof(buscar_rsp));

	return b_rsp;
}

