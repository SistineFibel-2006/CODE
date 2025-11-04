#include <bits/stdc++.h>
using namespace std;

int num , ans;
int main(){
    cin >> num ;
    for(int a=1;a<=num;a++ ){
        string m,n;
        cin >> m;
        if (m.size() < 3) cout << "-1" << endl;
        for (int i = 0; i < n.size () - 2; i ++) {
			m = n.substr (i, 3);
			if (m == "MOO") ans = n.size () - 3;
			else if (m == "MOM" || m == "OOO") ans = min (ans, int (n.size () - 2) );
			else if (m == "OOM") ans = min (ans, int (n.size () - 1) );
       
    }
    if (ans == 100000) cout << -1 << "\n";
		else cout << ans << "\n";
    }
    return 0;
}