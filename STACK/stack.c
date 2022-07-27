#include <stdlib.h>
#include "stack.h"

struct node {
    int value;
    struct node* prev;
};

struct stack {
    Node_t* top;
    int size;
};

Stack_t* createStack () {
    Stack_t* s = (Stack_t*) malloc(sizeof (Stack_t));
    if (s == NULL) return NULL;

    s->top = NULL;
    s->size = 0;

    return s;
}

int size (Stack_t* s) {
    if (s == NULL) return -1;

    return s->size;
}

Node_t* createNode (int value) {
    Node_t* n = (Node_t*) malloc(sizeof (Node_t));
    if (n == NULL) return NULL;

    n->value = value;
    n->prev = NULL;

    return n;
}

int push (int x, Stack_t* s) {
    if (s == NULL) return -1;

    Node_t* n = createNode(x);
    if (n == NULL) return -1;

    if (size(s) > 0) n->prev = s->top;
    s->top = n;

    s->size++;

    return 1;
}

int pop (int* x, Stack_t* s) {
    if (s == NULL) return -1;

    if (size(s) == 0) {
        return 0;

    } else {
        *x = s->top->value;

        Node_t* aux = s->top;
        s->top = aux->prev;
        free(aux);

        s->size--;

        return 1;

    }
}

int top (int* x, Stack_t* s) {
    if (s == NULL) return -1;

    if (size(s) == 0) {
        return 0;

    } else {
        *x = s->top->value;
        return 1;

    }
}

void destroyStack (Stack_t* s) {
    if (s == NULL) return;

    Node_t* aux = s->top;
    while (aux != NULL) {
        s->top = aux->prev;
        free(aux);
        aux = s->top;
    }
    free(s);
}
