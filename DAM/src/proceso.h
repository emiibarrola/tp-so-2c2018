/*
 * ifc_CPU.h
 *
 *  Created on: 11 oct. 2018
 *      Author: utnso
 */

#ifndef PROCESO_H_
#define PROCESO_H_

#include <shared.h>
#include <pthread.h>

int procesar_CPU(t_mensaje* msg, int socketCliente, fd_set* set_master);

#endif /* PROCESO_H_ */
