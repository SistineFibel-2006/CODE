#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9;
int ans[1010];
void dg(int* arr,int L,int R){

    if(L==R){
        ans[L]=arr[0];
        return;
    }

    int sL[R-L+10];
    int step1=0;
    queue<int>toP;
    int sR[R-L+10];
    int step2=0;
    int stepl=L,stepr=L+1;
    for(int i=0;i<R-L+1;i++){
        cout << 0 << ' ';
        for(int j=L;j<(L+R)/2;j++){
            cout << arr[stepl] << ' ';
        }
        for(int j=(L+R)/2;j<=R;j++){
            cout << arr[stepr] << ' ';
        }
        cout << endl;
        int rst;
        cin >> rst;
        if(rst==0){
            sL[step1]=arr[stepr];
            step1++;
            sR[step2]=arr[stepl];
            step2++;
            while(!toP.empty()){
                sR[step2]=toP.front();
                step2++;
                toP.pop();
            }
            stepl=stepr+1;
            stepr+=2;
        }
        else if(rst==2){
            sL[step1]=arr[stepl];
            step1++;
            sR[step2]=arr[stepr];
            step2++;
            while(!toP.empty()){
                sL[step1]=toP.front();
                step1++;
                toP.pop();
            }
            stepl=stepr+1;
            stepr+=2;
        }
        else{
            toP.push(arr[stepr]);
            stepr++;
        }
    }
    if(!toP.empty()){
        cout << 0 << ' ';
        for(int j=L;j<(L+R)/2;j++){
            cout << sL[0] << ' ';
        }
        for(int j=(L+R)/2;j<=R;j++){
            cout << stepr << ' ';
        }
        cout << endl;
        int rst;
        cin >> rst;
        if(rst==2){
            sR[step2]=arr[stepr];
            step2++;
            while(!toP.empty()){
                sR[step2]=toP.front();
                step2++;
                toP.pop();
            }
            stepl=stepr+1;
            stepr+=2;
        }
        else if(rst==1){
            sL[step1]=arr[stepr];
            step1++;
            while(!toP.empty()){
                sL[step1]=toP.front();
                step1++;
                toP.pop();
            }
            stepl=stepr+1;
            stepr+=2;
        }
    }
    dg(sR,L,(L+R)/2);
    dg(sL,(L+R)/2,R);
}

signed main () {
    int n;
    cin >> n;
    int arr[n];
    for(int i=1;i<=n;i++){
        arr[i-1]=i;
    }
    dg(arr,1,n);
    cout << 1 << ' ';
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}