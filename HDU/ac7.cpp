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
// 	cin >> t;  //atcĬ�Ϲرգ�cf���迪��
// 	while(t --)
// 		solve();
// }

// void solve(){
// 	int n;
//     cin >> n;
//     vector<int > a(n);
//     unordered_map<int, int > pos;
//     for(int i = 0; i < n; i ++)
//         cin >> a[i], pos[a[i]] = i;
//     int maxl = 1, cl = 1;
//     for(int i = 2; i <= n; i ++){
//         if(pos[i] > pos[i - 1])
//             cl += 1, maxl = max(maxl, cl);
//         else
//             cl = 1;
//     }
//     cout << n - maxl << endl;
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
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��


signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve(){
	int v, w;
    cin >> v >> w;

    if (v <= w) {
        cout << 1 << endl;
       	return ;
    }

    int ans = (w % 2) ? v / (w - w / 2) : (v >= w / 2) + (v - (v >= w / 2) * w / 2) / (w / 2 + 1);
    cout << ans << endl;
}
//test
/*
?
// ? (?????) ?
*/

/*
What's wrong with my code?
1. С���ݣ��������ݣ��� n = 1?
2. ��Сֵ�����ֵȡ���٣��Ƿ�������
3. ��ʼֵ��û�и�ֵ����û�н�����
4. �����С���Ƿ�Խ�磿
5. ˼��������ʱ�򣬿����Ƿ�����Ƕ�������Σ������Ǹ�����ȷ���޷��������Ƿ���Է��α�����
6. ������ϸ�ķ�������?
7. ѡ��������Ƿ����Ϊ�գ�

Trick:
1. 
2. 
3. 

About implementation skills:
1. ȫ�ֳ�������д��ĸ�����ֲ���������ʱ�������ͺ������ݵĲ���ʹ��Сд��ĸ��
2. ��ģ�⾡����ѭ����ô������ôд��
3. ����һЩ���ݺ�С����Ҫά������������Ҫ��������ʱ�����Կ��ǰ����������ɱ�����
4. д�ɶ��������
*/