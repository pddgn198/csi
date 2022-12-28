#include <stdlib.h>

typedef struct node {
    int idx;
    struct node *next;
} Node;

void AddFront(Node **head, Node **back, int num) {
    Node *oldHead = (*head)->next;
    (*head)->next = malloc(sizeof(Node));
    (*head)->next->idx = num;
    (*head)->next->next = oldHead;
}
void AddBack(Node **head, Node **back, int num) {
    Node *n = malloc(sizeof(Node));
    n->idx = num;
    n->next = NULL;
    (*back)->next = n;
    *back = n;
}
void DeleteFront(Node **head, Node **back) {
    if ((*head)->next == NULL) return;
    Node *del = (*head)->next;
    (*head)->next = del->next;
    free(del);
}
void Delete(Node **head, Node **back, int num) {
    Node *n = *head;
    while (n->next != NULL) {
        if (n->next->idx == num) {
            if (n->next == *back) {
                *back = n;
            }
            Node *del = n->next;
            n->next = del->next;
            free(del);
        } else {
            n = n->next;
        }
    }
}
void Swap(Node **head, Node **back) {
    if ((*head)->next == NULL) return;
    Node *pre = *head, *n = (*head)->next, *nxt = n->next;
    while (n != NULL) {
        nxt = n->next;
        n->next = pre;
        pre = n;
        n = nxt;
    }
    *back = (*head)->next;
    (*back)->next = NULL;
    (*head)->next = pre;
}