#include<ios>
#include<algorithm>
struct node{
	int y, x;
};
bool cmp(node a, node b){
	return a.y > b.y;
}
int main() {
	int n, m; scanf("%d%d",&n,&m);
	node a[n];
	for(int i = 0; i < n; i ++) 
		scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a,a+n,cmp);
	long long ans = 0;
	int cnt = m;
	for(int i = 0; i < n && cnt > 0; i ++) {
		int take = std::min(a[i].x, cnt);
		ans += take * a[i].y;
		cnt -= take;
	}
	printf("%lld",ans);
}

// 1 2 4 8 16 32 64 2^(n - 1) ~ 2^n


// int main() {
// 	int n,q,i; scanf("%d%d",&n,&q);
// 	int a[n+1]; for(i=1;i<=n;i++) scanf("%d",a+i);
// 	for(;q--;){
// 		int l,r,ans=0; scanf("%d%d",&l,&r);
// 		for(i=l;i<=r;i++) ans+=a[i];
// 		printf("%d",ans);
// 	}
// }