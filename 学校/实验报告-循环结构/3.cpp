#include <bits/stdc++.h>
using namespace std;

int main() {
  puts("*****************************");
  puts("1.完成计算1 - n的求和");
  puts("2.完成输出斐波那契数列的前m项");
  puts("*****************************");
  int q;
  scanf("%d", &q);
  if (q == 1) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
      sum += i;
    printf("%d\n", sum);
  }
  else if (q == 2) {
    int n;
    scanf("%d", &n);
    int s1 = 1, s2 = 1;
    printf("%d\n", s1);
    printf("%d\n", s2);
    for (int i = 1; i <= n; i++){
      s2 = s1 + s2;
      s1 = s1 + s2;
      printf("%d\n", s1);
      printf("%d\n", s2);
    }
  }
  return 0;
}
