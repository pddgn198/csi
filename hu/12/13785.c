#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node *left, *right;
} Node;

void Insert(Node **root, int src) {
    if (*root == NULL) {
        *root = malloc(sizeof(Node));
        (*root)->val = src;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    if (src < (*root)->val) Insert(&(*root)->left, src);
    if (src > (*root)->val) Insert(&(*root)->right, src);
}
void _print(Node *root) {
    if (root->left != NULL) {
        printf(" %d", root->left->val);
        _print(root->left);
    }
    if (root->right != NULL) {
        printf(" %d", root->right->val);
        _print(root->right);
    }
}
void Print(Node *root) {
    printf("%d", root->val);
    _print(root);
    puts("");
}
