#include <bits/stdc++.h>
using namespace std;
int a;
int k;
int n[10001];
int main(){
    cin >> a;
    for(int i=0;i<a;++i) cin >>n[i];
    for(int i=0;i<a;++i){
        for(int j=0;j<i;++j){
            if(n[j]>n[i]) ++k;
        }
    }
    cout << k;
    return 0;
}
