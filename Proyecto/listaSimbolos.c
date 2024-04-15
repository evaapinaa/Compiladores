#include "listaSimbolos.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct PosicionListaRep {
  Simbolo dato;
  struct PosicionListaRep *sig;
};

struct ListaRep {
  PosicionLista cabecera;
  PosicionLista ultimo;
  int n;
};

typedef struct PosicionListaRep *NodoPtr;

Lista creaLS() {
  Lista nueva = malloc(sizeof(struct ListaRep));
  nueva->cabecera = malloc(sizeof(struct PosicionListaRep));
  nueva->cabecera->sig = NULL;
  nueva->ultimo = nueva->cabecera;
  nueva->n = 0;
  return nueva;
}

void liberaLS(Lista lista) {
  while (lista->cabecera != NULL) {
    NodoPtr borrar = lista->cabecera;
    lista->cabecera = borrar->sig;
    free(borrar);
  }
  free(lista);
}

void insertaLS(Lista lista, PosicionLista p, Simbolo s) {
  NodoPtr nuevo = malloc(sizeof(struct PosicionListaRep));
  nuevo->dato = s;
  nuevo->sig = p->sig;
  p->sig = nuevo;
  if (lista->ultimo == p) {
    lista->ultimo = nuevo;
  }
  (lista->n)++;
}

void suprimeLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  NodoPtr borrar = p->sig;
  p->sig = borrar->sig;
  if (lista->ultimo == borrar) {
    lista->ultimo = p;
  }
  free(borrar);
  (lista->n)--;
}

Simbolo recuperaLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig->dato;
}

PosicionLista buscaLS(Lista lista, char *nombre) {
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

PosicionLista inicioLS(Lista lista) {
  return lista->cabecera;
}

PosicionLista finalLS(Lista lista) {
  return lista->ultimo;
}

PosicionLista siguienteLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig;
}

/*
int perteneceTabSimb(char *nombre) {
    PosicionLista pos = buscaLS(tabSimb, nombre);
    if (pos != finalLS(tabSimb) && strcmp(recuperaLS(tabSimb, pos).nombre, nombre) == 0) {
        return 1;
    } else {
        return 0;
    }
}
*/

int perteneceTabSimb(char *nombre) {
  Lista tabSimb = creaLS();
  PosicionLista p = buscaLS(tabSimb, nombre);
  return p != finalLS(tabSimb);
}

void imprimirTabSimb(Lista tabSimb) {
    PosicionLista p = inicioLS(tabSimb);
    while (p != finalLS(tabSimb)) {
        Simbolo s = recuperaLS(tabSimb, p);
        printf("Nombre: %s, Tipo: %d, Valor: %d\n", s.nombre, s.tipo, s.valor);
        p = siguienteLS(tabSimb, p);
    }
}

/*
void insertarTS(char * nombre, Tipo tipo) {
    Simbolo nuevoSimbolo;
    nuevoSimbolo.nombre = nombre;
    nuevoSimbolo.tipo = tipo;
    nuevoSimbolo.valor = contCadenas;
    insertaLS(tabSimb, finalLS(tabSimb), nuevoSimbolo);
}
*/

void insertarTS(char *nombre, Tipo tipo) {
  Lista tabSimb = creaLS();
  PosicionLista p = buscaLS(tabSimb, nombre);
  if (p == finalLS(tabSimb)) {
    Simbolo s;
    strcpy(s.nombre, nombre);
    s.tipo = tipo;
    insertaLS(tabSimb, finalLS(tabSimb), s);
  } else {
    asignaLS(tabSimb, p, (Simbolo){nombre, tipo});
  }
}

int esConstante(char* nombre) {
    Lista tabSimb = creaLS();
    PosicionLista p = buscaLS(tabSimb, nombre);
    if (p != finalLS(tabSimb)) {
        Simbolo s = recuperaLS(tabSimb, p);
        if (s.tipo == CONSTANTE) {
            return 1;
        }
    }
    return 0;
}
