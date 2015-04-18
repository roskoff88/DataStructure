#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"
struct Pila{
	int dato;
	Pila * sig;
};

Pila* crearPila()
{
	return NULL;
}


bool esVaciaPila(Pila* p){
	return p ==NULL;
}

void apilar(Pila* &p, int i)
{
	Pila * n = new Pila;
	n->dato=i;
	n->sig=p;
	p=n;
}


int desapilar(Pila* &p){
	int d = p->dato;
	Pila * temp = p;
	p=p->sig;
	delete temp;
	return d;
}

void destruirPila(Pila* &p){
	if (p != NULL){
		destruirPila(p->sig);
		delete p;
		p = NULL;
	}
}

void cargarRec(Pila* &p, FILE * f){
		char buffer[256];
		fscanf(f,"%s", &buffer);
		if (strcmp(buffer, "FIN"))
		{
			cargarRec(p, f);
			apilar(p, atoi(buffer));	
		}
}
void cargarPilaDeArchivo(Pila* &p, char* nomArchivo){
	FILE * f = fopen(nomArchivo,"r");
	destruirPila(p);
	p=crearPila();
	cargarRec(p, f);
	fclose(f);
}

void guardarPilaAArchivo(Pila* p, char* nomArchivo){
	FILE * f = fopen(nomArchivo,"w");
	Pila * l = p;
	while (l!=NULL){
		fprintf(f,"%d\n",l->dato);
		l=l->sig;
	}
	fprintf(f,"FIN\n");
	fclose(f);
}


