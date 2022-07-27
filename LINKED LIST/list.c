#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
    int value;
    struct node* next;
};

struct list {
    Node_t* first;
    Node_t* last;
    int size;
};

List_t* createList () {
    List_t* l = (List_t*) malloc(sizeof (List_t));
    if (l == NULL) return NULL;

    l->first = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}

int size (List_t* l) {
    if (l == NULL) return -1;

    return l->size;
}

Node_t* createNode (int value) {
    Node_t* n = (Node_t*) malloc(sizeof (Node_t));
    if (n == NULL) return NULL;

    n->value = value;
    n->next = NULL;

    return n;
}

int inList (int x, List_t* l) {
    if (l == NULL) return -1;

    Node_t* aux = l->first;
    while (aux != NULL) {
        if (aux->value == x) return 1;
        aux = aux->next;
    }

    return 0;
}

int insert (int x, List_t* l) {
    if (l == NULL) return -1;

    if (inList(x, l)) return 0;

    Node_t* n = createNode(x);
    if (n == NULL) return -1;

    if (size(l) == 0) l->first = n;
    else l->last->next = n;
    l->last = n;

    l->size++;

    return 1;
}

int delete (int x, List_t* l) {
    if (l == NULL) return -1;

    Node_t* prev = NULL;
    Node_t* aux = l->first;
    while (aux != NULL) {
        if (aux->value == x) {
            if (aux == l->first) {
                l->first = aux->next;

            } else if (aux == l->last) {
                l->last = prev;
                l->last->next = NULL;

            } else {
                prev->next = aux->next;

            }
            
            free(aux);

            l->size--;

            return 1;
        }

        prev = aux;
        aux = aux->next;
    }

    return 0;
}

void printList (List_t* l) {
    if (l == NULL) return;

    Node_t* aux = l->first;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void destroyList (List_t* l) {
    if (l == NULL) return;

    Node_t* aux = l->first;
    while (aux != NULL) {
        l->first = aux->next;
        free(aux);
        aux = l->first;
    }
    free(l);
}
