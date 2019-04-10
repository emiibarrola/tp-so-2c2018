#ifndef CPU_H_
#define CPU_H_

/*
    Este es el archivo de header de nuestro programa.
    Sirve para definir cosas que pueden sernos utiles en varios lados,
    o simplemente para poder delegar #includes de bibliotecas, estructuras
    o los prototipos de las funciones que querramos hacer publicas.
    Las guardas #ifndef, #define y #endif sirven para darle informacion al
    preprocesador de c sobre algunas cosas. Estas son importantes en
    el header, ya que nos protegen de problemas si hay doble inclusion
    del mismo archivo de header 2 veces.
*/

// Aca incluimos las bibliotecas que vamos a usar
#include <shared.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // Para close
#include <stdint.h>
#include <readline/readline.h> // Para usar readline
#include <commons/log.h>
#include <commons/config.h>
#include <commons/collections/list.h>

// Definimos algunas constantes para nuestro código

// Definimos algunas variables globales

typedef struct  {
  int iOperacion;
  void* vData;
} t_CPU;

t_CPU CPU;

t_log * logger;

int socket_fm9;
int socket_diego;
int socket_safa;

// Finalmente, los prototipos de las funciones que vamos a implementar

void retardo(int iRetardo);
void execute();

#endif /* CPU_H_ */
