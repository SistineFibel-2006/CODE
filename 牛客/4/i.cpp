#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();




}

void solve(){
	int cnt = 0;
	int n;
	cin >> n;
	string s;
	cin >> s;
	const string tt = "uwawauwa";
	vector<int> po;
	int pos = s.find(tt);
    while (pos != std::string::npos) {
        po.push_back(pos - 1); 
        pos = s.find(tt, pos + 1);
    }
    vector<int> pou;
    for(int i = 0; i < n; i ++)
    	if(s[i] == 'u')
    		pou.push_back(i);

    for(auto a : po){
    	if(a == 0)
    		continue;
    	cnt += lower_bound(pou.begin() ,pou.end() ,a) - pou.begin();
    	// cerr << lower_bound(pou.begin() ,pou.end() ,a) - pou.begin() << ' ';
    }
    // cout << endl;
    cout << cnt << endl;

    // cerr << "pos : ";
    // for(auto a : po)
    // 	cerr << a << ' ';
    // cerr << endl;

    // cerr << "pou : ";
    // for(auto a : pou)
    // 	cerr << a << ' ';
    // cerr << endl;
}