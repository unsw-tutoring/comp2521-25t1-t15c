#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *reverseList(struct node *l) {
    if (l == NULL) return NULL;
    if (l->next == NULL) return l;

    struct node *next = l->next;

    struct node *newHead = reverseList(l->next);
    next->next = l;
    l->next = NULL;

    return newHead;
}
