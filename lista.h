struct Nodo {
    int info;
    struct Nodo *sig;
};

typedef struct Nodo *TipoLista;

extern TipoLista lista_vacia(void);
extern int es_lista_vacia(TipoLista lista);
extern TipoLista inserta_por_cabeza(TipoLista lista, int valor);
extern TipoLista inserta_por_cola(TipoLista lista, int valor);
extern int longitud_lista(TipoLista lista);
extern int elemento_maximo(TipoLista lista);
extern float media(TipoLista lista);
extern void muestra_lista(TipoLista lista);
extern void muestra_lista_estilo_python(TipoLista lista_vacia);
extern void muestra_lista_estilo_nuevo(TipoLista lista_vacia);
