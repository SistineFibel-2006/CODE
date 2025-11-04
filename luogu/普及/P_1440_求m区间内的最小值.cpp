#include<iostream>
using namespace std;
const int MAXN=10000000;
int dui[MAXN],a[MAXN];
int  n,m,x,end=1,r=1;
int main()
{
	cin >> n >> m;
	cout << "0" << endl;
	for (int i = 0;i <= n - 1; ++i)
	{
		scanf ("%d",&a[i]);
		while (a [dui [r - 1]]>=a [i] && end < r)
		    r--;
		dui[r ++]=i;
		if (i - dui[l] + 1 > m) 
		    end++;
		printf("%d",a[dui[end]]);
		if (i!=n-1) 
		    cout << endl;
	}
	return 0;
}