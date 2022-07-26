#include <stdlib.h>
#include "stack.h"

Stack_t* createStack () {
    Stack_t* s = (Stack_t*) malloc(sizeof (Stack_t));
    if (s == NULL) return NULL;

    s->size = 0;
    s->items = NULL;

    return s;
}

int push (int x, Stack_t* s) {
    if (s == NULL) return -1;

    s->items = (int*) realloc(s->items, (s->size + 1) * sizeof (int));
    s->items[s->size] = x;
    s->size++;

    return 1;
}

int isEmpty (Stack_t* s) {
    if (s == NULL) return -1;

    return s->size == 0;
}

int pop (int* x, Stack_t* s) {
    if (s == NULL) return -1;

    if (isEmpty(s)) {
        return 0;

    } else {
        *x = s->items[s->size - 1];
        s->items = (int*) realloc(s->items, (s->size - 1) * sizeof (int));
        s->size--;
        return 1;

    }
}

int top (int* x, Stack_t* s) {
    if (s == NULL) return -1;

    if (isEmpty(s)) {
        return 0;

    } else {
        *x = s->items[s->size - 1];
        return 1;

    }
}

void destroyStack (Stack_t* s) {
    if (s == NULL) return;

    if (s->items != NULL) free(s->items);
    free(s);
}
