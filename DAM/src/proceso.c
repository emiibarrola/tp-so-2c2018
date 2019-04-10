/*
 * ifc_CPU.c
 *
 *  Created on: 11 oct. 2018
 *      Author: utnso
 */
#include "proceso.h"

#include "DAM.h"
#include "error.h"
#include "diego_cpu.h"
#include "mdj_diego.h"
#include "fm9_diego.h"
#include "safa_diego.h"

void *procesar_cpu(void *f_size) {
	void* buffer_msg = NULL;
	int largo = 0;
	int *file_size = (int *)f_size;

	t_mensaje* msg_mdj;
	t_mensaje* msg_fm9;
	t_mensaje* msg_safa;

	obtener_rsp o_rsp;

	int offset=0;
	int error=0;

	do {
		largo = s_diego_mdj_obtener_sol(&buffer_msg,1);

		pthread_mutex_lock(&lock_socket_mdj);
		if(enviarMensaje(diego, obtener, largo,
				buffer_msg, socket_mdj, logger) <= 0) {
			_exit_with_error("Ocurrio un error con MDJ",buffer_msg);
		}
		if((msg_mdj = recibirMensaje(socket_mdj, logger))== NULL) {
			destruirMensaje(msg_mdj);
			_exit_with_error("Ocurrio un error con MDJ",buffer_msg);
		}
		pthread_mutex_unlock(&lock_socket_mdj);

		o_rsp = d_mdj_diego_obtener_rsp(msg_mdj->content);

		offset = o_rsp.response;

		largo = s_diego_fm9_cargar_sol(&buffer_msg,1,o_rsp.largo_data, o_rsp.data);

		pthread_mutex_lock(&lock_socket_fm9);
		if (enviarMensaje(diego, cargar, largo,
				buffer_msg, socket_fm9, logger) <= 0) {
			destruirMensaje(msg_mdj);
			destroy_obtener_rsp(o_rsp);
			_exit_with_error("Ocurrio un error con FM9",buffer_msg);
		}
		if((msg_fm9 = recibirMensaje(socket_fm9, logger))== NULL) {
			destruirMensaje(msg_mdj);
			destroy_obtener_rsp(o_rsp);
			destruirMensaje(msg_fm9);
			_exit_with_error("Ocurrio un error con FM9",buffer_msg);
		}
		pthread_mutex_lock(&lock_socket_fm9);

		//cargar_rsp c_rsp = d_fm9_diego_cargar_rsp(msg_fm9->content);

		destruirMensaje(msg_mdj);
		destroy_obtener_rsp(o_rsp);
		destruirMensaje(msg_fm9);
		destruirBuffer(buffer_msg);
	} while(offset!=0 && offset<*file_size);

	if(offset<*file_size)
		error = 1;

	largo = s_diego_safa_listo_sol(&buffer_msg,error,1);

	pthread_mutex_lock(&lock_socket_safa);
	if(enviarMensaje(diego, listo, largo,
			buffer_msg, socket_safa, logger) <= 0) {
		_exit_with_error("Ocurrio un error con SAFA",buffer_msg);
	}
	if((msg_safa = recibirMensaje(socket_mdj, logger))== NULL) {
		destruirMensaje(msg_safa);
		_exit_with_error("Ocurrio un error con SAFA",buffer_msg);
	}
	pthread_mutex_lock(&lock_socket_safa);

	//l_rsp = d_safa_diego_listo_rsp(msg_mdj->content);

	destruirMensaje(msg_safa);
	destroy_obtener_rsp(o_rsp);
	destruirBuffer(buffer_msg);

	return NULL;
}

int procesar_CPU(t_mensaje* msg, int socketCPU, fd_set* set_master) {

	void* buffer_msg = NULL;
	int largo = 0;
	t_mensaje* msg_mdj;

	switch(msg->header.tipoMensaje) {
		case handshake: ;
			largo = s_diego_cpu_hadshake_rsp(&buffer_msg);
			if(enviarMensaje(diego, handshake, largo,
					buffer_msg, socketCPU, logger) <= 0) {
				close(socketCPU);
				FD_CLR(socketCPU, set_master);
				//destruirMensaje(msg);
				return 0;
			}
			break;
		case buscar: ;
			buscar_sol b_sol = d_cpu_diego_buscar_sol(msg->content);
			loggear(logger,LOG_LEVEL_INFO, "Ehhh voy a buscar '%s' para %d",b_sol.path, socketCPU);

			largo = s_diego_mdj_verificar_sol(&buffer_msg,1);

			pthread_mutex_lock(&lock_socket_mdj);
			if(enviarMensaje(diego, verificar, largo,
					buffer_msg, socket_mdj, logger) <= 0) {
				destroy_buscar_sol(b_sol);
				destruirMensaje(msg);
				_exit_with_error("Ocurrio un error con MDJ",buffer_msg);
			}
			if((msg_mdj = recibirMensaje(socket_mdj, logger))== NULL) {
				destroy_buscar_sol(b_sol);
				destruirMensaje(msg_mdj);
				destruirMensaje(msg);
				_exit_with_error("Ocurrio un error con MDJ",buffer_msg);
			}
			pthread_mutex_lock(&lock_socket_mdj);

			verificar_rsp v_rsp = d_mdj_diego_verificar_rsp(msg->content);

			largo = s_diego_cpu_buscar_rsp(&buffer_msg, v_rsp.response, 1);
			if(enviarMensaje(diego, buscar, largo,
					buffer_msg, socketCPU, logger) <= 0) {
				destroy_buscar_sol(b_sol);
				destruirMensaje(msg_mdj);
				destruirMensaje(msg);
				_exit_with_error("Ocurrio un error con MDJ",buffer_msg);
			}

			//TODO: CREAR HILO PARA PROCESAMIENTO DE OBTENER
			pthread_t procesar_cpu_thread;
			if(pthread_create(&procesar_cpu_thread, NULL, procesar_cpu, &v_rsp.response)) {

				loggear(logger,LOG_LEVEL_ERROR, "Error creando thread\n");
				destroy_buscar_sol(b_sol);
				destruirMensaje(msg_mdj);
				destruirBuffer(buffer_msg);
				return -1;
			}

			destroy_buscar_sol(b_sol);
			destruirMensaje(msg_mdj);
			destruirBuffer(buffer_msg);
			break;
		default:
			loggear(logger,LOG_LEVEL_ERROR, "No se reconoce el Comando: %d",msg->header.tipoMensaje);
			break;
	}
	return 1;
}

