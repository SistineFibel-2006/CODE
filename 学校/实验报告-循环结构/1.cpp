#include <bits/stdc++.h>

int main () {
	double ans = 0;
	for(int i = 1; i <= 100; i ++)
		ans += i;
	for(int i = 1; i <= 50; i ++)
		ans += (i * i);
	for(auto i = 1.0; i <= 10.0; i += 1.0)
		ans += (1 / i);
	printf("%d", ans);	
	return 0;
}