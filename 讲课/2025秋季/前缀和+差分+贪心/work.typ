#import "@preview/codly:1.3.0": *
#import "@preview/codly-languages:0.1.10": *
#show: codly-init.with()
#codly(languages: codly-languages)

#set page(
  "presentation-4-3",
  header : [
    #set align(center)
    �ڶ�����ѵ��*ǰ׺�� ��� ̰��*
    #line(length: 100%)
  ],
  footer : [
    #line(length: 100%)
    By --- Nil
  ],
  numbering: "1",
)

#place(center, dy : 40%)[
  #text(
    size : 4em,
    weight: "extrabold",
  )[
    ǰ׺�� ��� ��̰��
  ]\ \ \ \ 
]

#pagebreak()


#set text(lang: "zh")
#set heading(numbering: "I.")
#text(size: 2em)[
  = ǰ׺��(prefix-sum)
]
#text(size: 1.8em)[
  
  ǰ׺�ͣ� �������Ϊ�����е�ǰ$N$��͡�����һ����Ҫ��Ԥ����ʽ��\ \
  _һάǰ׺��_ : ����һ������Ϊ$n$������${a_i}_(i=1)^n$�������Ҫ��β�ѯ������$[l , r]$λ�����������ֵĺͣ���$sum_(i = l)^r a_i$������ô�Ϳ��Կ���ʹ��ǰ׺�͡�\
  �����ڸ���ѧϰ���е�ʱ�򣬶�ѧ�����е�ǰ$N$��ͣ���$ S_k = sum_(i=1)^k a_i $���ʱ������֪����$ S_0 = 0, S_i = S_(i - 1) + a_i , i in [1, n] $
  �������ǿ��Եõ���һ��ʽ��: $ sum_(i=l)^r a_i = S_r - S_(l - 1) $
]


#pagebreak()


#text(size: 1.8em)[
  Ȼ������������һ��ʱ�临�Ӷȣ�����ǰ׺�;�����������ʲô�ˡ�\
  ������������������������⣺\
  #set align(center)
  #box(fill: luma(230), inset : 4pt, radius : 20pt)[
    ����һ������Ϊ$N$������$A$��������$Q$��ѯ��\ ����ÿһ��ѯ�ʣ����Ǹ���һ������$[L,R]$������Ҫ����$ sum_(i=L)^R a_i $
  ]
]
#text(size : 1.8em)[
  *solution 1*:  _Step1_: ��������A  #sym.arrow.r.double.long _Step2_: $Q$��ѭ����ÿ�ζ���$L,R$ \ #sym.arrow.r.double.long _Step3:_ $R - L $��ѭ������Ͳ����\
  ����Ȼ���ǣ�������$O(N)$�ģ���ѯ�����ѭ��$Q$�Σ��ڲ�ѭ��$R-L$�Σ���ô��������ÿһ�ζ�ö��$1~N$���е����֣�ʱ�临�Ӷ���\ $O(N + Q N)$��.\ 
  *solution 2*: _Step1_: ��������A  #sym.arrow.r.double.long _Step2_: $N$��ѭ��Ԥ�����$S_(i in [1 , N])$ǰ׺�� \ #sym.arrow.r.double.long _Step3:_ $Q$��ѭ����ÿ�ζ���$L,R$ #sym.arrow.r.double.long _Step4_ : ֱ�����$S_R - S_(L- 1)$ \
  ������$O(N)$�ģ�Ԥ����ѭ��$Q$�Σ���ѯ��ѭ��$Q$�Σ�����ÿһ�β�ѯ��ֱ��$O(1)$��������Ը��Ӷ���$O(N+N+Q)$��.
]


#pagebreak()


#text(size : 1.7em)[
  �����������������
]
#text(size:1.4em)[
    ```cpp
int main() {
	int n,q,i; scanf("%d%d",&n,&q);
	int a[n+1]; for(i=1;i<=n;i++) scanf("%d",a+i);
	for(;q--;){
		int l,r,ans=0; scanf("%d%d",&l,&r);
		for(i=l;i<=r;i++) ans+=a[i];
		printf("%d",ans);
	}
}
  ```
```cpp
int main() {
	int n,q,i; scanf("%d%d",&n,&q);
	int a[n+1]; for(i=1;i<=n;i++) scanf("%d",a+i);	
	int pre[n+1]; pre[0]=0;
	for(i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(;q--;){
		int l,r; scanf("%d%d",&l,&r);
		printf("%d",pre[r]-pre[l-1]);		
	}
}
```
]


#pagebreak()


