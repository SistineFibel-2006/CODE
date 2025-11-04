#include <bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
int n,c,ans;
signed main(){
	cin >> n >> c;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n);
	int point = 0;
	while(point < n){
		for(int i = point + 1; i < n;i++){
			if(a[point] + c == a[i])
				ans+= 1;
			else if(a[point] + c > a[i])
				break;		
		}
		point++;
	}
	cout << ans <<endl;
	return 0;
}
