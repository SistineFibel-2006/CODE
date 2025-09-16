#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;


signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n+1]={0};
    int tt=0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        tt+=arr[i];
        
    }
    if(tt>=10000000000000)
    {
        int a=tt/n;
        int b;
        int ans=INF;
        for(int i=1;i<=INF;i+=i){
            a=a-1+i;
            for(int j=1;j<=INF;j+=j){
                if(tt%n!=0) 
                    b=a+j;
                else
                    b=a;
                ans=min(ans,a|b);
            }
        }
        ans=min(ans,a|INF);
        ans=min(ans,b|INF);
        ans=min(ans,tt|a|0|b);
        cout << ans << endl;
        return 0;
    }
    else{
        int s=tt;
        if(s%n==0) cout<<s/n;
        else{
            int ans=INF;
            int y=s%n,z=s/n,c=0;
            while(z>0){
                if((z&1)||y<(1<<c)) break;
                z>>=1;
                c++;
            }
            if(z==0) cout<<1;
            else if(y<(1<<c)) cout<<s/n+y;
            else if(y%(1<<c)==0) cout<<s/n;
            else cout<<s/n+y%(1<<c);
        }
    }
}