#include <bits/stdc++.h>
#define int long long
using namespace std;
int rst=0;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;
    }
}
bool in_area(vector< pair<int,int> >check,pair<int,int> *arr,int n){

    if(check[0].first>=arr[n].first){
        if(check[0].second>=arr[n].second){
            rst=0;
            return 1;
        }
    }
    for(int i=0;i<n-1;i++){
        if(check[i].first<=arr[n].first){
            if(check[i].second<=arr[n].second){
                if(check[i+1].first>=arr[n].first){
                    if(check[i+1].second>=arr[n].second){
                        rst=i+1;
                        return 1;
                    }
                }
            }
        }
    }
    if(check[n-1].first<=arr[n].first){
        if(check[n-1].second<=arr[n].second){
            rst=n;
            return 1;
        }
    }
    return 0;
}
void solve()
{   
    int n,m;
    cin >> n >> m;
    if(n==1&&m==1){
        int tp;
        cin >> tp;
        cout << 1 << endl;
        return;
    }
    pair<int,int>arr[n*m+10];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin >> temp;
            arr[temp].first=i;
            arr[temp].second=j;
        }
    }
    vector< pair<int,int> >check(n*m+10);
    check[0]=arr[0];
    int step=1;
    while(in_area(check,arr,step)&&step<n*m){
        check.insert(check.begin()+rst,arr[step]);
        step++;
        
        
    }
    cout << step << endl;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}