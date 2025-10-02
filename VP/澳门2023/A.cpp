#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define eb emplace_back
#define in insert
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
// #define rep(i, n) for(size_t i = 0; i < n; i ++)
#define rep(i, a, b) for(size_t i = a; i < b; i ++)
#define F_(i, a, b) for(size_t i = b; i > a; i --)
#define I(x) int x;cin>>x
using i64 = long long;
#define i64(x) i64 x;cin>>x
#define endl '\n'
const int N=4010;
int n;
bool mark[N+10][N+10]{};
bool arr[N+10][N+10]{};
int ra[N+10]{};
int ca[N+10]{};
void solve() {
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            
            if(s[j]=='+'){
                arr[i][j]=1;
            }
            else{
                mark[i][j]=1;
                arr[i][j]=0;
                ra[i]++;
                ca[j]++;
            }
            //1 + 0 -
        }
    }
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        ra[i]+=temp;
        pq.push({ra[i],i});
        if(ra[i]<0){
            cout << "No" << endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        ca[i]+=temp;
        if(ca[i]<0){
            cout << "No" << endl;
            return;
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<ca[i];j++){
            if(pq.empty()){
                cout << "No" << endl;
                return;
            }
            if(pq.top().first==0){
                cout << "No" << endl;
                return;
            }
            q.push({pq.top().first-1,pq.top().second});
            if(mark[pq.top().second][i]==1){
                mark[pq.top().second][i]=0;
            }
            else{
                mark[pq.top().second][i]=1;
            }
            pq.pop();
        }
        while(!q.empty()){
            pq.push(q.front());
            q.pop();
        }
    }
    cout << "Yes" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << mark[i][j];
        }
        cout << endl;
    }


    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t --) 
        solve();
}