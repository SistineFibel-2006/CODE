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
const int N = 2010;

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}


void solve(){
    int n;
    cin >> n;
    string s[n];
    vector<int> v(10, 0), l(10, INF), r(10, -1), u(10, INF), d(10, -1);
    for(int i = 0; i < n; i ++)
        cin >> s[i];
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j++) {
        int x = s[i][j] - '0';
        u[x] = min(u[x], i); 
        d[x] = max(d[x], i);
        l[x] = min(l[x], j); 
        r[x] = max(r[x], j);
      }

    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j ++) {
        int x = s[i][j] - '0';
        v[x] = max(v[x], max(d[x] - i, i - u[x]) * max(n - 1 - j, j - 0));
        v[x] = max(v[x], max(r[x] - j, j - l[x]) * max(n - 1 - i, i - 0));
      }
    
    for(auto c : v)
        cout << c << ' ';
    puts("");

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
