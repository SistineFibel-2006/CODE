#include <bits/stdc++.h>
using namespace std;

int main(){
	for(int i = 100; i <= 999; i ++){
			int x = i / 10;
			if(i % 3 == 0 && x % 2 == 0)
				cout << i << endl;
		}		
    return 0;
}

