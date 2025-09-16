#include <stdio.h>

bool isprime(int x){
    int f = 1;
    for(int i = x - 1; i > 1; i --){
        if(x % i == 0)
            f = 0;
    }
    return f;
}

signed main() {
    int x;
    scanf("%d", &x);
    if(isprime(x))
        puts("yes");
    else
        puts("no");
}