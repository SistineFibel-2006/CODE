// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define debug(x) cerr << #x << " = " << (x) << endl
// #define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
// #define all(x) (x).begin(),(x).end()
// void solve();
// #define endl '\n'

// const long long INF = 0x3f3f3f3f;
// const long long MOD = 1e9; //ģ��


// signed main (){ 
// 	std::cin.tie(NULL)->sync_with_stdio(false);
// 	int t = 1;
// 	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
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
// 1. С���ݣ��������ݣ��� n = 1?
// 2. ��Сֵ�����ֵȡ���٣��Ƿ�������
// 3. ��ʼֵ��û�и�ֵ����û�н�����
// 4. �����С���Ƿ�Խ�磿
// 5. ˼��������ʱ�򣬿����Ƿ�����Ƕ�������Σ������Ǹ�����ȷ���޷��������Ƿ���Է��α�����
// 6. ������ϸ�ķ�������?
// 7. ѡ��������Ƿ����Ϊ�գ�

// Trick:
// 1. 
// 2. 
// 3. 

// About implementation skills:
// 1. ȫ�ֳ�������д��ĸ�����ֲ���������ʱ�������ͺ������ݵĲ���ʹ��Сд��ĸ��
// 2. ��ģ�⾡����ѭ����ô������ôд��
// 3. ����һЩ���ݺ�С����Ҫά������������Ҫ��������ʱ�����Կ��ǰ����������ɱ�����
// 4. д�ɶ��������
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