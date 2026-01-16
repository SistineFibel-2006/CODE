#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#define Int long long

Int k;
Int cnt = 0;

bool check(Int x) {
    if(x * x + 3 * x + 1 >= k) return 1;
    else return 0;
}

int main() {
    scanf("%lld", &k);
    Int low = 0, high = 2e9;
    Int ans = 0;
    while(low <= high) {
	long long mid = low + (high - low) / 2;

	if(check(mid)) ans = mid, high = mid - 1;
	else low = mid + 1;
	cnt ++;
	assert(cnt <= 1e4);
    }
    //printf("%lld %lld \n", low, high);
    //printf("%lld \n", ans);
    if(ans % 3 == 2) puts("Dust");
    else if(ans % 3 == 1) puts("XUU");
    else puts("Lua");
}
