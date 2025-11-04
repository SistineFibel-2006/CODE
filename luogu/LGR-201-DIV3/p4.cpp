#include<bits/stdc++.h>
using namespace std;
int n;
int a,b;
int ans=0;
int main(){
    cin >>n ;
    for(int i=0;i<n/2;i++){
        cin >> a >> b;
        if(a==b) ans+=1;
    }
    cout << ans*2;
}