#include "listaSimbolos.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct PosicionListaRep {
  Simbolo dato;
  struct PosicionListaRep *sig;
};

struct ListaRep {	//Definicion de la estructura lista de Simbolos
  PosicionLista cabecera;
  PosicionLista ultimo;
  int n;
};

typedef struct PosicionListaRep *NodoPtr;

Lista creaLS() {	//Crear una nueva lista vacia
  Lista nueva = malloc(sizeof(struct ListaRep));
  nueva->cabecera = malloc(sizeof(struct PosicionListaRep));
  nueva->cabecera->sig = NULL;
  nueva->ultimo = nueva->cabecera;
  nueva->n = 0;
  return nueva;
}

void liberaLS(Lista lista) {	//Liberar una lista (Vacía y no vacia)
  while (lista->cabecera != NULL) {
    NodoPtr borrar = lista->cabecera;
    lista->cabecera = borrar->sig;
    free(borrar);
  }
  free(lista);
}

void insertaLS(Lista lista, PosicionLista p, Simbolo s) { //Insertar nuevo elemento a la lista
  NodoPtr nuevo = malloc(sizeof(struct PosicionListaRep));
  nuevo->dato = s;
  nuevo->sig = p->sig;
  p->sig = nuevo;
  if (lista->ultimo == p) {
    lista->ultimo = nuevo;
  }
  (lista->n)++;
}

void suprimeLS(Lista lista, PosicionLista p) {	//Eliminar un elemento de la lista
  assert(p != lista->ultimo);
  NodoPtr borrar = p->sig;
  p->sig = borrar->sig;
  if (lista->ultimo == borrar) {
    lista->ultimo = p;
  }
  free(borrar);
  (lista->n)--;
}

Simbolo recuperaLS(Lista lista, PosicionLista p) {	//Recupera un elemento
  assert(p != lista->ultimo);
  return p->sig->dato;
}

PosicionLista buscaLS(Lista lista, char *nombre) {	//Buscar un elemento, recibe como parametro la lista a analizar y el elemento buscado
  NodoPtr aux = lista->cabecera;
  while (aux->sig != NULL && strcmp(aux->sig->dato.nombre,nombre) != 0) {
    aux = aux->sig;
  }
  return aux;
}

void asignaLS(Lista lista, PosicionLista p, Simbolo s) {
  assert(p != lista->ultimo);
  p->sig->dato = s;
}

int longitudLS(Lista lista) {
  return lista->n;
}

PosicionLista inicioLS(Lista lista) {	//Devuelve el inicio de la lista
  return lista->cabecera;
}

PosicionLista finalLS(Lista lista) {	//Devuelve el fin de la lista
  return lista->ultimo;
}

PosicionLista siguienteLS(Lista lista, PosicionLista p) {	//Devuelve el siguiente respecto a una posicion
  assert(p != lista->ultimo);
  return p->sig;
}
