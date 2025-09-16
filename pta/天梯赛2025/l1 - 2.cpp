#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    vector<int> a (12, 0);
    for(int i = 0; i < 12; i ++)
    	a[i] = i;
    if(find(a.begin(), a.end(), 12) == a.end())
    	cout << "NO\n";
    int x = *find(a.begin(), a.end(), 12);
    cout << x << ' ' << a[x];

    return 0;
}