#text(size:1.8em)[
  ��άǰ׺�ͣ���ʵ��һάǰ׺�����ƣ�����һ������
]
#text(size:1.7em)[
  ʵ���ϣ�����һ����СΪ$M times N$�Ķ�ά����$A$����ǰ׺�͵�ʽ��Ӧ����
  $ S_(i,j) = sum_(k=1)^i sum_(h=1)^j  A_(k,h) $
  ��ô����Ҫ��������ƹ�ʽ�԰ɣ���Ӧ���������ģ�
  $ S_(i,j) = A_(i,j) + S_(i-1,j) + S_(i,j-1) - S_(i-1,j-1) $
  ������ͼ��ʾ��
  #set align(center)
  #image("pic/pre2.png",width: 13%)
  ȫ�� $=$ ��ɫ + ���� + ��� - ��
]
#text(size:1.7em)[
  ͬ������Ƶ��� $(i,j)=>(k,h)$�ľ����Ϊ��
  $ S_(k,h) - S_(i-1,h) - S_(k,j-1) + S_(i-1,j-1) $
]


#pagebreak()


#text(size:3em)[
  ��ô����������һ����ɣ� \
  ���P1387 ��������� \
  #link("https://www.luogu.com.cn/problem/P1387")\ 
]


#pagebreak()


#text(size:1.8em)[
  *solution* : ��󲻰���0�������Σ����仰˵�����ҵ���������������ʹ������������������ֵĺ͸պ�Ϊ�����С����ʽ���Ľ�: 
  $ sum_(i=x)^(x+l)sum_(j=y)^(y+l) A_(i,j) = l^2 $
  ǰ׺�ͼ�����Ҫ$O(n m)$��
  ö�ٱ߳�$l$��Ҫ$O(min(n, m))$��ö�ٺ�����Ҫ$O(n),O(m)$����$O(n m + min(n, m) n m)$ ����$n,m$ͬ�ף����Ը��ӶȾ��� $ O(n^3)$��.\ \
  �����ʹ��ǰ׺�ͣ�����������Ҫ��һ��$O(l^2)$�����վ���$O(n^5)$��.
  \ \
  ���ԣ���Ȼ���Կ���ǰ׺���Ż���ʱ�临�Ӷȣ�\

  #set align(center)
  ����ǰ׺�����Ǿ��Ƚ������  
]


#pagebreak()


#text(size:2em)[
  = ���
]
#text(size:1.8em)[
  ��֣���������${a_i}_(i=1)^n$�����Ĳ������${d_i}_(i=1)^n$�ǣ�
  $ d_i = a_i - a_(i-1), "�ر��" a_0 = 0 $
  ��ʵ���ѷ��֣�ǰ׺�͵Ĳ����ԭ���У�������е�ǰ׺����ԭ���У�\ \
  Ҳ����˵����ǰ׺�͡� �� ����֡� �������㣡

  $ a_i = sum_(j=1)^i d_i $
  $ &S_i = sum_(j=1)^i sum_(k=1)^j d_k = sum_(j=1)^i (i-j+1)dot d_j $

  ���ǣ��������ʲô�أ�\
  ǰ׺��һ�������ڴ������ߵĶ�β�ѯ�԰ɣ�\
  ��־��������������޸ĵģ�
]


#pagebreak()


#text(size:1.8em)[
  ���˵����Ҫ������${a_i}$������$[l,r]$�е�ÿ����������һ��$v$����ô��Ϳ��������Ĳ������${d_i}$�������²���:
  $ d_l <- d_l + v, d_(r+1) <- d_(r+1) - v $
  �ڶԲ�������������֮��$O(n)$����һ��ǰ׺�ͻ�ԭ��ԭ���м��ɣ�\ \
  ��ᷢ�֣����Ǿ�ʵ���˶��$O(1)$�������޸ģ�Ȼ��$O(n)$��ǰ׺�ͻ�ԭ����\ \ 
  �����֮ǰ���ص�$O(n)$��ÿ���޸ģ������$q$���޸ĵĻ�����ô���صĸ��ӶȾ���$O(n q)$�������ʹ�ò�ֵķ����޸ģ�����$O(q dot 1 + n)$�ģ�\ \
  ���ϣ�����һά��֣� ����������һ������ɣ�
  #set align(center)
  #box(fill: luma(230), inset : 4pt, radius : 20pt)[
    ����һ������Ϊ$N$������$A$��������$Q$���޸ģ�
    ÿ���޸��ṩ��������$L,R,X$����ʾ��������$[L,R]$��ÿ��Ԫ��$+X$\
    ����޸ĺ������$A$ 
  ]  
]


