#include <stdlib.h>
#include "queue.h"

struct node {
    int value;
    struct node* next;
};

struct queue {
    Node_t* first;
    Node_t* last;
};

Queue_t* createQueue () {
    Queue_t* q = (Queue_t*) malloc(sizeof (Queue_t));
    if (q == NULL) return NULL;

    q->first = NULL;
    q->last = NULL;

    return q;
}

int isEmpty (Queue_t* q) {
    if (q == NULL) return -1;

    return q->first == NULL;
}

Node_t* createNode (int value) {
    Node_t* n = (Node_t*) malloc(sizeof (Node_t));
    if (n == NULL) return NULL;

    n->value = value;
    n->next = NULL;

    return n;
}

int enqueue (int x, Queue_t* q) {
    if (q == NULL) return -1;

    Node_t* n = createNode(x);
    if (n == NULL) return -1;

    if (isEmpty(q)) q->first = n;
    else q->last->next = n;
    q->last = n;

    return 1;
}

int dequeue (int* x, Queue_t* q) {
    if (q == NULL) return -1;

    if (isEmpty(q)) {
        return 0;

    } else {
        *x = q->first->value;
        Node_t* aux = q->first;
        q->first = aux->next;
        free(aux);
        return 1;

    }
}

void destroyQueue (Queue_t* q) {
    Node_t* aux;
    while (q->first != NULL) {
        aux = q->first;
        q->first = aux->next;
        free(aux);
    }
    free(q);
}
