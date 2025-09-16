#include <bits/stdc++.h>
using namespace std;
	struct node{
		int l;
		int r;
	}a[2000020];


	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<q;i++)
		cin>>a[i].l>>a[i].r;
	int b[n+1];
	for(int i=0;i<=n;i++)
		b[i]=0;
	int sum[n+1];
	for(int i=0;i<=n;i++)
		sum[i]=0;
	for(int i=0;i<q;i++){
		sum[a[i].l-1]++;
		sum[a[i].r]--;
		//cout<<sum[0]<<" ";
	}
	for(int i=0;i<=n;i++){
		b[i+1]=sum[i]+b[i];
		//cout<<b[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i]%2;
		//cout<<b[i]<<" ";
	}
	int count=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1||b[i]==-1)
		count++;
	}
	cout<<count<<" ";
	return 0;
		
}