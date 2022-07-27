#include <stdio.h>
#include "stack.h"

int main () {
    Stack_t* s = createStack();

    printf("pushing: \n");
    int aux;
    for (int i = 0; i < 15; i++) {
        push(i, s);
        top(&aux, s);
        printf("%d ", aux);
    }

    printf("\n\npopping: \n");
    while (size(s) > 0) {
        pop(&aux, s);
        printf("%d ", aux);
    }
    printf("\n");

    destroyStack(s);

    return 0;
}
