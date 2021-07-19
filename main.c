#include <stdlib.h>
#include "lista.h"

int main() {
    TipoLista lista;
    lista = lista_vacia();
    lista = inserta_por_cabeza(lista, 2);
    lista = inserta_por_cabeza(lista, 8);
    lista = inserta_por_cabeza(lista, 3);
    lista = inserta_por_cola(lista, 10);
    lista = inserta_por_cola(lista, 12);
    lista = inserta_por_cabeza(lista, 1);
    lista = inserta_por_cola(lista, 13);

    printf("Longitud de la lista: %d\n", longitud_lista(lista));
    printf("Elemento maximo: %d\n", elemento_maximo(lista));
    printf("Media: %f\n", media(lista));
    muestra_lista(lista);
    muestra_lista_estilo_python(lista);
    muestra_lista_estilo_nuevo(lista);
    
    return 0;
}
