#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node {
    int value;
    struct node* parent;
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
    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int insertUtil (Node_t* n, Node_t* root) {
    if (root == NULL) return -1;

    if (n->value == root->value) {
        free(n);
        return 0;

    } else if (n->value < root->value) {
        if (root->left == NULL) {
            n->parent = root;
            root->left = n;

        } else {
            return insertUtil(n, root->left);

        }

    } else if (n->value > root->value) {
        if (root->right == NULL) {
            n->parent = root;
            root->right = n;

        } else {
            return insertUtil(n, root->right);

        }

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

Node_t* maxValueUtil (Node_t* root) {
    if (root == NULL) return NULL;

    Node_t* max = root;
    while (max->right != NULL) max = max->right;
    return max;
}

int maxValue (int* x, Tree_t* t) {
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
    while (min->left != NULL) min = min->left;
    return min;
}

int minValue (int* x, Tree_t* t) {
    if (t == NULL) return -1;

    Node_t* min = minValueUtil(t->root);
    if (min == NULL) {
        return 0;

    } else {
        *x = min->value;
        return 1;

    }
}

Node_t* searchNode (int x, Node_t* root) {
    if (root == NULL) return NULL;

    if (x < root->value) return searchNode(x, root->left);
    else if (x > root->value) return searchNode(x, root->right);
    else return root;
}

int inTree (int x, Tree_t* t) {
    if (t == NULL) return -1;

    Node_t* n = searchNode(x, t->root);
    return n != NULL;
}

int deleteUtil (Node_t* n, Node_t* root) {
    if (n == NULL || root == NULL) return -1;

    if (n->left == NULL && n->right == NULL) {
        if (n->parent == NULL) {
            root = NULL;

        } else {
            if (n->value > n->parent->value) n->parent->right = NULL;
            else n->parent->left = NULL;

        }
        free(n);

        return 1;

    } else if (n->left == NULL) {
        if (n->parent == NULL) {
            root = n->right;

        } else {
            if (n->value > n->parent->value) n->parent->right = n->right;
            else n->parent->left = n->right;

        }
        free(n);

        return 1;

    } else if (n->right == NULL) {
        if (n->parent == NULL) {
            root = n->left;

        } else {
            if (n->value > n->parent->value) n->parent->right = n->left;
            else n->parent->left = n->left;

        }
        free(n);

        return 1;

    } else {
        Node_t* temp = maxValueUtil(n->left);
        n->value = temp->value;

        return deleteUtil(temp, root);

    }
}

int delete (int x, Tree_t* t) {
    if (t == NULL) return -1;

    Node_t* n = searchNode(x, t->root);
    if (n == NULL) return 0;
    else return deleteUtil(n, t->root);
}

void printTreeUtil (Node_t* root) {
    if (root == NULL) return;

    printf("%d -> ", root->value);
    if (root->left == NULL) printf("NULL, ");
    else printf("%d, ", root->left->value);
    if (root->right == NULL) printf("NULL\n");
    else printf("%d\n", root->right->value);

    printTreeUtil(root->left);
    printTreeUtil(root->right);
}

void printTree (Tree_t* t) {
    if (t == NULL) return;

    printTreeUtil(t->root);
    printf("\n");
}

void destroyTreeUtil (Node_t* root) {
    if (root == NULL) return;

    destroyTreeUtil(root->left);
    destroyTreeUtil(root->right);
    free(root);
}

void destroyTree (Tree_t* t) {
    if (t == NULL) return;

    destroyTreeUtil(t->root);
    free(t);
}
