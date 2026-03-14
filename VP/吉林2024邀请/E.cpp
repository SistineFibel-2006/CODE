#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define fi first
#define se second

struct P {
    int x, y;
};

signed main() {
    int n, k; cin >> n;
    vector<P> p(n);
    for(int i = 0; i < n; i ++) { 
	cin >> p[i].x >> p[i].y;
	p[i].x = p[i].x - i;
	p[i].y = i - p[i].y; 
    }
    sort(p.begin(), p.end(), [&](const P& a, const P& b){
	return (a.x ^ b.x) ? a.x < b.x : a.y < b.y; 
    });
    vector<int> st;
    for(int i = 0; i < n; i ++) {
	int pre = i;
	while(!st.empty() && p[st.back()].y <= p[i].y) {
	    if(pre == i) pre = st.back();
	    st.pop_back();
	}
	cerr << "pre (" << i << ") :" << pre << "\n";
	st.push_back(pre);
    }
    cout << st.size();
}
