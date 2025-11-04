#include<bits/stdc++.h>
using namespace std;
long long int t;
long long int n,q;
long long int r[100000000];
long long int note;
long long int sum=0;
int main(){
    for (long long int i=1;i<=t;i++){
        cin >> n>>q;
        if(n%(q+1)<=0){
            for(long long int i=(n/q);i<=(n/(q+1)-1);i++){
                r[n%i]=1;
            }
        }
        else{
            for(long long int i=(n/q);i<=(n/(q+1));i++){
                r[n%i]=1;
            }
        }
        note = n/q;
        while(note <= n/(q+1)){
            if(r[note]==1) sum++;
            note ++;
        }
        cout << sum<< endl;
    }
    return 0;
}