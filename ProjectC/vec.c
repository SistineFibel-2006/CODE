#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct {
    int *item;
    size_t size;
    size_t cap;
} vi;

#define push_back(xs, s)\
    do {\
        if(xs.size >= xs.cap) { \
	    if(xs.cap == 0) xs.cap = 128;\
	    else xs.cap *= 2;\
	    xs.item = realloc(xs.item, sizeof(*xs.item) * xs.cap);\
	}\
	xs.item[xs.size ++] = s;\
    }while(0)


int main(void) {
    vi A = {0};
    for(int i = 0; i < 10; i ++) push_back(A, i);
    for(int i = 0; i < 10; i ++) printf("%d ", A.item[i]);
    return 0;
}
