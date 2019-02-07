#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void mostrarLista(ListaBid *lista)
{
    listabidGoFirst(lista);
    while (!listabidFinal(*lista))
    {
        printf("\t %d\n", listabidConsulta(*lista));
        listabidAvanza(lista);
    }
}
void llenarLista(ListaBid *lista)
{
    printf("Insercion de los elementos\n");
    listabidIntroduceOrdenado(lista, 5);
    listabidIntroduceOrdenado(lista, 55);
    listabidIntroduceOrdenado(lista, 10);
    listabidIntroduceOrdenado(lista, 21);
    listabidIntroduceOrdenado(lista, 24);
    listabidIntroduceOrdenado(lista, 8);
}

void main() {
    ListaBid lista;
    lista = listabidCreate();
    llenarLista(&lista);
    printf("Mostramos la lista\n");
    mostrarLista(&lista);
}