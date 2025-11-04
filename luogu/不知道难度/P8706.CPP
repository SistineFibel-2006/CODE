#include <bits/stdc++.h>
using namespace std;
unsigned main(){
    string a;
    cin >> a;
    int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]<='9'&&a[i]>='0'){
			int n=a[i]-'0';
			for(int j=2;j<=n;j++){
				cout<<a[i-1];
			}
}
            else cout<<a[i];
    }

}