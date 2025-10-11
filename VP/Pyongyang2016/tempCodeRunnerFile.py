from datetime import date
t = int(input())
for _ in range(t) :
  a,b,c,d,e,f = map(int, input().split())
  t1=date(year=a,month=b,day=c)
  t2=date(year=d,month=e,day=f)
  t3=t2-t1
  print(t3.days+1)