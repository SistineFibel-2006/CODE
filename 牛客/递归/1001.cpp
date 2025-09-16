#include <bits/stdc++.h>

signed main(){
	int a;
	std::cin >> a;
	do{
		int sum = 0;
		while(a != 0){
			sum += a % 10;
			a /= 10;
		}
		a = sum;
	}while(a > 9);
	std::cout << a <<std::endl;
	return 0;
}