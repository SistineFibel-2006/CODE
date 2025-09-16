#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const int N = 1000050;
int trie[N][26];
int cnt[N];
int id;

void insert(string s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i] - 'a';
		if (trie[p][x] == 0) trie[p][x] = ++id;
		p = trie[p][x];
	}
	cnt[p]++;
}

int  find(string s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i] - 'a';
		if (trie[p][x] == 0)return 0;
		p = trie[p][x];
	}
	return cnt[p];
}

int countNodes() {
    function<int(int)> dfs = [&](int node) {
        int count = 1; 
        for (int i = 0; i < 26; i++) {
            if (trie[node][i] != 0) { 
                count += dfs(trie[node][i]);
            }
        }
        return count;
    };
    return dfs(0); 
}

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	int maxs = 0;
	for(int i = 0; i < n; i ++){
		cin >> s;
		if(s.length() > maxs)
			maxs = s.length();
		insert(s);
	}
	
	cout << (countNodes() - 1) * 2 - maxs << endl;
}

void solve(){

}