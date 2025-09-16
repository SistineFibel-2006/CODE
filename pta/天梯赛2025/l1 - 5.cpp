#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
   	string s;
   	getline(cin, s);
   	int arr[26];
	int cnt[26] = {0};
   	for(int i = 0; i < 26; i ++)
   		cin >> arr[i];
   			     	
   	int ans = 0;
	for(int i = 0; i < s.length(); i ++){
		ans += arr[s[i] - 'a'];
		cnt[s[i] - 'a'] += 1;
	}
	for(int i = 0; i < 26; i ++){
		if(i == 25)
            cout << cnt[i] << endl;
		else
			cout << cnt[i] << ' ';
	}
	cout << ans;
    return 0;
}
