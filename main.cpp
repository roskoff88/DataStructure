#include "ABB.h"
#include "Pila.h"
#include "Cola.h"
#include <string.h>
#include <stdio.h>

int main(){
	char comando[256];
	printf(" Estructuras de datos: Pila, Cola y ABB\n");
	ABB * abb = crearABB();
	Pila * pila = crearPila();
	Cola * cola = crearCola();
	bool fin = false;
	int i;
	while (!fin){
		printf (">");
		scanf("%s",&comando);
		if (!strcmp(comando,"pilaAgregar")){
			scanf("%d",&i);
			apilar(pila, i);
			printf("El elemento %d se ha agregado a la pila.\n",i);
		}
		else if (!strcmp(comando,"pilaObtener")){
			i=desapilar(pila);
			printf("El tope de la pila es %d.\n",i);		
		}
		else if (!strcmp(comando,"colaAgregar")){
			scanf("%d",&i);
			encolar(cola, i);
			printf("El elemento %d se ha agregado en la cola.\n",i);

		}
		else if (!strcmp(comando,"colaObtener")){
			i=desencolar(cola);
			printf("El primer elemento de la cola es %d.\n",i);		
		}
		else if (!strcmp(comando,"abbAgregar")){
			scanf("%d",&i);
			agregarABB(abb, i);
			printf("El elemento %d se ha agregado en el ABB.\n",i);
		}
		else if (!strcmp(comando,"abbMinimo")){
			printf("El minimo elemento del ABB es %d.\n",menorABB(abb));
		}
		else if (!strcmp(comando,"abbMaximo")){
			printf("El maximo elemento del ABB es %d.\n",mayorABB(abb));
		}
		else if (!strcmp(comando,"salir")){
			fin = true;
		}
		else if (!strcmp(comando,"guardar")){
			char nombre[256];
			scanf("%s",nombre);
			char nombreABB[256], nombrePila[256], nombreCola[256];
			strcpy(nombreABB,nombre);//copia
			strcpy(nombrePila, nombre);
			strcpy(nombreCola, nombre);
			strcat(nombreABB,"_abb.txt");//adjunta
			strcat(nombrePila,"_pila.txt");
			strcat(nombreCola,"_cola.txt");
			guardarABBAArchivo(abb, nombreABB);
			guardarPilaAArchivo(pila, nombrePila);
			guardarColaAArchivo(cola, nombreCola);
		}
		else if (!strcmp(comando,"cargar")){
			char nombre[256];
			scanf("%s",nombre);
			char nombreABB[256], nombrePila[256], nombreCola[256];
			strcpy(nombreABB,nombre);//copia
			strcpy(nombrePila, nombre);
			strcpy(nombreCola, nombre);
			strcat(nombreABB,"_abb.txt");//adjunta
			strcat(nombrePila,"_pila.txt");
			strcat(nombreCola,"_cola.txt");
			cargarABBDeArchivo(abb, nombreABB);
			cargarPilaDeArchivo(pila, nombrePila);
			cargarColaDeArchivo(cola, nombreCola);
		}
		else 
			printf("Comando no reconocido\n");

	}
	return 0;
}
