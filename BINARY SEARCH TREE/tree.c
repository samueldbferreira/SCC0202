#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct tree {
    Node_t* root;
};

Tree_t* createTree () {
    Tree_t* t = (Tree_t*) malloc(sizeof (Tree_t));
    if (t == NULL) return NULL;

    t->root = NULL;

    return t;
}

int isEmpty (Tree_t* t) {
    if (t == NULL) return -1;

    return t->root == NULL;
}

Node_t* createNode (int value) {
    Node_t* n = (Node_t*) malloc(sizeof (Node_t));
    if (n == NULL) return NULL;

    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int insertUtil (Node_t* n, Node_t* root) {
    if (n == NULL || root == NULL) return -1;

    if (n->value == root->value) {
        return 0;

    } else if (n->value < root->value) {
        if (root->left == NULL) root->left = n;
        else insertUtil(n, root->left);

    } else {
        if (root->right == NULL) root->right = n;
        else insertUtil(n, root->right);

    }

    return 1;
}

int insert (int x, Tree_t* t) {
    if (t == NULL) return -1;

    Node_t* n = createNode(x);
    if (n == NULL) return -1;

    if (isEmpty(t)) {
        t->root = n;
        return 1;

    } else {
        return insertUtil(n, t->root);

    }
}

Node_t* searchNode (int x, Node_t* root) {
    if (root == NULL) return NULL;

    if (root->value == x) return root;
    else if (x < root->value) return searchNode(x, root->left);
    else return searchNode(x, root->right);
}

int inTree (int x, Tree_t* t) {
    if (t == NULL) return -1;

    Node_t* n = searchNode(x, t->root);

    return n != NULL;
}

Node_t* maxValueUtil (Node_t* root) {
    if (root == NULL) return NULL;

    Node_t* max = root;
    while (1) {
        if (max->right == NULL) break;
        max = max->right;
    }
    return max;
}

int maxValue (int *x, Tree_t* t) {
    if (t == NULL) return -1;

    Node_t* max = maxValueUtil(t->root);
    if (max == NULL) {
        return 0;

    } else {
        *x = max->value;
        return 1;

    }
}

Node_t* minValueUtil (Node_t* root) {
    if (root == NULL) return NULL;

    Node_t* min = root;
    while (1) {
        if (min->left == NULL) break;
        min = min->left;
    }
    return min;
}

int minValue (int *x, Tree_t* t) {
    if (t == NULL) return -1;

    Node_t* min = minValueUtil(t->root);
    if (min == NULL) {
        return 0;

    } else {
        *x = min->value;
        return 1;

    }
}

int deleteUtil (int x, Node_t** root) {
    if (*root == NULL) return 0;

    if (x < (*root)->value) {
        return deleteUtil(x, &(*root)->left);

    } else if (x > (*root)->value) {
        return deleteUtil(x, &(*root)->right);

    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return 1;

        } else if ((*root)->left == NULL) {
            Node_t* temp = *root;
            *root = temp->right;
            free(temp);
            return 1;

        } else if ((*root)->right == NULL) {
            Node_t* temp = *root;
            *root = temp->left;
            free(temp);
            return 1;

        } else {
            (*root)->value = maxValueUtil((*root)->left)->value;
            return deleteUtil((*root)->value, &(*root)->left);

        }
    }
}

int delete (int x, Tree_t* t) {
    if (t == NULL) return -1;

    return deleteUtil(x, &t->root);
}

void printUtil (Node_t* root) {
    if (root == NULL) return;

    printf("%d -> ", root->value);
    if (root->left != NULL) printf("%d, ", root->left->value);
    else printf("NULL, ");
    if (root->right != NULL) printf("%d", root->right->value);
    else printf("NULL");
    printf("\n");

    printUtil(root->left);
    printUtil(root->right);
}

void printTree (Tree_t* t) {
    if (t == NULL) return;

    printUtil(t->root);
    printf("\n");
}

void destroyUtil (Node_t* root) {
    if (root == NULL) return;

    destroyUtil(root->left);
    destroyUtil(root->right);
    free(root);
}

void destroyTree (Tree_t* t) {
    if (t == NULL) return;

    destroyUtil(t->root);
    free(t);
}
