#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int *l,*r,a[300003],n,q,k,d=0,typ,kkk;
signed main()
{
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	l=a+1,r=a+n+1;
	sort(l,r);
	while(q--)
	{
		cin>>typ;
		if(typ==1){cin>>kkk;d-=kkk;r=upper_bound(l,r,k+d);}
		if(typ==2){cin>>kkk;d+=kkk;l=lower_bound(l,r,-k+d);}
		if(typ==3)cout<<r-l<<endl;
	}
}