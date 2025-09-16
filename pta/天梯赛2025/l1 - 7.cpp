#include <bits/stdc++.h>
using namespace std;
#define int long long

int mi[40] = {0};
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int nop;
	for(int i = 1; i <= 40; i ++){
		ans = 0;
		for(int j = 1; n > ans; j ++){
			ans += pow(j, i);
			nop = j;
		}
//		cout << i << " : " << ans << " : " << nop <<endl;
		if(n == ans)
			mi[i] = nop;
			
	}
	
//	for(int i = 1; i <= 10; i ++)
//		cout << mi[i] << " ";
//	cout << endl;
	for(int i = 40; i >= 1; i --){
		if(mi[i] != 0){
			for(int j = 1; j <= mi[i] - 1; j ++){
				printf("%d^%d+",j,i);
			}
			printf("%d^%d",mi[i],i);
			return 0;
		}
	}
	cout << "Impossible for " << n << endl;
    return 0;
}
