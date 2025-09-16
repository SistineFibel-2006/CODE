#include <bits/stdc++.h>

int gcd(int a, int b);
int lcm(int a, int b);

signed main () {
    int n, m, o;
    int (*fun)(int, int);
    std::cin >> n >> m >> o;
    if(o == 1)
        fun = gcd;
    else
        fun = lcm;
    int ans = fun(n, m);
    std::cout << ans;
}

int gcd (int a, int b){
    while(b != 0){
        auto tt = b;
        b = a % b;
        a = tt;
    }
    return a;
}

int lcm (int a, int b){
    return a * b / gcd(a, b);
}