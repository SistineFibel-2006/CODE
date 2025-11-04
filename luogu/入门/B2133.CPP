#include <bits/stdc++.h>
using namespace std;
int n,i,j;
int a,b;
int main(){
    cin >> n;
    for(i=1;;i++){
        for(j=1;j<=i;j++){
            if(i*(i+1)/2-3*j==n){
                cout << j << " " << i << endl;
                return 0;
            }
        }
    }
}