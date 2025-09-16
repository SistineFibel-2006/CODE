#include <bits/stdc++.h>
#define int long long
using namespace std;


const int INF = 0x3f3f3f3f;

struct grass{
    int l;
    int r;
    int hour=INF;
    int fen=INF;
    int k;
};

grass arr[1000010]={0};

void solve(){
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            arr[i].k=0;
            arr[i].hour=INF;
            arr[i].fen=INF;
        }
        for(int i=0;i<n;i++){
            cin >> arr[i].k;
            arr[i].r=(n-1-i)*2;
            arr[i].l=2*i+1;
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(arr[j].hour+arr[j].l>arr[j].k){
                    arr[j].hour=0;
                    arr[j].fen=0;
                    cnt++;
                }
                else{
                    arr[j].hour+=arr[j].l;
                }

                if(arr[j].hour+arr[j].r>arr[j].k){
                    arr[j].hour=0;
                    arr[j].fen=0;
                    cnt++;
                }
                else{
                    arr[j].hour+=arr[j].r;
                }
            }
            cout << cnt << ' ';
        }
        cout << endl;
}

signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    std::cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
