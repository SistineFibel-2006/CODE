#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
	int T, S, t;
	cin >> T >> S >> t;
	if(S == 1) {
		if(T >= 35 && t >= 33){
			cout << "Bu Tie" << endl;
			cout << T;
			return 0;
		}
		else{
			cout << "Bu Re" << endl;
			cout << t;
			return 0;
		}
	}
	else {
		if(T >= 35 && t >= 33){
			cout << "Shi Nei" << endl;
			cout << T;
			return 0;
		}
		else {
			cout << "Shu Shi" << endl;
			cout << t;
			return 0;
		}
	}

    return 0;
}
