#include <bits/stdc++.h>
#define MAXN 1000000000
using namespace std;
int n,q=0;
long long int a[MAXN];
long long int b[MAXN];
long long int k;
int main(){
    cin >> n >> k;
    for(int i=0;i<n;++i) cin>> a[i];
    sort(&a[0],&a[n]);
    if (a[n]-a[0]<k) cout<<"No";
    if (a[n]-a[0]>=k){
        b[0] = a[0];
        q++;
        for (int i=1;i<n;++i) {
            if (a[i]!= a[i-1]) {
                b[q] = a [i];
                q++;
            }
        }
        for (int i=1;i<n;++i) {

        }
    }
}