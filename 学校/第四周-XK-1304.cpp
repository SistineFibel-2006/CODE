// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'


// signed main (){ 
// 	std::ios::sync_with_stdio(false);std::cin.tie(0);
// 	int t = 1;
// 	cin >> t;
// 	while(t --)
// 		solve();
// }

// void solve(){
// 	int a, b ,c;
// 	scanf("%d%d%d", &a, &b, &c);
// 	double s = 0.5 * (a + b + c);
// 	printf("%llf", sqrt(s * (s - a) * (s - b) * (s - c)));

// }
// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'


// signed main (){ 
// 	std::ios::sync_with_stdio(false);std::cin.tie(0);
// 	int t = 1;
// 	// cin >> t;
// 	while(t --)
// 		solve();
// }

// void solve(){
// 	int a, b, c;
// 	scanf("%d%d%d", &a, &b, &c);
// 	double dd = sqrt(b * b - 4.0 * a * c);
// 	double x1 = ((-b) + dd) / (2 * a);
// 	double x2 = ((-b) - dd) / (2 * a);	
// 	printf("x1 = %.2llf  x2 = %.2llf", x1, x2);
// }

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
	char a;
	scanf("%c", &a);
	printf("%c", a - 'A' + 'a');
}