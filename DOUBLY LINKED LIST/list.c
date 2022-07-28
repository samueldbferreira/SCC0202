#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
    int value;
    struct node* prev;
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

Node_t* createNode (int value) {
    Node_t* n = (Node_t*) malloc(sizeof (Node_t));
    if (n == NULL) return NULL;

    n->value = value;
    n->prev = NULL;
    n->next = NULL;

    return n;
}

Node_t* findPosition (int x, List_t* l) {
    if (l == NULL) return NULL;

    Node_t* aux = l->first;
    while (aux != NULL && x > aux->value) aux = aux->next;
    return aux;
}

int size (List_t* l) {
    if (l == NULL) return -1;

    return l->size;
}

int insert (int x, List_t* l) {
    if (l == NULL) return -1;

    Node_t* n = createNode(x);
    if (n == NULL) return -1;

    Node_t* aux = findPosition(x, l);
    if (aux == NULL) {
        if (size(l) == 0) {
            l->first = n;

        } else {
            l->last->next = n;
            n->prev = l->last;

        }
        l->last = n;
        l->size++;

        return 1;

    } else if (x != aux->value){
        if (aux == l->first) {
            l->first->prev = n;
            n->next = l->first;
            l->first = n;

        } else {
            aux->prev->next = n;
            n->prev = aux->prev;
            n->next = aux;
            aux->prev = n;

        }
        l->size++;

        return 1;

    }

    return 0;
}

int delete (int x, List_t* l) {
    if (l == NULL) return -1;

    Node_t* n = findPosition(x, l);
    if (n == NULL || n->value != x) {
        return 0;

    } else {
        if (n->prev == NULL && n->next == NULL) {
            l->first = NULL;
            l->last = NULL;
            free(n);

        } else {
            if (n == l->first) {
                l->first = n->next;
                l->first->prev = NULL;

            } else if (n == l->last) {
                l->last = n->prev;
                l->last->next = NULL;

            } else {
                n->prev->next = n->next;
                n->next->prev = n->prev;

            }
            free(n);

        }
        l->size--;

        return 1;
    }
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
