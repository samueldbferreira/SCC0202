#include <stdio.h>
#include "tree.h"

int main () {
    Tree_t* t = createTree();

    insert(5, t);
    insert(3, t);
    insert(7, t);
    insert(9, t);
    insert(8, t);
    insert(2, t);
    printTree(t);

    printf("5 -> %d\n\n",inTree(5, t));

    int temp;
    maxValue(&temp, t);
    printf("max: %d\n", temp);
    minValue(&temp, t);
    printf("min: %d\n\n", temp);;

    delete(5, t);
    printTree(t);

    printf("5 -> %d\n",inTree(5, t));

    destroyTree(t);

    return 0;
}
