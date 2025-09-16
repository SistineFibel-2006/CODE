#include <bits/stdc++.h>
#include <stack>
const int MAXN = 1e6;

struct stack{
	struct item {
	int l, r, v, w;
	};
	item st[MAXN] = {};
	int point = 0;

	void push(item x) {
		st[point ++] = x;
	}

	item top(){
		return st[point - 1];
	}

	void pop(){
		point --;
	}

	void clear() {
		point = 0;
	}

	bool empty() {
		return point == 0 ? true : false; //三目运算符
	}
	//clear, empty
};

//树 => 图

// 链式前项星



int main() {
	// std::stack<int> S;
	// S.push();
	// S.pop();
	// S.top();
	// S.size();
}