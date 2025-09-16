// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'
// // #define max(x, y) x>y?x:y

// 	map<string, int> a;
// 	int p = 1984;
// 	string x[10] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin","ren","gui"};
// 	string y[12] = {"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};
	
// 	int xx = 0, yy = 0;

// signed main() {

// 	for(int i = 0; i < 60; i ++) {
// 		string s = x[xx] + y[yy];
// 		a[s] = p ++;
// 		xx ++; yy ++;
// 		if(xx == 10) 
// 			xx = 0;
// 		if(yy == 12)
// 			yy = 0;
// 	}
//     int tt = 1;
//     cin >> tt;
//     while(tt --)
//     	solve();
// }

// void solve() {

// 	string ss;
// 	cin >> ss;
// 	cout << a[ss] << endl;
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
// // #define max(x, y) x>y?x:y
// 	string ss = "";
// int f[5000] = {0};
// signed main() {
//     int tt = 1;
//     cin >> tt;
//     while(tt --)
//     	solve();
// }

// void solve() {
//     string S, K;
//         cin>>S>>K;
//         int k=0;
//         switch (K.size()) {
//         case 1:
//             k=K[0]-'0';
//             break;
//         case 2:
//             k=(K[0]-'0')*10+K[1]-'0';
//             break;
//         default:
//             k=114514;
//             break;
//         }
//         if(k>26){
//             sort(S.begin(),S.end());
//             printf("%d\n",unique(S.begin(),S.end())-S.begin());
//             return;
//         }
//         else{
//             string S1="";
//             for(int i=0;i<k;i++)
//                 S1+=S;
//             int maxans=0;
//             for(int i=0;i<S1.size();i++){
//                 f[i]=1;
//                 for(int j=0;j<i;j++)
//                     if(S1[j]<S1[i])
//                         f[i]=max(f[i],f[j]+1);
//                 maxans=max(maxans,f[i]);
//             }
//             printf("%d\n",maxans);
//         }
// 	// string s, K;
// 	// cin >> s >> K;
//     // int k;
//     // if(K.size() <= 2) {
//     //     if(K.size() == 1)
//     //         k = K[0] - '0';
//     //     else {
//     //         k = (K[0] - '0') * 10 + K[1] - '0'; 
//     //     }
//     // }
//     // else
//     //     k = 27;
//     // if(k > 26){
//     //     sort(s.begin(), s.end());
//     //     cout << unique(s.begin(), s.end()) - s.begin() << endl;
//     //     return;
//     // }

// 	// // map<char, bool> a;
// 	// // int cnt = 0;
// 	// // for(auto c : s){
// 	// // 	if(!a[c])
// 	// // 		cnt++;
// 	// // 	a[c] = true;
// 	// // }

// 	// // if(n >= s.length()){
// 	// // 	cout << cnt << endl;
// 	// // 	return;
// 	// // }
	

// 	// for(int i = 0; i < k; i ++)
// 	// 	ss += s;
//     // int f[50000] = {0};
//     // int ans = 0;
//     // for(int i = 0; i < ss.size(); i ++){
//     //     f[i] = 1;
//     //     for(int j = 0; i < i; j ++) {
//     //         if(ss[j] < ss[i])
//     //             f[i] = max(f[i], f[j] + 1);
//     //     }
//     //     ans = max(ans, f[i]);
//     // }

// 	// cout << ans << endl;
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
// 	int tt;
// 	cin >> tt;
// 	while(tt --)
// 		solve();
// }

// void solve(){
// 	i64 n, k;
// 	cin >> n >> k;

// 	if(k % 2 != 0){
// 		cout << 0 << endl;
// 		return;
// 	}

// 	i64 m = k / 2;
// 	if(m > n - 1) {
// 		cout << 0 << endl;
// 		return;
// 	}

// 	i64 t = (n - m - 1) / (2 * m);
// 	i64 cnt = t + 1;
// 	i64 sum = n * cnt - m * cnt * cnt;
// 	cout << sum << endl;
// }


// #include <iostream>
// #include <vector>
// #include <cstring>

// using namespace std;

// const int MAX_R = 1005;
// const int MAX_B = 1005;
// const int MAX_M = 1005;

// int memo[MAX_R][MAX_B][MAX_M];

// bool canWin(int r, int b, int m) {
//     if (m < 0) return false;
//     if (r < 0 || b < 0) return false;

//     if (memo[r][b][m] != -1) return memo[r][b][m];

//     // 检查是否可以直接清空桌面
//     if (m == 0) {
//         // 操作1：拿走k红宝石
//         for (int k = 1; k <= 3; ++k) {
//             if (r == k && b == 0) {
//                 return memo[r][b][m] = true;
//             }
//         }
//         // 操作3：拿1蓝宝石，0红宝石
//         if (b == 1 && r == 0) {
//             return memo[r][b][m] = true;
//         }
//         // 操作3：拿1蓝宝石，1红宝石
//         if (b == 1 && r == 1) {
//             return memo[r][b][m] = true;
//         }
//     }

//     // 处理所有可能的操作
//     bool win = false;

//     // 操作1：拿走1-3红宝石
//     for (int k = 1; k <= 3; ++k) {
//         if (r >= k) {
//             int nr = r - k;
//             if (!canWin(nr, b, m)) {
//                 win = true;
//                 break;
//             }
//         }
//     }
//     if (win) return memo[r][b][m] = true;

