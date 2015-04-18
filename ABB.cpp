#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"
#include <string.h>
struct ABB{
	int dato;
	ABB * izq, *der;
};

ABB* crearABB(){
	return NULL;
};


void agregarABB(ABB* &abb, int i){
	if (abb ==NULL){
		abb = new ABB;
		abb->dato=i;
		abb->izq = NULL;
		abb->der = NULL;
	}
	else if (abb->dato > i)
		agregarABB(abb->izq, i);
	else 
		agregarABB(abb->der, i);
}

bool esVacioABB(ABB* abb){
	return abb == NULL;
}


int valorABB(ABB* abb){
	return abb->dato;
}

ABB* arbolIzquierdo(ABB* abb){
	return abb->izq;
}

ABB* arbolDerecho(ABB* abb){
	return abb->der;
}

int menorABB(ABB* &abb){
	if (abb->izq == NULL)
		return abb->dato;
	else
		return menorABB(abb->izq);
}

int mayorABB(ABB* &abb){
	if (abb->der == NULL)
		return abb->dato;
	else
		return mayorABB(abb->der);
}

void destruirABB(ABB* &abb){
	if (abb != NULL){
		destruirABB(abb->izq);
		destruirABB(abb->der);
		delete abb;
		abb = NULL;
	}
}

void cargarRec(FILE * f, ABB* & abb){
	char buffer[255];
	fscanf(f,"%s", &buffer);

	if (!strcmp(buffer,"NULL"))
		abb=crearABB();
	else
	{
		abb = new ABB;
		abb->dato = atoi(buffer);
		cargarRec(f, abb->izq);
		cargarRec(f, abb->der);
	}
}
void cargarABBDeArchivo(ABB* &abb, char* nomArchivo){
	FILE * f = fopen(nomArchivo,"r");
	destruirABB(abb);
	cargarRec(f,abb);
	fclose(f);
}

void guardarRec(FILE * f, ABB* abb){
	if (abb == NULL)
		fprintf(f,"NULL\n");
	else
	{
		fprintf(f,"%d\n",abb->dato);
		guardarRec(f, abb->izq);
		guardarRec(f, abb->der);
	}
}

void guardarABBAArchivo(ABB* abb, char* nomArchivo){
	FILE * f = fopen(nomArchivo,"w");
	guardarRec(f,abb);
	fprintf(f,"FIN\n");
	fclose(f);
}
