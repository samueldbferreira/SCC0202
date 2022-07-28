#include <stdio.h>
#include "list.h"

int main () {
    List_t* l = createList();

    insert(5, l);
    insert(2, l);
    insert(3, l);
    insert(7, l);
    insert(8, l);
    printList(l);

    delete(5, l);
    delete(2, l);
    delete(3, l);
    delete(7, l);
    delete(8, l);
    delete(821, l);
    printList(l);

    insert(90, l);
    insert(90, l);
    insert(910, l);
    printList(l);

    printf("\n%d\n", inList(5, l));
    printf("\n%d\n", inList(90, l));

    destroyList(l);

    return 0;
}