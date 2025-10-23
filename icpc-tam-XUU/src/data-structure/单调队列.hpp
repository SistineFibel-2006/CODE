#include<bits/stdc++.h>
using namespace std;
struct qwq
{
	int x,y;
}a;
deque<qwq> q1;
deque<qwq> q2;
int ansmax[10000005];
int ansmin[10000005];
int main()
{
    int n,k,w,t=1;
    cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>w;
		a.x=w;
		a.y=i;
		while(q1.empty()==0&&w>=q1.back().x)
		{
			q1.pop_back();
		}
		while(q2.empty()==0&&w<=q2.back().x)
		{
			q2.pop_back();
		}
		q1.push_back(a);
		q2.push_back(a);
		while(i-k>=q1.front().y)
		{
			q1.pop_front();
		}
		while(i-k>=q2.front().y)
		{
			q2.pop_front();
		}
		if(i>=k)
		{
			ansmin[t]=q2.front().x;
			ansmax[t]=q1.front().x;
			t++;
		}
	}
	for(int i=1;i<t;i++)
	{
		cout<<ansmin[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<t;i++)
	{
		cout<<ansmax[i]<<" ";
	}
    return 0;
}