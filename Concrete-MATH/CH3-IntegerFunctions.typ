= #sym.section 3 Integer Function 整数函数
== #sym.section 3.1 Floors and Ceilings 下取整和上取整
\
$floor(x)$ = 最大的小于等于 $x$ 的整数 \
$ceil(x)$ = 最小的大于等于 $x$ 的整数 *(3.1)*

#sym.arrow.r.double $
floor(x) = x #sym.arrow.l.r.double x "是整数" #sym.arrow.l.r.double ceil(x) = x
$

#sym.arrow.r.double $
ceil(x) - floor(x) =  [x "is not an integer"] 
$ *(3.2)*\ (艾弗森括号，显然如果上取整和下取整不等，那么x不是整数)

#sym.arrow.r.double $
x-1 lt floor(x) lt.eq x lt.eq floor(x) lt x + 1
$ *(3.3)*

#sym.arrow.r.double $
floor(-x) = -floor(x) ;space ceil(-x) = -ceil(x)
$ *(3.4)*

#sym.arrow.r.double 没有这两个记号之前，人们使用的记录方法
$ 
\
floor(x) = n #sym.arrow.l.r.double n lt.eq x lt n + 1,(a)\
floor(x) = n #sym.arrow.l.r.double x - 1 lt n lt.eq x,(b)\
ceil(x) = n #sym.arrow.l.r.double x-1 lt n lt.eq x, (c)\
ceil(x) = n #sym.arrow.l.r.double x lt.eq n lt x + 1.(d)\
$ 
*(3.5)*\
- 在上面这个式子中，我们认为 $x$ 是实数，$n$ 是整数.

- (a)和(c)就是*(3.1)*的直接推论(?)，(b)和(d)是相同的，互为重排后的不等式，通过以上，我们有一个结论：

$ 
ceil(x+n)=ceil(x)+n,space "integer" n\
floor(x+n)=floor(x)+n,space "integer" n\
$ *(3.6)*\
- 有(3.5)(a)，于是 ($floor(x)+n lt.eq x+n lt floor(x)+n+1$), 比如 $floor(n x) eq.not n floor(x)$，当 $n eq 2 "and" n eq frac(1,2)$. 所以我们知道，上取整和下取整函数是"片面灵活性"的. 我们通常乐于摆脱它们；或者，如果无法摆脱，只要能证明任何相关结论，我们也会感到满意.

- 所以，在很多情形下，上取整和下取整函数（或括号）其实是不必要的，这样一来，我们就可以随意插入或删除它们. 比方说，任意一个实数与整数之间的不等式，都可以等价于一个包括取整函数的整数间不等式：
$
  x lt n #sym.arrow.l.r.double floor(x)lt n, space (a)\
  n lt x #sym.arrow.l.r.double n lt ceil(x), space (b)\
  x lt.eq n #sym.arrow.l.r.double ceil(x) lt.eq n, space(c)\
  n lt.eq x #sym.arrow.l.r.double n lt.eq floor(x). space(d)\
$ *(3.7)*\
- 这些式子非常容易证明. 如果说记忆这四个式子的难度和证明这四个式子的难度同样简单的话，那就太好了. 但是当我们决定使用哪个式子的时候，我们需要多想想，选用合适的.

- $x$ 和 $floor(x)$ 的不同部分被称作 _fractional part of $x$ _，它也有一个符号:
$
  {x} eq x - floor(x)
$ *(3.8)*\
- 有时我们把 $floor(x)$ 称作 _integer part of x_，因为 $x eq floor(x) + {x}$.\ 如果一个实数 $x$ 可以被表示为 $x eq n + theta,space  "n is an integer and" 0 lt.eq theta lt 1$, 我们可以用 *(3.5(a))* 推出 $n = floor(x) "and" theta = {x}$.

- 恒等式*(3.6)*并不总是成立当 $n$ 是 "任意实数". 但是我们可以推断出在这个式子( $floor(x+y)$ )中只有两种情形:
$
  because x eq floor(x) + {x}, space y eq floor(x) + {y},\
  therefore floor(x+y) eq floor(x) + floor(y) + floor({x}+{y}),\
  because 0 lt.eq {x} + {y} lt 2,\
  therefore floor(x+y) = floor(x) + floor(y) "or" floor(x) + floor(y) + 1.
$

== #sym.section 3.2 Floor/Ceiling Applications 取整函数的应用
\
现在让我们进入应用阶段，这里有一个简单的问题：\
- $ceil(lg 35)"是多少？"$ (在这里，我们使用 '$lg$' 表示以 $2$ 为底的对数).
- 由于 $2^5 lt 35 lt.eq 2^6$, 我们同时取对数可以得到 $5 lt lg 35 lt.eq 6$; 所以根据*(3.5(c))*我们知道 $ceil(lg 35) = 6$.

我们知道 $35$ 在二进制下是 $6$ 位长的: $35=(100011)_2$. \ 
- 那么是不是 $ceil(lg n)$ 的答案总是 $n$ 在二进制下的位长？\
- 并不准确. 因为对于 $32$ 来说，我们也需要 $32=(100000)_2$ 共 $6$ 位来书写它.\
所以说这个答案实际上只在当 $n$ 是 $2$ 的幂时会出错，虽然看上去不多，但是这依旧有不可数个. 我们可以找到这个正确的答案当我们注意到我们可以用 $m$ 位来表示整数 $n$ 的时候需要满足 $2^(m-1) lt.eq n lt 2^m$; 由 *(3.5(a))* 我们知道 $m - 1 eq floor(lg n)$ ,所以 $m eq floor(lg n) + 1$. 而这正是我们想要的答案：
$
  "我们需要" floor(lg n) + 1 "位，来在二进制内表示" n, "对于所有" n gt 0.