//     // 操作2：蓝宝石转红宝石
//     if (b >= 1) {
//         int nr = r + 1;
//         int nb = b - 1;
//         if (!canWin(nr, nb, m)) {
//             return memo[r][b][m] = true;
//         }
//     }

//     // 操作3：拿1蓝宝石，0或1红宝石
//     if (b >= 1) {
//         // 拿0红宝石
//         if (!canWin(r, b - 1, m)) {
//             return memo[r][b][m] = true;
//         }
//         // 拿1红宝石（如果存在）
//         if (r >= 1) {
//             if (!canWin(r - 1, b - 1, m)) {
//                 return memo[r][b][m] = true;
//             }
//         }
//     }

//     // 操作4：拿2蓝宝石，生成1红宝石
//     if (b >= 2) {
//         int nr = r + 1;
//         int nb = b - 2;
//         if (!canWin(nr, nb, m)) {
//             return memo[r][b][m] = true;
//         }
//     }

//     // 处理宝盒操作（m > 0）
//     if (m > 0) {
//         // 蓝星：生成1蓝宝石
//         if (!canWin(r, b + 1, m - 1)) {
//             return memo[r][b][m] = true;
//         }
//         // 苏石：生成1红宝石
//         if (!canWin(r + 1, b, m - 1)) {
//             return memo[r][b][m] = true;
//         }
//         // 共生：生成1红1蓝
//         if (!canWin(r + 1, b + 1, m - 1)) {
//             return memo[r][b][m] = true;
//         }
//     }

//     // 所有操作都无法让对手必败
//     return memo[r][b][m] = false;
// }

// int main() {
	
//     memset(memo, -1, sizeof(memo));
//     int t;
//     cin >> t;
//     while(t --) {



//     int r, b, m;
//     cin >> r >> b >> m;

//     if (canWin(r, b, m)) 
//         cout << "Alice" << endl;
//     else 
//         cout << "Bob" << endl;
//     }
    
//     return 0;
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
// const int N = 1e6 + 10;
// // int n;
// int b[N], c[N];

// int n,a[1000005],fir[1000005],uni[1000005];
// const int Bad=1e9+7;

// signed main (){ 
//     std::ios::sync_with_stdio(false);std::cin.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t --)
//         solve();
// }

// void solve(){
//         memset(a,0,sizeof a);
//         memset(b,0,sizeof b);
//         memset(c,0,sizeof c);
//     cin >> n;
//     for(int i = 1; i <= n; i ++)
//         cin >> a[i];
//     for(int i = n; i > 0; i --) {
//         if(a[i] == 0) {
//             b[i] = b[i + 1];
//             continue;
//         }        
//         b[i] = b[i + 1] + (c[a[i]] == 0 );
//         c[a[i]] = i;        
//     }
//     i64 ans = 0;
//     int ls0 = 0;
//     for(int i = 1; i <= n; i ++) {
//         if(a[i] == 0) {
//             ls0 = i;
//             continue;
//         }
//         if(c[a[i]] < ls0) {
//             ans += b[i + 1];
//             c[a[i]] = (int)(1e9 + 10);
//         }
//     }

//     cout << ans << endl;
    //     memset(a,0,sizeof a);
    //     memset(fir,0,sizeof fir);
    //     memset(uni,0,sizeof uni);
    // cin >> n;
    // for(int i=1;i<=n;i++)
    //     cin >> a[i];
    // for(int i=n;i>0;i--){
    //     if(a[i]==0){
    //         uni[i]=uni[i+1];
    //         continue;
    //     }
    //     uni[i]=uni[i+1]+(fir[a[i]]==0);
    //     fir[a[i]]=i;
    // }
    // long long cnt=0;
    // int last0=0;
    // for(int i=1;i<=n;i++){
    //     if(a[i]==0){
    //         last0=i;
    //         continue;
    //     }
    //     //printf("fir[%d]=%d uni[%d+1]=%d last0=%d\n",a[i],fir[a[i]],i,uni[i+1],last0);
    //     if(fir[a[i]]<last0){
    //         cnt+=uni[i+1];
    //         fir[a[i]]=Bad;
    //     }
    // }
    // printf("%lld\n",cnt);
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
//     std::ios::sync_with_stdio(false);std::cin.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t --)
//         solve();
// }

// void solve(){
//     int a, b, c;
//     cin >> a >> b >> c;
//     if((a + 2 * b + 4 * c) % 4 == 0) 
//         cout << "Bob" << endl;
//     else
//         cout << "Alice" << endl;
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

int n,m,a[900005];
vector<int> g[900005];

signed main (){ 
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
        solve();
}

void solve(){
    cin >> n >> m;
    memset(a, 0, 4 * (3 * n + 3));
    for(int i=0;i<3*n+3;i++)
        g[i].clear();
    bool p = 1;
    for(int i=1;i<=m;i++) {
    int v,j,col;
    cin >> v >> j >> col;
    int x=(j+1)/2,y=n + n - v + 1,z = n + n + v - j / 2;
    if(col==y)swap(x,y);
    else if(col==z)swap(x,z);
    else if(col!=x)
        p = false;
    g[x].emplace_back(y);
    g[x].emplace_back(z);
    a[y]++;a[z]++;
    }
    vector<int> q;
    for(int i=1;i<=3*n;i++)
        if(a[i]==0)
            q.emplace_back(i);
    for(int hd=0;hd<q.size();hd++){
        for(int i:g[q[hd]]){
            a[i]--;
            if(a[i]==0)
                q.emplace_back(i);
        }
    }
    if(p && q.size()==3*n)
        puts("Yes");
    else 
        puts("No");    
}


