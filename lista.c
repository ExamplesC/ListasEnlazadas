#include <stdlib.h>
#include "lista.h"

TipoLista lista_vacia() {
    return NULL;
}

int es_lista_vacia(TipoLista lista) {
    return lista == NULL;
}

TipoLista inserta_por_cabeza(TipoLista lista, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    
    nuevo->info = valor;
    nuevo->sig = lista;
    lista = nuevo;

    return lista;
}

TipoLista inserta_por_cola(TipoLista lista, int valor) {
    struct Nodo *aux, *nuevo;
    nuevo = malloc(sizeof(struct Nodo));
    nuevo->info = valor;
    nuevo->sig = NULL;

    if (!es_lista_vacia(lista)) {
        for (aux = lista; aux->sig != NULL; aux = aux->sig);
        aux->sig = nuevo;
    } else {
        lista = nuevo;
    }

    return lista;
}

int longitud_lista(TipoLista lista) {
    struct Nodo *aux;
    int longitud = 0;

    for (aux = lista; aux != NULL; aux = aux->sig) {
        ++longitud;
    }

    return longitud;
}

int elemento_maximo(TipoLista lista) {
    struct Nodo *aux;
    int maximo = 0;

    if (!es_lista_vacia(lista)) {
        maximo = lista->info;
        for (aux = lista; aux != NULL; aux = aux->sig) {
            if (aux->info > maximo) {
                maximo = aux->info;
            }
        }
    }

    return maximo;
}

float media(TipoLista lista) {
    struct Nodo *aux;
    float media = 0.0;
    float suma = 0.0;
    int contador = 0;

    if (!es_lista_vacia(lista)) {
        for (aux = lista; aux != NULL; aux = aux->sig) {
            suma += aux->info;
            ++contador;
        }

        media = suma / contador;
    }

    return media;
}

void muestra_lista(TipoLista lista) {
    struct Nodo *aux;
    for (aux = lista; aux != NULL; aux = aux->sig) {
        printf("%d\n", aux->info);
    }
}

void muestra_lista_estilo_python(TipoLista lista) {
    struct Nodo *aux;

    printf("[");
    for (aux = lista; aux != NULL; aux = aux->sig) {
        printf("%d", aux->info);
        if (aux->sig != NULL) {
            printf(",");
        }
    }
    printf("]\n");
}


void muestra_lista_estilo_nuevo(TipoLista lista) {
    struct Nodo *aux;

    for (aux = lista; aux != NULL; aux = aux->sig) {
        printf("->%d", aux->info);
    }
    printf("->|\n");
}

/* Borra el primer nodo de la lista */
TipoLista borra_cabeza(TipoLista lista) {
    struct Nodo *aux;
    if (!es_lista_vacia(lista)) {
        aux = lista->sig;
        free(lista);
        lista = aux;
    }
    return lista;
}

/* Borra el último nodo de la lista */
TipoLista borra_cola(TipoLista lista) {
    struct Nodo *aux, *atras;

    if (!es_lista_vacia(lista)) {
        for (atras = NULL, aux = lista; aux->sig != NULL; atras = aux, aux = aux->sig);
        free(aux);
        if (atras == NULL) {
            lista = NULL;
        } else {
            atras->sig = NULL;
        }
    }

    return lista;
}