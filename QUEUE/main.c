#include <stdio.h>
#include "queue.h"

int main () {
    Queue_t* q = createQueue();

    printf("Enqueuing: \n");
    for (int i = 0; i < 50; i++) {
        enqueue(i + 1, q);
        printf("%d ", i + 1);
    }

    printf("\n\nDequeuing: \n");
    int aux;
    for (int i = 0; i < 25; i++) {
        dequeue(&aux, q);
        printf("%d ", aux);
    }

    printf("\n\nEnqueuing again: \n");
    for (int i = 0; i < 10; i++) {
        enqueue(i, q);
        printf("%d ", i);
    }

    printf("\n\nFinal queue: \n");
    while (!isEmpty(q)) {
        dequeue(&aux, q);
        printf("%d ", aux);
    }
    printf("\n");

    destroyQueue(q);

    return 0;
}
