#include <bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

// 1 2 3 4 5 6 (后缀数组)
// 1 3 2 3 5 6
// 1 4 6 9 14 20
// a[n]- a[n-1]=  + b[n]; (求前缀和)
// b[l]~b[r];
// ans = a[r]-a[l-1];
//(差分是前缀和的逆运算，反数组)
//差分的第i位，记录了后缀数组里i位和i-1的变化 Δx
//l ~ r ; + a;
//
