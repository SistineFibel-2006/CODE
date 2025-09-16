#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for(int i = 0; i < h; i ++)
		cin >> s[i];
	vector<vector<int>> pre(h + 1, vector<int>(w + 1, 0)); 

	// ǰ׺��
	for(int i = 0; i < h; i ++) { 
		for(int j = 0; j < w; j ++) { 
			pre[i + 1][j + 1] = pre[i + 1][j] + (s[i][j] == '#' ? 1 : -1);
        }
    }

	long long cnt = 0;

	int nowmax = h * w;
	int offset = nowmax; 
	int sizea = 2 * nowmax + 1;

	for(int l = 1; l <= w; l ++){
		for(int r = l; r <= w; r ++){
			vector<int> lsum(h + 1); 
			for(int i = 1; i <= h; i ++) {
				lsum[i] = pre[i][r] - pre[i][l - 1]; 
            }
			vector<int> c(sizea, 0); 
			
			c[0 + offset] = 1; 
			int nowsum = 0; 

			for(int i = 1; i <= h; i ++){
				nowsum += lsum[i]; 

				cnt += c[nowsum + offset]; 
				c[nowsum + offset] ++; 
			}
		}
	}
	cout << cnt << endl;
}


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
1.   //// ///// �뵽 ���� ����ת��Ϊ �����ͣ���������
2.
3.

About implementation skills:
1. ȫ�ֳ�������д��ĸ�����ֲ���������ʱ�������ͺ������ݵĲ���ʹ��Сд��ĸ��
2. ��ģ�⾡����ѭ����ô������ôд��
3. ����һЩ���ݺ�С����Ҫά������������Ҫ��������ʱ�����Կ��ǰ����������ɱ�����
4. д�ɶ��������

����Ŀ˼· ��
��Ϊ # �� . �� ͬ�������� ����ô����Ԥ����� +1 �� -1�� ��ֻ��Ҫ�ҵ���һ�����η����ڣ� ��������0 ��
�Ӿ������������
�ͱ����һ����άǰ׺�͵���Ŀ
��Ԥ���� 0,0�� i, j�����о���� ������
ö�ٷ�Χ
Ȼ��������緶Χ��ÿ��ÿ�еĴ�����
ͳ�ƴ�������
*/
