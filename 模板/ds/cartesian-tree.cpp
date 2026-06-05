#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define sz(x) ssize(x)
#define int long long

namespace CarTree0 {//1-based
	struct Node {
		int v, left, right;
		Node() : v(0), left(-1), right(-1) {}
		Node(int v) : v(v), left(-1), right(-1) {}
	};
	struct Tree {
		vector<Node> tree;
		int root;
		Tree(const vector<int>& arr) {
			int n = (int)(size(arr));
			tree.resize(n);
			rep(i, 0, n) tree[i].v = arr[i];
			stack<int> st;
			rep(i, 0, n) {
				int lst = -1;
				while(!empty(st) && arr[st.top()] > arr[i]) 
					lst = st.top(), st.pop();
				if(!empty(st)) tree[i].left = lst, tree[st.top()].right = i; 
				else tree[i].left = lst, root = i;
				st.push(i);
			}
		}
	};
}

namespace CarTree1 {//1-based
	struct Node {
		int v, left, right;
		Node() : v(0), left(0), right(0) {}
		Node(int v) : v(v), left(0), right(0) {}
	};
	struct Tree {
		vector<Node> tree;
		int root;
		Tree(const vector<int>& arr) {
			int n = (int)(size(arr));
			tree.resize(n);
			rep(i, 0, n) tree[i].v = arr[i];
			stack<int> st;
			rep(i, 0, n) {
				int lst = -1;
				while(!empty(st) && arr[st.top()] > arr[i]) 
					lst = st.top(), st.pop();
				if(!empty(st)) tree[i].left = lst + 1, tree[st.top()].right = i + 1; 
				else tree[i].left = lst + 1, root = i;
				st.push(i);
			}
		}
	};
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	CarTree1::Tree tree(a);
	long long ans1 = 0, ans2 = 0;
	rep(i, 0, sz(tree.tree)) {
		ans1 ^= ((i + 1) * (tree.tree[i].left + 1));
		ans2 ^= ((i + 1) * (tree.tree[i].right + 1));
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}