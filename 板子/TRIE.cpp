#include "bits/stdc++.h"
using namespace std;


template<class T> using v = vector<T>;
#define rep(i, a, b) for(int i = (a); i < (b); i ++)
#define rrep(i, a, b) for(int i = b; i --> a; )
#define sz(x) (int)size(x)

struct TRIE {
	v<v<int>> nxt;
	int cnt;
	v<bool> vis; //是否存在以_i结尾的字符串
	TRIE(int N) {
		nxt.reserve(N);
		rep(i, 0, N) nxt[i].reserve(26);
		vis.reserve(N);
		cnt = 0;
	}
	TRIE() {
		int N = 1e6;
		nxt.reserve(N);
		rep(i, 0, N) nxt[i].reserve(26);
		vis.reserve(N);
		cnt = 0;
	}

	void insert(string s) {
		int l = sz(s);
		int p = 0;
		rep(i, 0, l) {
			int ch = s[i] - 'a';
			if(!nxt[p][ch]) nxt[p][ch] = ++ cnt;
			p = nxt[p][ch]; 
		}
		vis[p] = true;
	}

	bool find(string s) {
		int l = sz(s);
		int p = 0;
		rep(i, 0, l) {
			int ch = s[i] - 'a';
			if(!nxt[p][ch]) return false;
			p = nxt[p][ch];
		}
		return vis[p];
	}

};

struct TRIE_01 {
	v<v<int>> nxt;
	int cnt;
	v<int> vis; //经过节点_i的数字数
	TRIE_01(int N) {
		nxt.reserve(N);
		rep(i, 0, N) nxt[i].reserve(2);
		vis.reserve(N);
		cnt = 0;
	}
	TRIE_01() {
		int N = 1e6;
		nxt.reserve(N);
		rep(i, 0, N) nxt[i].reserve(2);
		vis.reserve(N);
		cnt = 0;
	}

	void insert(int x) {
		int p = 0;
		vis[p] ++;
		rrep(i, 0, 32) {
			int ch = (x >> i) & 1;
			if(!nxt[p][ch]) nxt[p][ch] = ++ cnt;
			p = nxt[p][ch]; 
			vis[p] ++;
		}
	}

	void erase(int x) {
		int p = 0;
		vis[p] --;
		rrep(i, 0, 32) {
			int ch = (x >> i) & 1;
			p = nxt[p][ch];
			vis[p] --;
		}
	}

};

signed main() {

}