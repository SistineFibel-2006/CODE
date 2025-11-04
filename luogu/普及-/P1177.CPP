#include <bits/stdc++.h>
using namespace std;
long long int m;
int main(){
    cin >> m;
    long long int a[m];
    for (int i=0;i<m;i++) cin >> a[i];
    sort(&a[0],&a[m]);
    for (int i=0;i<m;i++) cout << a[i] << " ";
    return 0;
}