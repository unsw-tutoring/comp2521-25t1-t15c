#include "Set.h"

struct set {
    int nelems;
    int size;
    int *elems;
};

Set SetNew(void) {
    Set s = malloc(sizeof(struct set));
    s->nelems = 0;
    s->size = 8;
    s->elems = malloc(8 * sizeof(int));
}

void SetFree(Set s) {
    free(s->elems);
    free(s);
}

void SetInsert(Set s, int elem) {
    if (s->nelems == s->size) {
        s->elems = realloc(s->elems, s->size * 2 * sizeof(int));
        s->size *= 2;
    }

    s->elems[s->nelems++] = elem;
}