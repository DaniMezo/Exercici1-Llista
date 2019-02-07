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