#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define int long long
#define double long double
const int N=1005;
const double PI=3.1415926;
struct pt{
	double x,y,z,r;
};
double getA(pt a,pt b){
	double dot = a.x*b.x+a.y*b.y+a.z*b.z;
	double d=sqrt((a.x*a.x+a.y*a.y+a.z*a.z)*(b.x*b.x+b.y*b.y+b.z*b.z));
	double cosT=dot/d;
	//cerr << '!' << dot << ' ' << d << ' ' << acos(cosT) << endl;
	return acos(cosT);
}

void sol() {
	int n;
	cin >> n;
	pt arr[n+10]{{0,0,0,0}};
	for(int i=0;i<n;i++){
		double a,b,R;
		cin >> a >> b >> R;
		arr[i].z=sin((b)/360*2*PI);
		arr[i].x=cos((b)/360*2*PI)*cos((a)/360*2*PI);
		arr[i].y=cos((b)/360*2*PI)*sin((a)/360*2*PI);
		arr[i].r=R;
	}
	int ans=1;
	int nmax=1;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			//cerr << arr[i].r << ' ' << arr[j].r << endl;
			if((getA(arr[i],arr[j]))*6370<=arr[j].r){
				//cerr << '!' << ' ' << getA(arr[i],arr[j])*6370 << endl;
				cnt++;
			}
		}
		if(nmax<=cnt){
			ans=i+1;
			nmax=max(nmax,cnt);
		}
	}
	
	cout << ans << endl;	
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    	sol();
}