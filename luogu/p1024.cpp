#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
#define int double

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int a, b, c,d;
	cin >> a >> b >> c >> d;

	for(int i = -100.00, j, y1, y2; i <= 100.00; i += 0.001){
		j = i + 0.001;
		y1 = a*i*i*i + b*i*i + c*i + d;
		y2 = a*j*j*j + b*j*j + c*j + d;
		if(y1 * y2 < 0)
			printf("%.2llf ", (i + j) / 2);
		
	}

	return 0;
}


//	-100.00 ~ 100.00
//	10000 + 2
//	1e8 == 1s
//   O(n) 	n <= 1e8 
//	 
//
