#include <stdio.h>
#include "deque.h"

int main () {
    Deque_t* d = createDeque();

    for (int i = 0; i < 15; i++) {
        insertEnd(i + 1, d);
    }
    printDeque(d);

    for (int i = 0; i > -16; i--) {
        insertStart(i, d);
    }
    printDeque(d);

    int aux;

    for (int i = 0; i < 4; i++) {
        deleteEnd(&aux, d);
        printf("deletei o %d\n", aux);
    }
    printDeque(d);

    for (int i = 0; i < 4; i++) {
        deleteStart(&aux, d);
        printf("deletei o %d\n", aux);
    }
    printDeque(d);

    last(&aux, d);
    printf("ultimo: %d\n", aux);

    first(&aux, d);
    printf("primeiro: %d\n", aux);

    while (size(d) > 0) {
        deleteStart(&aux, d);
        printf("%d\n", aux);
    }

    for (int i = 0; i < 15; i++) {
        insertEnd(i + 1, d);
    }
    printDeque(d);

    destroyDeque(d);

    return 0;
}
