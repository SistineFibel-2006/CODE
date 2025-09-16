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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char arr[] = {'^', 'v', '<', '>'};

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve(){
	queue<pair<int, int>> q;
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	for(auto &c : g)
		cin >> c;
	
	vector<vector<int>> vis(h, vector<int> (w, -1));
	for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if (g[i][j] == 'E') {
                vis[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

	while(!q.empty()){
		auto [i, j] = q.front();q.pop();
		for(int k = 0; k <= 3; k ++){
			int ii = i + dx[k];
			int jj = j + dy[k];
			if(ii >= 0 && ii < h && jj >= 0 && jj < w)
				if(g[ii][jj] == '.' && vis[ii][jj] == -1){
					vis[ii][jj] = vis[i][j] + 1;
					q.emplace(ii,jj);
				}
		}
	}

	vector<string> ans = g;
	for(int i = 0; i < h; i ++)
		for(int j = 0; j < w; j ++)
			if(g[i][j] == '.'){
				for(int k = 0; k <= 3; k ++){
					int ii = i + dx[k];
					int jj = j + dy[k];
					if(ii >= 0 && ii < h && jj >= 0 && jj < w)	
						if(vis[ii][jj] == vis[i][j] - 1){
							ans[i][j] = arr[k];
							break;
						}				
				}
			}

	for(auto c : ans)
		cout << c << endl;
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