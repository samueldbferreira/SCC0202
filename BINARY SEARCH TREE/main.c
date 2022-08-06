#include <stdio.h>
#include "bst.h"

int main () {
    Tree_t* t = createTree();

    printf("empty? %d\n\n", isEmpty(t));

    insert(8, t);
    insert(3, t);
    insert(13, t);
    insert(1, t);
    insert(7, t);
    insert(10, t);
    insert(14, t);
    insert(4, t);
    insert(12, t);
    insert(5, t);

    printTree(t);
    printf("13 in tree? -> %d\n\n", inTree(13, t));

    printf("empty? %d\n\n", isEmpty(t));

    int temp;
    minValue(&temp, t);
    printf("min: %d\n", temp);
    maxValue(&temp, t);
    printf("max: %d\n\n", temp);

    delete(13, t);
    printTree(t);

    printf("13 in tree? -> %d\n\n", inTree(13, t));

    destroyTree(t);

    return 0;
}
