#include bitsstdc++.h
#define ffor(i,a,b) for(int i=(a);i=(b);i++) 
#define roff(i,a,b) for(int i=(a);i=(b);i--) 
using namespace std;
typedef long long ll;
const int Maxn=3000005;
string s;
int n,q,t,tot;
int trie[Maxn][130],cnt[Maxn];
void insert(string s) {
	int len=s.size(),u=0;
	ffor(i,0,len-1) {
		int a=s[i];
		if (!trie[u][a]) trie[u][a]=++tot;
		u=trie[u][a];
		cnt[u]++;
	}
}
int find(string s) {
	int len=s.size(),u=0;
	ffor(i,0,len-1) {
		int a=s[i];
		if (!trie[u][a]) return 0;
		u=trie[u][a];
	}
	return cnt[u];
}
void solve() {
	cinnq;
	ffor(i,0,tot) ffor(j,0,122) trie[i][j]=0;
	ffor(i,0,tot) cnt[i]=0;
	tot=0;
	ffor(i,1,n) {
		cins;
		insert(s);
	}
	ffor(i,1,q) {
		cins;
		coutfind(s)'n';
	}
}
int main()
{
	cint;
	while (t--) solve();
	return 0;
}
