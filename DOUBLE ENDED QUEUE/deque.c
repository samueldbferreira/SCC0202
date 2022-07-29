#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

struct node {
    int value;
    struct node* prev;
    struct node* next;
};

struct deque {
    Node_t* first;
    Node_t* last;
    int size;
};

Deque_t* createDeque () {
    Deque_t* d = (Deque_t*) malloc(sizeof (Deque_t));
    if (d == NULL) return NULL;

    d->first = NULL;
    d->last = NULL;
    d->size = 0;

    return d;
}

int size (Deque_t* d) {
    if (d == NULL) return -1;

    return d->size;
}

Node_t* createNode (int value) {
    Node_t* n = (Node_t*) malloc(sizeof (Node_t));
    if (n == NULL) return NULL;

    n->value = value;
    n->prev = NULL;
    n->next = NULL;

    return n;
}

int insertStart (int x, Deque_t* d) {
    if (d == NULL) return -1;

    Node_t* n = createNode(x);
    if (n == NULL) return -1;

    if (size(d) == 0) {
        d->last = n;

    } else {
        n->next = d->first;
        d->first->prev = n;

    }
    d->first = n;
    d->size++;

    return 1;
}

int insertEnd (int x, Deque_t* d) {
    if (d == NULL) return -1;

    Node_t* n = createNode(x);
    if (n == NULL) return -1;

    if (size(d) == 0) {
        d->first = n;

    } else {
        n->prev = d->last;
        d->last->next = n;

    }
    d->last = n;
    d->size++;

    return 1;
}

int deleteStart (int* x, Deque_t* d) {
    if (d == NULL) -1;

    if (size(d) == 0) {
        return 0;

    } else {
        *x = d->first->value;

        Node_t* aux = d->first;
        if (size(d) == 1) {
            d->first = NULL;
            d->last = NULL;

        } else {
            d->first = aux->next;
            d->first->prev = NULL;

        }
        free(aux);
        d->size--;
        return 1;

    }
}

int deleteEnd (int* x, Deque_t* d) {
    if (d == NULL) -1;

    if (size(d) == 0) {
        return 0;

    } else {
        *x = d->last->value;

        Node_t* aux = d->last;
        if (size(d) == 1) {
            d->first = NULL;
            d->last = NULL;

        } else {
            d->last = aux->prev;
            d->last->next = NULL;

        }
        free(aux);
        d->size--;
        return 1;

    }
}

int first (int* x, Deque_t* d) {
    if (d == NULL) return -1;

    if (size(d) == 0) {
        return 0;

    } else {
        *x = d->first->value;
        return 1;

    }
}

int last (int* x, Deque_t* d) {
    if (d == NULL) return -1;

    if (size(d) == 0) {
        return 0;

    } else {
        *x = d->last->value;
        return 1;

    }
}

void printDeque (Deque_t* d) {
    if (d == NULL) return;

    Node_t* aux = d->first;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void destroyDeque (Deque_t* d) {
    if (d == NULL) return;

    Node_t* aux = d->first;
    while (aux != NULL) {
        d->first = aux->next;
        free(aux);
        aux = d->first;
    }
    free(d);
}
