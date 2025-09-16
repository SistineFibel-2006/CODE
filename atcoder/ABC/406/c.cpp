// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define debug(x) cerr << #x << " = " << (x) << endl
// #define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
// #define all(x) (x).begin(),(x).end()
// void solve();
// #define endl '\n'

// const long long INF = 0x3f3f3f3f;
// const long long MOD = 1e9; //模数


// signed main (){ 
// 	std::cin.tie(NULL)->sync_with_stdio(false);
// 	int t = 1;
// 	// cin >> t;  //atc默认关闭，cf按需开启
// 	while(t --)
// 		solve();
// }

// void solve(){
// 	int N;
// 	cin >> N;
// 	vector<int> a(N);
// 	for(auto &c : a)
// 		cin >> c;
//     int count = 0;

//     for (int s = 0; s < N; s++) {
//         for (int l = s + 3; l < N; l++) { 
//             if (a[s] >= a[s + 1]) {
//                 continue; 
//             }
//             bool fnP = false;
//             bool fnV = false;
//             int Psit = -1;
//             int Vsit = -1;
//             for (int i = s + 1; i < l; i++) {
//                 if (i > s && i < l && a[i-1] < a[i] && a[i] > a[i+1]) {
//                     if (fnP) {
//                         fnP = false;
//                         break;
//                     }
//                     fnP = true;
//                     Psit = i;
//                 }

//                 if (i > s && i < l && a[i-1] > a[i] && a[i] < a[i+1]) {
//                     if (fnV) {
//                         fnV = false;
//                         break;
//                     }
//                     fnV = true;
//                     Vsit = i;
//                 }
//             }

//             if (fnP && fnV && 
//                 Psit >= s + 1 && Psit <= l - 1 && 
//                 Vsit >= s + 1 && Vsit <= l - 1) {
//                 count++;
//             }
//         }
//     }

// 	cout << count;
// }	
// //test
// /*
// ?
// // ? (?????) ?
// */

// /*
// What's wrong with my code?
// 1. 小数据？特殊数据？如 n = 1?
// 2. 最小值，最大值取多少？是否会溢出？
// 3. 初始值有没有赋值？有没有建树？
// 4. 数组大小？是否越界？
// 5. 思考暴力的时候，考虑是否可能是多个连续段？或者是个数不确定无法暴力？是否可以分治暴力？
// 6. 进行详细的分类讨论?
// 7. 选择的区间是否可以为空？

// Trick:
// 1. 
// 2. 
// 3. 

// About implementation skills:
// 1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
// 2. 大模拟尽量遵循：怎么方便怎么写。
// 3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
// 4. 写成多个函数。
// */

#include <bits/stdc++.h>
using namespace std;

bool isok(const vector<int>& P, int l, int r) {
    int L = r - l + 1;
    if (L < 4) return false;
    if (P[l] >= P[l + 1]) return false;
    int peakCount = 0;
    int valleyCount = 0;
    
    for (int i = l + 1; i < r; i++) {
        
        int relativeIdx = i - l;
        if (relativeIdx < 1) continue;
        
        if (P[i-1] < P[i] && P[i] > P[i+1]) {
            peakCount++;
            if (peakCount > 1) return false; 
        }

        if (P[i-1] > P[i] && P[i] < P[i+1]) {
            valleyCount++;
            if (valleyCount > 1) return false;
        }
    }
    return (peakCount == 1 && valleyCount == 1);
}

int cnt1(const vector<int>& P, int N) {
    int count = 0;

    for (int l = 0; l < N; l++) {
        for (int r = l + 3; r < N; r++) { 
            if (isok(P, l, r)) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;   
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    int result = cnt1(P, N);
    cout << result << endl;
    
    return 0;
}