#include <stdio.h>

void sort(int *a, int n) {
    if(n < 2) return;
    int p = a[n / 2], i = 0, j = n - 1, t;
    while(i <= j) {
	while(a[i] < p) i ++;
	while(a[j] > p) j --;
	if(i <= j) {t = a[i]; a[i ++] = a[j]; a[j --] = t;}
    }
    sort(a, j + 1); sort(a + i, n - i);
}

int main(void) {
    int a[] = {6, 5, 4, 3, 2, 1};
    sort(a + 1, sizeof a / sizeof (int) - 1);
    for(int i = 0; i < (sizeof a / sizeof (int)); i ++) printf("%d ", a[i]);
    return 0;
}
