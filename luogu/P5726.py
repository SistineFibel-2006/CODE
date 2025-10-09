n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = 0 
for i in range(1,n - 1) :
  ans = ans + a[i]
ans = ans / (n - 2)
print("%.2f" % ans)