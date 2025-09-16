#include <bits/stdc++.h>
#define int double
using namespace std;
int a,b,c,d;
signed main(){
cin >> a >> b >> c >> d;
for(double i=-100;i<=100;i+=0.001){
      double j=i+0.001;
      double y1=a*i*i*i+b*i*i+c*i+d;
      double y2=a*j*j*j+b*j*j+c*j+d;
      if(y1>=0&&y2<=0||y1<=0&&y2>=0){
         double x=(i+j)/2;
         printf("%.2lf ",x);
      }
   }
}