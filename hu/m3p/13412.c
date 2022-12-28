#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int val;
    struct _Node *next;
} Node;

Node *_process(Node **processor, Node *next, int k) {
    // printf("Processing");
    // for (int i = 0; i < k; i++) {
    //     printf(" %d", processor[i]->val);
    // }
    // printf(" -> %d\n", next->val);
    for (int i = 1; i < k; i++) {
        processor[i]->next = processor[i - 1];
    }
    processor[0]->next = next;
    return processor[k - 1];
}

Node *Solver(Node *head, int k) {
    if (k == 1) return head;
    Node **processor = malloc(sizeof(Node *) * k);
    int count = 0, found = 0;
    Node *n = head, *pre = NULL;
    while (n != NULL) {
        processor[count++] = n;
        n = n->next;
        if (count == k) {
            Node *r = _process(processor, n, k);
            if (!found)
                head = r;
            else
                pre->next = r;
            pre = processor[0];
            count = 0, found = 1;
        }
    }
    free(processor);
    return head;
}