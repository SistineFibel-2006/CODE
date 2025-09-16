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
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
	for(int i = 0; i < n + 1; i ++)
		a[i][0] = 0;
	for(int i = 0; i < n + 1; i ++)
		a[0][i] = 0;	
	vector<pair<string, int> > ans;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> a[i][j];
	
	if(m >= n){
		for(int i = 1; i <= n; i ++){
			int minx = INF;
			for(int j = 1; j <= m; j ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int j = 1; j <= m; j ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"row", i});
			}
		}
		for(int j = 1; j <= m; j ++){
			int minx = INF;
			for(int i = 1; i <= n; i ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int i = 1; i <= n; i ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"col", j});
			}
		}
	}
	else { //����������
		for(int j = 1; j <= m; j ++){
			int minx = INF;
			for(int i = 1; i <= n; i ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int i = 1; i <= n; i ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"col", j});
			}
		}
		for(int i = 1; i <= n; i ++){
			int minx = INF;
			for(int j = 1; j <= m; j ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int j = 1; j <= m; j ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"row", i});
			}
		}
	}
		
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(a[i][j] != 0) {
				cout << -1;
				return;
			}
	cout << ans.size() << endl;
	for(auto [x, y] : ans){
		cout << x << " " << y << endl;
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
