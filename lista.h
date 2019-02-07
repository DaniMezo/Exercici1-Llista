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