$
我们也可以用一个类似的推导得到答案 $ceil(lg(n+1))$; 这个答案在 $n eq 0$ 的时候依旧成立.

让我们看看如果一个表达式里有多个上取整和下取整函数会怎么样？比如:
- $ceil(floor(x))$ 的值是？
- 这很好解决，因为 $floor(x)$ 一定是整数，所以 $ceil(floor(x))$ 就是 $floor(x)$.

这里有一个更加棘手的问题:
- 证明或证伪下面这个等式: 
$
  floor(sqrt(floor(x))) eq floor(sqrt(x)), space space "real" x gt.eq 0
$ *(3.9)*
- 当 $x$ 是整数的时候，这个式子显然成立，因为 $x eq floor(x)$, 当 $sqrt(x) lt.eq 1$ 的时候也成立，因为我们有 $1 eq 1$, 我们没有能成功找到反例，所以让我们尝试证明这个式子！
- 顺带说一嘴，当我们面临一个“证明或证伪”的问题时，我们更倾向于先去“证伪”，因为我们只需要找到一个反例即可，尽管这个猜想可能是正确的，我们在寻找反例的过程中，也总是会把我们牵引到证明它的道路上，同时我们也会发现构造一个反例是不可能的. 当然，始终保有怀疑的态度是有益的. 
- 当我们尝试证明这个式子的时候，我们可能会先考虑把 $x$ 切分成其的整数和小数部分 $floor(x) + {x} = n + theta$ 然后用二项式定理把这个式子的平方根扩展：
$
  (n + theta)^frac(1,2) eq n^frac(1,2)+frac(1,2)n^(-frac(1,2)) theta-frac(1,8)n^(-3/2) theta^2 + dots.h.c
