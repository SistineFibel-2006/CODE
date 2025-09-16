#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
int main () {std::cin.tie(NULL)->sync_with_stdio(false);
	const long double X = 1000;std::cout << std::fixed<<std::setprecision(10);int t;for(std::cin >> t; t --;){int n; std::cin >> n; std::vector<long double> p(n + 2); for(int i = 1; i <= n; i ++) {int x;std::cin>>x;p[i]=x/X;}std::vector<long double> f(n+1,0); f[n]=n; for(int i=n-1;i>=1;i--) f[i]=std::min(f[i+1],((1-p[i])*i+p[i]*(f[i+1]+20)));std::cout<<f[1]<<'\n';}
}