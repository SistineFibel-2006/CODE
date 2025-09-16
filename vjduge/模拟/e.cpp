#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	string s;
	cin >> s;
	vector<char> arr;
	char x,y,z;
	int lag =0;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == '-' && s[i + 1] - s[i] == 1)
			lag = 0;
		else if(s[i] != '-')
			cout << s[i];
		else if(s[i] == '-' && s[i - 1] - s[i + 1] >= 0)
			cout << s[i];
		else {
			x = s[i - 1]; y = s[i + 1];
			int sum = (y - x - 1) * b;
			if(a == 3)
				for(int i = 0; i < sum; i ++)
					arr.push_back('*');
			else if(c == 1){
				int cnt = 0; 
				z = x + 1;
				if(a == 2)
					z -= 32;
				for(int i = 0; i < sum; i ++){
					arr.push_back(z);
					cnt ++;
					if(cnt == b){
						z++;
						cnt = 0;
					}
				}
				for(auto c : arr){
					cout << c;
				}
				arr.clear();
			}
			else{
				int cnt = 0;
				z = y - 1;
				if(a == 2)
					z -= 32;
				for(int i = 0; i < sum; i ++){
					arr.push_back(z);
					cnt ++;
					if(cnt == b){
						z--;
						cnt = 0;
					}
				}
				for(auto c : arr){
					cout << c;
				}
				arr.clear();
			}
		}
	}
}





void solve(){

}