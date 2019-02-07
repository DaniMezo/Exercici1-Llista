#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

ListaBid listabidCreate(){
    ListaBid l;
    l.first = (Node *) malloc(sizeof(Node)); //Asignacion de memoria
    if(l.first == NULL)
    {
        printf("Error al crear la llista\n");
    }else{
        l.last=(Node *) malloc(sizeof(Node));
        if(l.last==NULL)
        {
            printf("Error al crear la llista\n");
            free(l.first);
        }else{
            l.pdi=l.last;
            l.first->seguent=l.last;
            l.last->anterior=l.first;
            l.first->anterior=NULL;
            l.last->seguent=NULL;
        }
    }
    return l;
}

void listabidIntroduceOrdenado(ListaBid *l, Element e){
    Node *aux;
    int trobat=0;
    Node *pdi;
    aux=(Node *) malloc(sizeof(Node));
    if(aux==NULL){
        printf("Error al insertar l'element\n");
    }else{
        aux->e=e;
        pdi = l->pdi;
        l->pdi=l->first->seguent;
        if(l->first->seguent==l->last)
        {
            aux->seguent=l->pdi;
            aux->anterior=l->pdi->anterior;
            aux->anterior->seguent=aux;
            l->pdi->anterior=aux;
        }else{
            l->pdi=l->first->seguent;
            while(!trobat && l->pdi->seguent !=NULL){
                if(l->pdi->e <=e){
                    l->pdi = l->pdi->seguent;
                }else{
                    trobat=1;
                    aux->anterior=l->pdi->anterior;
                    aux->anterior->seguent=aux;
                    aux->seguent=l->pdi;
                    l->pdi->anterior=aux;
                }
            }
            if(!trobat)
            {
                l->pdi=l->last;
                aux->seguent=l->pdi;
                aux->anterior=l->pdi->anterior;
                aux->anterior->seguent=aux;
                l->pdi->anterior=aux;
            }
            l->pdi=pdi;
        }
    }
}
Element listabidConsulta(ListaBid l){
    Element e;

    if (l.pdi==l.first || l.pdi==l.last) {
        printf("No se puede consultar el elemento\n");
    }else{
        e = l.pdi->e;
    }
    return e;
}
void listabidBorrar(ListaBid *l){
    Node *aux;
    if(l->pdi==l->first || l->pdi == l->last)
    {
        printf("Error\n");
    }else{
        aux=l->pdi;
        l->pdi=l->pdi->seguent;
        aux->anterior->seguent=aux->seguent;
        aux->seguent->anterior=aux->anterior;
        free(aux);
    }
}
void listabidAvanza(ListaBid *l){
    if(l->pdi->seguent!=NULL)
    {
        l->pdi=l->pdi->seguent;
    }else{
        printf("Error al avanzar\n");
    }
}
void listabidRetrocede(ListaBid *l){
    if(l->pdi==l->first)
    {
        printf("Error al retroceder\n");
    }else{
        l->pdi=l->pdi->anterior;
    }
}