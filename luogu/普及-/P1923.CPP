#include <bits/stdc++.h>
using namespace std;
long long int m,k;
int main(){
    cin >> m >> k;
    long long int a[m];
    for (int i=0;i<m;i++) cin >> a[i];
    nth_element(a,a+k,a+m);
    cout << a[k];
    return 0;
}