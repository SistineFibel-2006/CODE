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
    int n, q; cin >> n >> q;
    // vector<int > a(n + 1, 0);
    // for(int i = 1; i <= n; i ++)
    //     cin >> a[i];
    // auto cnt = [&]() -> int{
    //     int count = 0;
    //     for(int i = 1; i <= n; i ++) {
    //         bool isok = 1;
    //         if(n == 1) {
    //             isok = 0;
    //         }
    //         else if(i == 1){
    //             if(a[i] >= a[i + 1]) isok = 0;
    //         } 
    //         else if(i == n) {
    //             if(a[i] >= a[i - 1]) isok = 0;
    //         }
    //         else {
    //             if(a[i] >= a[i - 1] || a[i] >= a[i + 1]) isok = 0;
    //         }
    //         if(isok)
    //             count ++;
    //     }
    //     return count;
    // };
    vector<int> a(n);
    int ev = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] % 2 == 0)
            ev ++;
    }

    
    for(int i = 0; i < q; i ++) {
        int p, v; cin >> p >> v;
        int idx = p - 1;
        if(a[idx] % 2 == 0)
            ev --;
        a[idx] += v;
        if(a[idx] % 2 == 0)
            ev ++;
        cout << ev << endl; 
    }
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
