#include <bits/stdc++.h>
using namespace std;
int k,n,S;
int main(){
    n=1;
    S=0;
    cin>>k;
    while(1){
        for(;;n++){
            S+=(1/n);
            if(S>k){
                cout<< n;
                return 0;
            }
        }
    }
}