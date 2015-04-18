#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Cola.h"
struct Nodo{
	int dato;
	Nodo * sig;
};
struct Cola{
	Nodo * primero, *ultimo;
};

Cola* crearCola(){
	Cola * n = new Cola;
	n->primero=NULL;
	n->ultimo=NULL;
	return n;
}


bool esVaciaCola(Cola* c){
	return c->primero == NULL;
}


void encolar(Cola* &c, int i){
	if (c->primero == NULL){
		c->primero = new Nodo;
		c->ultimo = c->primero;
		c->primero->dato = i;
		c->primero->sig = NULL;
	}
	else
	{
		c->ultimo->sig = new Nodo;
		c->ultimo=c->ultimo->sig;
		c->ultimo->sig=NULL;
		c->ultimo->dato=i;
	}
}


int desencolar(Cola* &c){
	Nodo * temp = c->primero;
	int i = temp->dato;
	c->primero = temp->sig;
	delete temp;
	return i;
}

void destruirCola(Cola* &c){
	Nodo * l = c->primero;
	while (l!=NULL){
		Nodo * temp = l;
		l = l->sig;
		delete temp;
	}
	delete c;
	c = NULL;
}


void cargarColaDeArchivo(Cola* &c, char* nomArchivo){
	FILE * f = fopen(nomArchivo,"r");
	destruirCola(c);
	c=crearCola();
	while (!feof(f)){
		char buffer[256];
		fscanf(f,"%s", &buffer);
		if (strcmp(buffer, "FIN"))
			encolar(c, atoi(buffer));	
	}
	fclose(f);
}

void guardarColaAArchivo(Cola* c, char* nomArchivo){
	FILE * f = fopen(nomArchivo,"w");
	Nodo * l = c->primero;
	while (l!=NULL){
		fprintf(f,"%d\n",l->dato);
		l=l->sig;
	}
	fprintf(f,"FIN\n");
	fclose(f);
}