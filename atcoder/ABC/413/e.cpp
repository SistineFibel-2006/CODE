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
	cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve() {
    int n;
    cin >> n;
    int size = 1 << n; 
    vector<int> p(size);
    for (int i = 0; i < size; ++i) {
        cin >> p[i];
    }
    for (int k = 1; k <= n; ++k) {
        int s = 1 << k;
        int mid = 1 << (k - 1); 
        for (int i = 0; i < size; i += s) {
            auto l = p.begin() + i;
            auto r = p.begin() + i + mid;

            bool should_swap = lexicographical_compare(
                r, r + mid,
                l, l + mid
            );
            if (should_swap) {
                for (int j = 0; j < mid; ++j) {
                    swap(*(l + j), *(r + j));
                }
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        cout << p[i] << (i == size - 1 ? "" : " ");
    }
    cout << "\n";
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
