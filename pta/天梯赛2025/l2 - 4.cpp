#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
	if(n == 2){
		for(int i = a; i <= b; i ++){
			if(i % 2 == 0)
				cout << i << endl;
		}
	}
	else if(n == 3){
		for(int i = a; i <= b; i ++){
			int x = i / 10;
			if(i % 3 == 0 && x % 2 == 0)
				cout << i << endl;
		}
	}
	else if(n == 4){
		for(int i = a; i <= b; i ++){
			int x = i / 100;
			int y = i / 10;
			if(i % 4 == 0 && y % 3 == 0 && x % 2 == 0)
				cout << i << endl;
		}
	}
    return 0;
}
