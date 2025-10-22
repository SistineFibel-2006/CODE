#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
const ll LINF = LLONG_MAX / 4;
#define rep(i,a,b) for(ll i = a; i < b; i ++)
#define all(a) a.begin(),a.end()
#define sz(a) ssize(a)
bool chmax(auto&a, auto b) {return a < b ? a = b, 1 : 0;}
bool chmin(auto&a, auto b) {return a > b ? a = b, 1 : 0;}
#define fi first 
#define se second 
#define eb emplace_back
#define pb push_back
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.fi!=b.fi){
		return a.fi > b.fi;
	}
	else{
		return a.se < b.se;
	}
}
void solve() {
  int n,m,q;
  cin >> n >> m >> q;
  int score[m+10]{0};
	unordered_map<int,int>status;
  int step=m;
  bool level[n+10]{0};
	int l_now=0;
  for(int i=0;i<q;i++){
    int temp=0;
    cin >> temp;
    int id,l;
    if(temp == 1){
			cin >> l;
      if(!level[l]){
				step=m;
				level[l]=1;
				l_now=l;
				status.clear();
			}
			continue;
    }
		cin >> id >> l;
		if(l_now==0||status[id]!=0){
			continue;
		}
    else if(temp == 2){
			if(l==l_now){
				score[id]+=step;
				step--;
				status[id]=2;
			}
    }
    else{
			if(l==l_now){
				status[id]=3;
			}
    }
  }
	vector<pair<int,int>>vec;
	for(int i=1;i<=m;i++){
		vec.push_back({score[i],i});
	}
	sort(vec.begin(),vec.end(),cmp);
	for(auto [a,b]:vec){
		cout << b << ' ' << a << endl;
	}
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
  int t = 1; 
  cin >> t;
  while(t --)  {
    solve();
  }
}