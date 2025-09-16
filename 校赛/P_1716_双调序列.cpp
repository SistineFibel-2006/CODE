#include <bits/stdc++.h>
#define max(x,y) x>y?x:y
using namespace std;

bool cmp(int a, int b){
    return max(a,b);
}
int main (void){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(&a[0],&a[n],cmp);
    int l = 0, r = n;
    for(int i=1;i<=n/2;i++){
        cout << a[n - i + 1] << endl << a[i] << endl;
    }
    if(n%2)
        cout << a[n / 2 + 1] << endl;
    return 0;
}