#pagebreak()


#text(size:2em)[
```cpp
#include<ios>
int main() {
	int n, q, i; 
  scanf("%d%d",&n,&q);
	int a[n + 1],d[n + 1]; 
  for(i = 1; i <= n; i ++) scanf("%d",a+i);
	for(; q --;){
		int l,r,x; scanf("%d%d%d",&l,&r,&x);
		d[l] += x, d[r + 1] -= x;
	}
	for(i=1;i<=n;i++) a[i] = a[i - 1] + d[i];
}
```
]
#text(size:1.8em)[
  �����ʹ�ò�ֺ��д���� ������Ǿ��Ƚ��ܵ������ʵ���Ķ�άʵ����ǰ׺�Ͳ��޲��죬����ʽ��һ����������
]


#pagebreak()


#text(size:2em)[
  = ̰���㷨����
]
#text(size:1.8em)[
  �������У����ǻ��������������Ƶ����⡣������������һ����ͬ�Ĺ��ɣ�*������������Ž⣬���������и���С��������Ž�ƴ�ն��ɡ�*
$ ==> $
���仰˵��*�ֲ��������Ž�ļ��ϣ�����������������ս⣡* \ 
\ 
������Ӧ�á�̰���㷨���Ĺؼ�Ҫ�ء� \ \

̰���㷨��Ӣ�*Greedy Algorithm*������һ���ü����ģ�⡰̰�ġ�˼ά�ľ��߹��̡�������ˡ��ǳ�̰�� ���� ÿһ��������ĳ��ָ��ѡ��ǰ�������ŵĲ�����������Ŀ���ǳ��ֻ��ע��ǰ���棬������δ�����ܵ�Ӱ�졣

�����֪��̰�ķ��������ܵõ�ȫ�����Ž⡣��ˣ���ʹ��̰���㷨ʱ������ͨ����Ҫ*֤������ȷ��*�����ܷ��ĵ�ʹ�á�

]


#pagebreak()


#text(size:1.8em)[
  ����̰���㷨��֤���������ṩ����������\ \
  + ��֤��������ı�����ĳ��ֵ��ʹ�𰸱�ø����ã���ô����֤����ǰ״̬�����ŵ��� $==>$ ���ı�һ��ֵ����ʹ�������ò��ô�ı����ֵ�����ŵ�.
  + ���ɷ����ȼ�����߽����������˵ǰ����״̬�����Ž�$F_1$��Ȼ����֤�������ں�����$F_(n+1)$���ܿ�����һ������ʹ��$F_(n+1)$������$F_n$�Ƶ�����.\ 
  
  ��ʵ̰��Ҳ�кܶ�����ı��֣��練��̰�ĵȵ�.

  ����������һ������ɣ�
  #set align(center)
  #box(fill: luma(230), inset : 4pt, radius : 20pt)[
    �̵�����$N$���ǹ���ÿ���ǹ���һ����Ŀ$X$����һ����ֵ$Y$\
    ����Ҫѡ��һ��$M$���ǹ���ʹ����ѡ��������ǹ����ܼ�ֵ���\
    ��ʽ���Ľ�����Ҫ���:
    $ "ans" = sum_(i =1 ) ^ M Y_i $
  ]    
]


#pagebreak()


#text(size:1.8em)[
  ������λӦ�ú����׾����뵽����Ϊ��Ҫѡ��$M$���ǹ���������Ȼ��ѡ��۸�����$M$������.\
  ������˼�룬���� ��̰�ġ� ��
  ��������:
]
#text(size:1.04em)[
    ```cpp
#include<ios>
#include<algorithm>
struct node{
	int y, x;
};
bool cmp(node a, node b){
	return a.y > b.y;
}
int main() {
	int n, m; scanf("%d%d",&n,&m);
	node a[n];
	for(int i = 0; i < n; i ++) 
		scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a,a+n,cmp);
	long long ans = 0;
	int cnt = m;
	for(int i = 0; i < n && cnt > 0; i ++) {
		int take = std::min(a[i].x, cnt);
		ans += take * a[i].y;
		cnt -= take;
	}
	printf("%lld",ans);
}
  ```

]


#pagebreak()


#text(size:2em)[
  ����������һ�����������ɣ�\
  CodeForces Round 1043 (division 3)\ 
  Problem E : Arithmetics Competition\
  #link("https://codeforces.com/contest/2132/problem/E")\

  _*hint*_�������Ҫ�������ǽ���ѧ����������Ŷ
]


#pagebreak()


#text(size:1.8em)[
  
]