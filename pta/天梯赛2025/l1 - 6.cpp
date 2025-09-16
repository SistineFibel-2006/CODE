#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s = "";

	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		s[i] += (char(x + 'a' - 1));
	}
	for(int a;m--;){
		cin >> a;
		if (a == 1){
			int x;cin >> x;
			string a1 = "",a2 = "";
			for(int i = 0; i < x; i ++){
				int t;cin >> t;
				a1 += (char(t + 'a' - 1));
			}
			int y;cin >> y;
			for(int i = 0; i < y; i ++){
				int t;cin >> t;
				a2 += (char(t + 'a' - 1));
			}
			int flag = 0;
			for(int i = 0; i < s.length(); i ++){
				for(int j = 0; j < a1.length(); j ++){
					if(s[i] != a1[j])
						break;
					else
						i ++;
					
					if(j == a1.length() - 1)
						flag = 1;
				}
				if(flag == 1){
					string temp = "";
					int sss = i - a1.length();
					for(int k = 0; k < i - a1.length(); k ++) 
						temp += s[k];
					for(int k = 0; k < a1.length(); k ++)
						temp += a1[k];
					for(int k = i; k < s.length(); k ++)
						temp += s[k];
					
					s = temp;
					i = a1.length() + sss - 1;
				}
			}
		}
		else if(a == 2){
			for(int i = 0; i < n - 1; i ++){
				if(int(s[i] - 'a') + int(s[i + 1] - 'a') % 2 == 0){
					int temp = "";
					for(int k = 0; k <= i; k ++)
						temp += k[i];
				}
			}
		}
	}

    return 0;
}
