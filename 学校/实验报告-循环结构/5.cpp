#include<bits/stdc++.h>
using namespace std;
int main(){
  char a;
  while(scanf("%c",&a)!= '\n'){
    a += 4;
    if(a < 'A' && a > 'z')
      a -= 'a' - 1;
    if(a > 'A' && a <= 'Z')
      a -= 'A' - 1;
    printf("%c",a);
  }
  while(scanf("%c",&a)!= '\n'){
    a -= 4;
    if(a < 'a')
      a += 'z' - 'a';
    if(a > 'z' && a < 'A')
      a += 'Z' - 'A';
    printf("%c",a);
  }
  return 0;
}