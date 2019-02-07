#ifndef EJERCICIO1_LISTA_H
#define EJERCICIO1_LISTA_H
typedef int Element;
typedef struct n{
    Element e;
    struct n *anterior;
    struct n *seguent;
}Node;
typedef struct{
    Node *first;
    Node *last;
    Node *pdi;
}ListaBid;

#define ELEMENT_indefinit -10


ListaBid listabidCreate();
void listabidIntroduceOrdenado(ListaBid *lista, Element e);
Element listabidConsulta(ListaBid lista);
void listabidBorrar(ListaBid *lista);
void listabidAvanza(ListaBid *lista);//Tira una posicion hacia el final de la cola
void listabidRetrocede(ListaBid *lista);//Tira una posicion hacia adelante de la cola
int listabidFinal(ListaBid lista);
int listabidInicio(ListaBid lista);
void listabidGoFirst(ListaBid *lista);
void listabidGoLast(ListaBid *lista);
int listabidBacia(ListaBid lista);
void listabidDestruye(ListaBid *lista);

#endif //EJERCICIO1_LISTA_H