#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int *x;
    size_t size;
    size_t cap;
}vector;

void V_init(vector *a, int len) {
    a->x = NULL;
    a->cap = len;
    a->size = len;
    a->x = realloc(a->x, sizeof(*(a->x)) * a->cap);
    for(int i = 0; i < len; i ++) a->x[i] = 0;
}

void V_push_back(vector *a, int x) {
    if(a->size >= a->cap) {
	if(a->cap == 0) a->cap = 128;
	else a->cap *= 2;
	a->x = realloc(a->x, sizeof(*(a->x)) * a->cap);
    }
    a->x[a->size ++] = x;
}

int V_get(vector *a, int id) {
    assert(id < a->size);
    return a->x[id];
}

size_t V_size(vector *a) {
    return a->size;
}

void V_upd(vector *a, int id, int val) {
    assert(id < a->size);
    a->x[id] = val;
}



int main() {
    vector A;
    V_init(&A, 60);
    for(int i = 0; i < A.size; i ++) {
	printf("%d ", V_get(&A,i));
    }
}