$
但这就很复杂了 :(
- 如果使用我们刚发现的工具，会更加容易. 这里给出一个可能的策略：我们先设法去掉最外层的下取整和开平方，然后尝试去掉内层的下取整，最后把外面的东西都加回来.
- 我们令 $m = floor(sqrt(floor(x)))$ 然后应用 *(3.7(a))*, 得到 $m lt.eq sqrt(floor(x)) lt m+1$. 这样我们就去掉了外层的下取整，然后我们两边同时平方得到 $m^2 lt.eq floor(x) lt (m+1)^2$. 我们对于等式左边应用*(3.7(d))*, 右边应用*(3.7(a))*，于是我们得到了 $m^2 lt.eq x lt (m+1)^2$，后面的环节就很容易了，于是我们证明了这个式子，使用相似的方法，也可以证明：
$
  ceil(sqrt(ceil(x))) eq ceil(sqrt(x)), space space "real" x gt.eq 0
$
- 我们刚刚证明的式子仅仅只在平方根下满足，但是如果我们更深层次的看看呢？
- 我们令 $f(x)$ 是任意连续的，单增的函数，满足性质
$
  f(x) eq "integer"  #sym.arrow.r.double x eq "integer".
$
尝试证明：
$
  floor(f(x)) eq floor(f(floor(x))) "and" ceil(f(x)) eq ceil(f(ceil(x)))
$ *(3.10)*
- 我们知道，只需要证明上取整或下取整中的一个即可，因为两个证明几乎是一样的. 如果 $x = floor(x)$，显然成立. 如果 $x lt ceil(x)$，有 $f(x) lt f(ceil(x))$ 因为 $f$ 是增的. 因此 $ceil(f(x)) lt.eq ceil(f(ceil(x)))$ 因为上取整是增的. 如果 $ceil(f(x)) lt ceil(f(ceil(x)))$, 那么一定存在一个数字 $y$ 满足 $x lt.eq y lt ceil(x) $ 和 $ f(y) eq ceil(f(x))$ 因为 $f$ 是连续的. 这个 $y$ 一定是一个整数，因为 $f$ 的特殊性质. 但是因为一定不可能存在一个整数在 $x$ 和 $ceil(x)$. 所以一定有 $ceil(f(x)) eq ceil(f(ceil(x)))$.
\
- 这个定理有一个重要的特殊情形，值得明确指出来.
$
  floor((x+m)/n) eq floor((floor(x)+m)/n) space "and" space ceil((x+m)/n) eq ceil((ceil(x)+m)/n) 
$ *(3.11)*
- 如果 $m$ 和 $n$ 都是整数且分母是正的. 比如，当 $m eq 0$ 的时候，我们有 $floor(floor(floor(x div 10)div 10)div 10) eq floor(x div 1000)$. 我们就知道了，把一个数连续除以 $10$ 三次，每次扔掉小数部分，是等价于，直接除以 $1000$，然后扔掉其小数部分的.
- - 现在让我们尝试证明或证伪这个式子:
$
  ceil(sqrt(floor(x))) eq? ceil(sqrt(x)), space space "real" x gt.eq 0.
$
- 这个式子在 $x=pi$ 和 $x=e$ 的时候成立，但是在 $x=phi.alt$ 的时候不成立，所以我们知道这个式子不是普适的.
- 现在让我们讨论一下，要使这个式子成立的充要条件？
- - 我们已经发现，在 $x = 3.142$ 的时候成立，而 $x = 1.618$ 时就不成立；我们进一步尝试得到了当 $x in (9,10)$ 的时候就不成立. 是的，我们注意到，当 $m^2 lt x lt m^2+1$ 时，就会出现不符合要求的情况，因为此时左侧的取值为 $m$，而右侧的取值为 $m + 1$. #sym.space 在所有定义 $sqrt(x)$ 的情况下，即当 $x=0$ 或 $m^2+1 lt.eq x lt.eq (m+1)^2$ 时，我们的结果是成立（相等）的.
- - - 这些事实是这个式子的充要条件：要么 $x$ 是整数，要么 $sqrt(floor(x))$ 不是.
我们的下一个问题，我们一起来考虑一个实用的新记号，由 _C.A.R Hoare_ 和 _Lyle Ramshaw_ 提出，对于实数轴上的区间:
$
  (alpha, beta) space "双开区间-closed interval"\
  [alpha, beta] space "双闭区间-open interval"\
  [alpha, beta) space "左闭右开-half-open"\
  (alpha, beta] space "左开右闭-half-open"
$
> 有多少整数在这些区间中呢？\
- 好的，回到问题本身.对于整数而言，我们的问题很简单：$[alpha dots beta)$ 包含了整数 $alpha comma alpha + 1 comma dots comma beta-1$，假设 $alpha lt.eq beta$. 同样地如果是左开右闭也一样有 $beta-alpha$ 个整数，但是我们的问题更难一点，因为#sym.alpha 和#sym.beta 是任意整数，但是我们可以转化它：
$
  alpha lt.eq n lt beta arrow.l.r.double.long ceil(alpha) lt.eq n lt ceil(beta)\
  alpha lt n lt.eq beta arrow.l.r.double.long floor(alpha) lt n lt.eq floor(beta) 
$
- 当 $n$ 是整数时，我们用 *(3.7)* 化简出上式，我们可以很容易的得到，对于左闭右开，我们有 $ceil(beta)-ceil(alpha)$ 个整数；对于左开右闭，我们有 $floor(beta)-floor(alpha)$ 个整数.
- - - 这是一个我们乐意主动引入取整函数（符号）的例子，而不是化简掉它.
- > 你只需要记住：_ceiling for $[alpha dots beta)$ and floor for $(alpha dots beta]$._
相似的分析可以得到下面这个表，但是你要注意，对于双开区间，区间的下限和上限不能相等！
$
  [alpha dots beta] space.quad floor(beta)-ceil(alpha)+1 space.quad alpha lt.eq beta,\
  [alpha dots beta) space.quad space.quad ceil(beta)-ceil(alpha) space.quad space.third space alpha lt.eq beta,\
  (alpha dots beta] space.quad space.quad floor(beta)-floor(alpha) space.quad space.third space alpha lt.eq beta,\  
  (alpha dots beta) space.quad ceil(beta)-floor(alpha)-1 space.quad alpha lt beta.
$ *(3.12)*

这里就引入了一个新的问题：\
> “具体数学俱乐部”有个赌场（只有买了这本书的人才能进入xD），里面有个轮盘赌轮，有一千个空位，编号从 $1$ 到 $1000$ ，如果轮盘转到的数字能够被其立方根向下取整后的结果整除，形式化的讲 
$
  floor(root(3,n)) backslash n
$
那么认为其胜利，且庄家会支付我们5刀乐；否则我们就输了，且我们要支付1刀乐（译者：我也要给么 "哭脸.jpg"）.
- - - 在这里，我们认为 $a backslash b$ 表示整除，即 $b$ 是 $a$ 的因子（因数），其性质我们会在 _Cp4_ 详细探讨.
问题就是，我们能从这个游戏里大赚一笔么？！
  - 我们可以计算“平均获胜点”——也就是，我们每把会赢（或输）的钱（译者：是赢？还是输？！）——首先我们先假设 $W$ 是胜利数，$1000-W$就是败者数（译者：败者树！）. 如果在 $1000$ 局里我们认为每把都抽中一个格子，那么“平均打点”就是：
  $
    frac(5W-L,1000)eq frac(5W-(1000-W),1000)eq frac(6W-1000,1000).
  $
  - 也就是说，如果有超过 $167$ 个获胜的空位，那么闲家占优！；反之，庄家有优势.
  - 我们能够算出 $1$ 到 $1000$ 有多少个获胜的空位么？当然可以，我们可以列出下面这个算式
$
  W &= sum_(n=1)^1000 [n "is a winner"]\
  &=sum_(1<=n<=1000) [floor(root(3,n))backslash n] = sum_(k,n)[k=floor(root(3,n))][k backslash n][1<=n<=1000]\
  &= sum_(k,n,m)[k^3<=n<(k+1)^3][n=k m][1<=n<=1000]\
  &=1+sum_(k,m)[k^3<=n<(k+1)^3][1<=k<10]\
  &=1+sum_(1<=k<10)(ceil(k^2+3k+3+1/k)-ceil(k^2))\
  &=1+sum_(1<=k<10)(3k+4)=172.
$
- 这个分解需要注意的是，第五行的用了*(3.12)*的左闭右开区间内整数数量的分解. 总体而言，边界条件往往是 「$sum-$ 运算」中最关键的部分。
- 也就是说我们其实是能赚钱的，计算来看的话，我们每把可以获得 $(6 dot.c 172 - 1000)/1000$ 刀，也就是3.2美分。
- 这个问题实际上是另一个问题的包装版本：在1到1000内有多少整数满足 $floor(root(3,n)) backslash n$？数学上来说，我们确实认为两个问题无异，但是有时候把一个问题包装一下也不失为一个好想法。我们使用赢和输这样的词汇，很多时候可以让我们更好的理解问题的走向。
- 让我们更进一步，假设我们把1000变成1000000 ，或者更大的数字，$N$，有多少个满足的整数呢？
$
  K&=floor(root(3,N)).\
  W&=sum_(1<=k<K)(3k+4)+sum_m [K^3<=K m<=N]\
  &=1/2(7+3K+1)(K-1)+sum_m [m in[K^2dots N/K]]\
  &=3/2 K^2+5/2K-4+sum_m [m in[K^2dots N/K]]\
$
- 我们都知道剩下的那个大求和符号的结果是 $floor(N/K)-ceil(K^2)+1=floor(N/K)-K^2+1;$\ 因此我们得到
$
  W = floor(N/K) +1/2K^2+5/2K-3, space space space K=floor(root(3,N))
$ *(3.13)*\
这给出了 $N$ 以内的答案.
- 公式的前两项约为 $N^(2/3)+1/2N^(2/3)=3/2N^(2/3)$，其余项相比之下是相当小的，当 $N$ 很大时.
- 等到第九章的时候我们会学到，这个式子可以写作
$
  W = 3/2N^(2/3)+O(N^(1/3))
$
- 其中 $O(N^(1/3))$ 代表了一个不超过常数乘以 $N^(1/3)$ 的量. 不论常数是多少，我们都知道他是 $N$ 数量级的，可见这是一个成功的估计值.
- 估计后的公式是更好用的，因为他们比带有取整函数的公式要更加简洁.但是，精确的数据有时也是重要的，尤其当 $N$ 很小的时候，要注意估计的时机.
- 本章的最后一个应用，叫做谱；我们定义一个实数 $alpha$ 的 _spectrum_ 是下面这个公式，一个无限可重集
$
  "Spec"(alpha) = {floor(alpha),floor(2alpha),floor(3alpha),dots}.
$\
比方说，$1/2$ 的 spectrum 开头就是 ${0,1,1,2,2,3,3,dots}$
- 很容易证明不会有两个谱是相同的—— $alpha!=beta -> "Spec"(alpha)!="Spec"(beta)$. 因为，不妨设 $alpha < beta$，都存在一个正整数 $m$ 使得 $m(beta-alpha) >= 1$. 因此有 $m beta- m alpha >= 1$, 和 $floor(m beta) > floor(m alpha)$. 因此，在小于等于 $floor(m alpha)$ 的范围内，$"Spec"(beta)$ 的元素数小于 $m$ 个，$"Spec"(alpha)$ 至少有 $m$ 个.
- 这东西还有很多美丽的性质，让我们看下下面这两个例子:
$
  "Spec"(sqrt(2))&={1,2,4,5,7,8,9,11,12,14,15,16,18,19,21,22,24,dots},\
  "Spec"(2+sqrt(2))&={3,6,10,13,17,20,23,27,30,34,37,40,44,47,51,dots}.
$
- 对于上面的式子，我们使用计算器很容易就能算出来，然后对于下面这个式子的第 $n$ 项就仅仅比上面这个式子的第 $n$ 项多了 $2n$，由*(3.6)*推得.
- 如果再观察的细致一点，我们会发现一个更出乎意料的性质：全体正整数刚好是这两个东西的无交并(_disjoint union_). 我们就说这些谱，构成了正整数的一个「划分(_partition_)」.
- 为了证明这个断言，我们来数出对于前者和后者分别有多少个比 $n$ 小于等于的元素，然后看他们的总和是否是 $n$，对于每一个 $n$ 都满足的话，那么我们的确可以说两个谱构成了正整数的一个划分！
- 设 $alpha$ 是一个正数，那么在 $"Spec"(alpha)$ 中 $<=n$的元素数就是：
$
  N(alpha,n)&=sum_(k>0)[floor(k alpha)<=n]\
  &=sum_(k>0)[floor(k alpha) <n + 1]\
  &=sum_(k>0)[k alpha <n+1]\
  &=sum_k [0<k<(n+1)/alpha]\
  &=ceil((n+1)/alpha)-1.
$ *(3.14)*\
这个推导有两个值得注意的地方，第一个，他用了定理：
$
  m<=n arrow.double.l.r.long m<n+1, (m,n in ZZ)
$ *(3.15)*\
来把 '$<=$' 变成 '$<$'，所以下取整括号就可以被 *(3.7)* 消掉；同样地，但是这个更为精妙，我们使用 $k>0$ 代替了 $k>=1$，因为 $(n+1)/alpha$ 可能比 $1$ 小. 这样一来我们使用 *(3.12)* 的时候就可以直接使用双开区间的公式而不是被迫使用可能不满足情形的左闭右开公式.
- 肥肠好啊，我们现在有了 $N(alpha,n)$ 的公式. 现在我们可以测试两个谱是否是正整数的划分了，通过检测是否满足式子 $N(sqrt(2),n) + N(2+sqrt(2),n)=n,space n in ZZ_(>0)$ ，我们使用 *(3.14)*:
$
  &ceil((n+1)/sqrt(2))-1+ceil((n+1)/(2+sqrt(2)))-1=n\
  &arrow.l.r.long.double floor((n+1)/sqrt(2)) + floor((n+1)/(2+sqrt(2)))=n, space &"by (3.2)";&\
  &arrow.l.r.double.long (n+1)/sqrt(2) - {(n+1)/sqrt(2)} + (n+1)/(2+sqrt(2)) - {(n+1)/(2+sqrt(2))} = n, &"by(3.8)".
$ 
一切现在都得以简化，这归功于一个简洁的恒等式。
$
  1/sqrt(2)+1/(2+sqrt(2))=1;
$
现在我们的条件缩小了我们要证明的范围，那就是证明是否有下面的式子：
$
  {1/sqrt(2)}+{1/(2+sqrt(2))}=1; space n in (0,+infinity)
$
然后我们就胜利了，证明出了这两个谱是正整数的一组划分！

== #sym.section 3.3 FLOOR/CEILING RECURRENCES 取整函数的递归表示
- 取整函数给了我们一个新的有意思的方面去研究递归关系，让我们先看一下下面这组递归：
$
  K_0 &=1;\
  K_(n+1) &=1+min(2K_(floor(n/2)),3K_(floor(n/3))), space "for" n >=0.
$ *(3.16)*\
举个例子，这个式子开始是 $1,3,3,4,7,7,7,9,9,10,13,dots$.\ 本书的一位作者谦逊地决定将这些数命名为「克努特数」.
- 「_Exercise 25_」问了一个证明或证伪，是否有对于 $n>=0, "总有" K_n >= n$. $K$ 的前几个项似乎是满足这个推论的，所以我们尝试证明他是对. 让我们尝试用归纳法证明：当 $n=0$ 时，递归式可以直接给出结果. 在归纳的步骤里，我们假设该不等式对所有不大于某个固定非负整数 $n$ 的值均成立，然后尝试证明 $K_(n+1) >=n+1$. 归纳假设告诉我们 $2K_(floor(n/2)) >= 2floor(n/2)$ 以及 $3K_(floor(n/3)) >= 3floor(n/3)$. 但是，$2floor(n/2)$ 可以比 $n-1$ 小，$3floor(n/3)$ 也可以比 $n-2$ 小. 我们唯一可以总结出的就是 $K_(n+1) >= 1 + (n-2);$ 这与 $K_(n+1)>=n+1$ 相差甚远！
- 现在我们开始担心是否都有 $K_n>=n$ 了，所以让我们尝试证伪它！如果我们可以找到一个 $n$ 有 $2K_(floor(n/2))<n$ 或者 $3K_(floor(n/3))<n$ ，或者换一个写法：
$
  K_(floor(n/2))<n/2 "或者" K_(floor(n/3))<n/3,
$
我们就会有 $K_(n+1)<n+1$. 这可能么？我们最好不在这里继续了，因为这可是 「_Exercise 25_」！
- 包含取整函数的递归关系在计算机科学中非常常见，因为基于“分治法”这一重要技术的算法，常常能将规模为 $n$ 的问题，转化为求解规模为 $n$ 的某个分数倍的整数子问题。例如，有一种对于 $n$ 个记录排序的算法，对于 $n>1$ 时，我们把它分成两部分，就有下面的式子:
$
  n=ceil(n/2)+floor(n/2)
$ *(3.17)*\
顺便说一嘴，这个式子非常常用. 我们在归并的过程中，每一次都要分开他们然后用 $n-1$ 次合并他们，就有这个递归式子：
$
  f(1)&=0;\
  f(n)&=f(ceil(n/2))+f(floor(n/2))+n-1, space space "for" n > 1.
$ *(3.18)*\
这个式子的结果就是 「_Exercise 34_」.
- 第一章的约瑟夫问题也有一个类似的递归版本，也可以写成下面这样：
$
  J(1)&=1;\
  J(n)&=2J(floor(n/2))-(-1)^n, space space "for" n>1.
$
我们现在比第一章拥有了更多的工具！那么，让我们来考虑更「真实」的约瑟夫问题：即每三个人淘汰一个，而不是每两个人淘汰一个. 如果我们对于现在这个问题运用和第一章相同的方法的话，我们会得到这个式子：
$
  J_3(n)=(ceil(3/2J_3(floor(2/3n))+a_n) mod n) + 1,
$
但是这个递归关系继续下去会很糟糕.
- 这里有一个别的方式来开始这个问题，给了我们一个更好的开局方式. 当有一个人G了的时候，我们定义一组新的编号. 因此，1和2变成了n+1和n+2，然后3被淘汰了；4和5变成n+3和n+4,然后6被淘汰；#sym.dots ；3k+1和3k+2变成了n+2k+1和n+2k+2，然后3k+3被淘汰；#sym.dots 然后3n被淘汰（或者是最后幸存的）.
- 第 $k$ 个完蛋的哥们会以 $3k$ 编号结尾. 因此，只要能确定原始人数为 $3n$ 时的对应编号，我们就能推算出幸存者是谁。
- 如果 $N>n$，编号是 $N$ 的人一定会有一个之前的编号，我们可以通过以下方式来寻找：我们有 $N=n+2k+1$ 或 $N=n+2k+2$，因此 $k=floor((N+n-1)/2)$; 前一个编号是 $3k+2$ 或 $3k+1$. 那么就是 $3k+(N-n-2k)=k+N-n.$ 所以我们可以计算出来幸存者编号 $J_3(n)$ 以以下方法：
$
  &N := 3n;\
  &"while" N>n "do" N:=floor((N-n-1)/2)+N-n;\
  &J_3(n):=N.
$
这并不是闭合形式的 $J_3(n)$ 公式，甚至不能算作是一个递归式，但至少这东西能告诉我们如何在 $n$ 很大的情形下算出答案.
- 有幸的是这里有一个方法简化这个算法如果我们使用 $D=3n+1-N$ 来代替 $N$. （这一记法的变化相当于从 $3n$ 向下到 $1$ 分配编号，而不是从 $1$ 向上到 $3n$ —— 有点像倒计时。）:
$
  D :&= 3n+1-(floor(((3n+1-D)-n-1)/2)+(3n+1-D)-n)\
  &=n+D-floor((2n-D)/2) = D-floor(-D/2)=D+ceil(D/2)=ceil(3/2D),
$
然后我们就可以重写这个算法：
$
  &D:=1\
  &"while" D<=2n "do" D:=ceil(3/2D);\
  &J_3(n):=3n+1-D.
$
啊哈！这样看起来好多了，因为这样以来，$n$ 在这个式子里就是简单的了，我们同理也可以得到 $J_q (n)$ 的计算法了：
$
  &D:=1\
  &"while" D<=(q-1)n "do" D:=ceil(q/(q-1)D);\
  &J_q (n):=q n+1-D.
$ *(3.19)*\
根据 *(3.19)* 中的方法，可计算出一个整数序列，该序列可通过以下递推关系定义：
$
  D_0^((q)) &= 1;\
  D_n^((q)) &= ceil(q/(q-1) D_(n-1)^((q))) space space space "for" n>0.
$ *(3.20)*\
这些整数看起来没有任何可以通过简单函数描述出来的关系，除了当 $q=2$ 时；因此它们很可能没有一个美妙的闭合形式！但是如果我们乐意认为 $D_n^((q))$ 是 「已知的」 的话，那么就很容易使用变种约瑟夫问题来描述这个结果：幸存者 $J_q(n)$ 是 $q n+1-D_k^((q))$，当 $k$ 是足够小的如 $D_k^((q))>(q-1)n$.

== #sym.section 3.4 'MOD': THE BINARY OPERTION mod：二元运算
- $n$ 除以 $m$ 的商是 $floor(n/m)$，其中 $m$ 和 $n$ 都是正整数。对于其的余数，我们也有一个方便的记录法，我们管它叫 $n mod m$。于是我们有一个简单的公式：
$
  n = m floor(n/m) + n mod m
$
- 这告诉我们我们可以用 $n - m floor(n / m)$ 来表示 $n mod m$。我们也可以推广其至负数，使其在完整的实数域上都有：
$
  x mod y = x - y floor(x/y), space space "for" y != 0.
$ *(3.21)*
- 这定义了取模是一个二元运算，就如同加法和减法一样也是二元运算。数学家们非正式的以这种方式使用取模运算用了很长一段时间，但直到最近二十年，它才在形式上流行起来。旧概念，新符号。
- 我们可以直观的理解 $x mod y$，当 $x$ 和 $y$ 是正整数时，如果我们想象这里有一个圆圈代表 $y$，上面均匀的表示着 $[0,y)$ 这个区间内的数。如果我们在上面移动 $x$ 距离，从 $0$ 开始，那么我们会在 $x mod y$ 处结束，且经过 $0$ 的次数刚好是 $floor(x/y)$ 次。
- 当 $x,y$ 是负的时候，我们需要仔细的看看定义了，这里给出几个例子：
$
  5 mod 3 &= 5 - 3 floor(5/3) &= 2;\
  5 mod -3 &= 5-(-3)floor(5/(-3))&=-1;\
  -5mod 3 &= -5-3floor(-5/3)&=1;\
  -5mod -3 &= -5 - (-3)floor(-5/(-3)) &= -2;\
$
- 在 $mod$ 符号后面那个数叫 「模数」；前面那个数还没有一个确定的说法。在实际应用中，模数往往是正的，但是定义上，负的模数应用起来也很完美，有下面这个性质：
$
  0 <= x mod y < y, "for" y > 0;\
  0 >= x mod y > y, "for" y < 0.
$
- 那 $y=0$ 时怎么办呢？特别的我们有： $x mod 0 = x.$ *(3.22)*
- 这个约定保留了如下性质： $x mod y$ 总是与 $x$ 相差 $y$ 的倍数。
- 当我们把 $x$ 表示为他的整数部分和小数部分的时候，$x = {x}+floor(x)$。小数部分也可以写作 $x mod 1$, 因为我们有：
$
  x = floor(x) + x mod 1.
$
- 注意我们没有用括号来改变优先级，我们定义取模运算的优先级高于加法和减法。
- 可以看到我们使用了下取整来定义取模，那么上取整呢？实际上我们也可以定义一个类取模运算：
$
  x "mumble" y = y ceil(x/y) - x;
$
- 在我们的走圆圈比喻中，这个值就是当我们走了 $x$ 距离后，还要走多少才能回到 $0$ 位置的值。
- 分配率是取模运算最重要的代数性质：我们有
$
  c(x mod y) = (c x)mod(c y), space space c,x,y in RR  
$ *(3.23)*
- 使用 *(3.21)* 很容易证明他：
$
  c(x mod y) = c(x - y floor(x/y)) = c x - c y floor((c x) / (c y)) = c x mod c y,
$
- 这和孙子定理也有一定的联系，或称「中国剩余定理(CRT)」。
- 因此，我们可以列出一个恒等式，把 $n$ 拆分成 $m$ 个尽可能均匀的非递增项：
$
  n = ceil(n/m)+ceil(frac(n-1,m))+dots+ceil(frac(n-m+1,m)).
$ *(3.24)*
- 这个恒等式成立当 $m$ 是正整数，$n$ 是全体整数时。其实我们在 *(3.17)* 的时候就见到另一个形式的它了，$n=ceil(n/2)+floor(n/2)$.
- 如果我们想要一个均匀的非递减项，也有一个类似的式子：
$
  n = floor(n/m)+floor(frac(n+1,m))+dots+floor(frac(n+m-1,m)).
$ *(3.25)*
- 这两个式子可以用 *(3.4)* 来转换，或者使用 「_exercise 12_」 的解法转换。
- 如果我们用 $floor(m x)$ 来代替 $n$ 呢？使用 *(3.11)* 可以得到一个对于全体实数 $x$ 都成立的恒等式：
$
  floor(m x) = floor(x) + floor(x + 1/m) + dots + floor(x + (m-1)/x).
$ *(3.26)*
- 这个式子可太牛逼了，因为下取整实际上是一个整数估计值，但是左右两边的估计值的和居然惊人的刚好相同了！
== #sym.section 3.5 FLOOR/CEILING SUMS 取整函数的求和
- 等式 *(3.26)* 展示了对于至少引入了一个下取整的式子，我们是可能得到一个封闭形式的。那么有别的么？当然！在这种情况下通常有效的技巧是，通过引入一个新变量来去掉取整符号。
- 举个例子，让我们看看对于这个求和怎么办：$ sum_(0<=k<n) floor(sqrt(k)) $
- 一个思路是设 $m = floor(sqrt(k))$；然后我们就可以机械的处理这个问题，就像我们在之前的轮盘赌问题里做的一样：
$
  sum_(0<=k<n) floor(sqrt(k)) &= sum_(k,m>=0) m[k<n][m=floor(sqrt(k))] \
  &= sum_(k,m>=0) m[k<n][m<=sqrt(k)<m+1]\
  &= sum_(k,m>=0) m[k<n][m^2<=k<(m+1)^2]\
  &= sum_(k,m>=0) m[m^2<=k<(m+1)^2<=n] +
  sum_(k,m>=0) m[m^2<=k<n<(m+1)^2].
$
- 让我们先假设 $n = a^2$ 是一个完全平方，这样第二个式子就是 $0$ 了，然后我们就可以继续化简：
$
  sum_(k,m>=0) &m[m^2<=k<(m+1)^2<=a^2]\
  &= sum_(m>=0) m((m+1)^2-m^2)[m+1<=a]\
  &= sum_(m>=0) m(2m+1)[m<a]\
  &= 2/3a(a-1)(a-2)+3/2a(a-1) = 1/6(4a+1)a(a-1).
$
- 我们可以再令 $a = floor(sqrt(n))$；然后我们仅仅只需要添加对应于 $a^2 <= k < n$ 的项，这些刚好和 $a$ 相等，所以他们的和就等于 $(n-a^2)a$。这就给了我们一个封闭形式： $ sum_(0<=k<n) floor(sqrt(k)) = n a-1/3a^3-1/2a^2-1/6a, space space a = floor(sqrt(n)). $ *(3.27)*\
- 另一个类似的写法是把所有形如 $floor(x)$ 的项替换成 $sum_j [1<=j<=x]$；但这只在 $x>=0$ 时合法。下面给出推导：
$
  sum_(0<=k<n) floor(sqrt(k)) &= sum_(j,k) [1<=j<=sqrt(k)][0<=k<a^2]\
  &= sum_(1<=j<a)sum_(k) [j^2<=k<a^2]\
  &= sum_(1<=j<a) (a^2-j^2) = a^3 - 1/3a(a+1/2)(a+1).
$
- 现在来看另一个例子，其中通过变量替换可以转换求和形式。一个出色的理论被三个数学家于1909年独立发现——（ _Bohl[34],Sierpinski[326],Weyl[368]_ ）；如果 $alpha$ 是无理数且其小数部分 ${n alpha}$ 在 $0$ 到 $1$ 上均匀分布，当 $n -> infinity$ 时。： $ lim_(n->infinity) 1/n sum_(0<=k<n) f({k alpha}) = integral_0^1 f(x) d x $ *(3.28)*\
对于所有无理数 $alpha$ 和所有有界函数 $f$ 在几乎处处连续下。举个例子，${n alpha}$ 的平均值可以被这样找到，设 $f(x) = x$；我们会得到 $1/2$ （这正是我们预想的，无论无理数 $a$ 是多少）
- 这个理论被改进了，通过「阶梯函数」从上方和下方逼近 $f(x)$，他们是简单函数的线性组合 $ f_v(x)=[0<=x<v] $
当 $0<=v<=1$。我们这里的目的不是证明这个定理；这是其他书干的事情。但是让我们尝试去找一找其成立的最基本原因，通过观察他在这个特殊例子下运作的如何：$f(x)=f_v(x)$。换句话说，让我们试试这个求和式子 $ sum_(0<=k<n) [{k alpha}<nu] $
与理想的值 $n nu$ 相差多少，当 $n$ 是足够大且 $alpha$ 是无理数.
- 为此，我们定义「差异」 $D(alpha, n)$ 是对于所有 $0 <= nu <= 1$ 范围内求和的最大绝对值 $ s(alpha,n,nu) = sum_(0<=k<n) ([{k alpha} < nu]-nu) $ *(3.29)*\
我们的目标是展示 $D(alpha, n)$ 相较于 $n$ 是 「并不大」 的，通过计算 $|s(alpha,n,nu)|$ 总是 「相当小的」 当 $alpha$ 是无理数。我们可以不失一般性地假设$0<alpha<1$。
- 第一件事我们可以先重写 $s(alpha,n,nu)$ 用一个更简单的形式，我们引入一个新的索引变量 $j$:
$
  sum_(0<=k<n) ([{k alpha}<nu]-nu) &= sum_(0<=k<n) (floor(k alpha) - floor(k alpha - nu) - nu)\
  &= -n nu + sum_(0<=k<n) sum_j [k alpha - nu < j <= k alpha]\
  &= -n nu + sum_(0<=j<ceil(n alpha)) sum_(k<n) [j alpha^(-1) <= k < (j + nu)a^(-1)].
$
如果我们足够幸运，我们可以对 $k$ 求和，但是我们应该引入一些新的变量，这样公式不会变得乱糟糟，所以我们有：
$
  a &= floor(alpha^(-1)), space space space space &alpha^(-1) &= a + a^';\
  b &= ceil(nu alpha^(-1)), &nu alpha^(-1) &= b - nu^';
$
因此 $a'={a^(-1)}$ 是 $a^(-1)$ 的小数部分，然后 $v'$ 是 $nu alpha^(-1)$ 的分数部分。
- 边界条件再次成为我们唯一的困扰来源。所以，让我们忘掉 '$k<n$' 的限制，先来尝试计算 $k$ 的值！:
$
  sum_k [k in [j alpha^(-1)..(j+nu)alpha^(-1))] &= ceil((j+nu)(a+alpha')) - ceil(j(a+alpha'))\
  &= b + ceil(j alpha' - nu') - ceil(j alpha').
$
好的！现在就看起来很简单了吧，我们将其代入并逐步推导:
$
  s(alpha,n,nu)=-n nu + ceil(n alpha)b + sum_(0<=j<ceil(n alpha)) (ceil(j alpha'-nu')-ceil(j alpha')) - S,
$ *(3.30)*\
其中 $S$ 是对我们未能排除的 $k >= n$ 情况的修正。其中有理数 $j alpha'$ 只在 $j = 0$ 时是整数，因为 $alpha$ 是无理数；而且 $j alpha' - nu'$ 只会在至多对应一个 $j$ 时是整数。所以我们可以把上取整改成下取整。
$
  s(alpha,n,nu) = -n nu + ceil(n alpha) b - sum_(0<=j<ceil(n alpha)) (floor(j alpha')- floor(j alpha'- nu')) - S + {0 "or" 1}.
$
有意思。并非化成封闭形式，我们把这个求和用好多不同的符号替代了，我们可能更想得到：
$
  s(alpha',ceil(n alpha),nu') = sum_(0<=j<ceil(n alpha)) (floor(j alpha')-floor(j alpha'-nu')-nu')
$
为了这步操作
$
  s(alpha,n,nu) = -n nu + ceil(n alpha)b - ceil(n alpha) nu' - s(alpha', ceil(n alpha),nu')-S+{0 "or" 1}.
$
回顾我们有 $b-nu'=nu alpha^(-1)$，我们可以看到当我们把 $ceil(n alpha)(b - nu')$ 以 $n alpha(b - nu') = n nu$ 替换后，一切都会非常美丽！
$
  s(alpha,n,nu) = -s(alpha', ceil(n alpha), nu') - S + epsilon + {0 "or" 1}.
$
在这里 $epsilon$ 是一个比 $nu alpha ^ (-1)$ 小的正误差。 「 _Exercise 18_ 」 证明了 $S$ 是介于 $0 "和" ceil(nu alpha^(-1))$ 之间的，然后我们可以用 $j = ceil(n alpha) - 1 = floor(n alpha)$ 化简和式，我们就有:
$
  D(alpha, n) <= D(alpha', floor(alpha n)) + alpha^(-1) + 2.
$ *(3.31)*\