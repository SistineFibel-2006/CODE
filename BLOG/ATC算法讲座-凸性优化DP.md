## 凸数列的 `min-plus` 卷积 （未完结）

Atcoder Algorithm Lectures 难度评级 4 / 10

原文： [凸数列的 min-plus 卷积 - AtCoderInfo --- 凸数列の min-plus 畳み込み - AtCoderInfo](https://info.atcoder.jp/entry/algorithm_lectures/min_plus_convolution)

原解说视频链接： https://youtu.be/VnFJxcYBugU

> [!tip]
>
> 本文是原文的翻译与扩展，具体的扩展内容是后续例题的题解与讲解，译者水平有限，可能有些许错误，还望海涵，也可与文章作者联系并提出建议与指出错误！


### 1.概述

对于两个整（实）数序列 $A=(A_0, A_1, \dots, A_N), \ \ B=(B_0, B_1, \dots, B_M)$, 由他们得到的新序列 $C = (C_0, C_1, \dots, C_{N + M})$ 满足：$C_k = \min_{i+j=k} (A_i + B_j)$  被叫做 **A与B的 min-plus** 卷积.

当两个序列其中一方有 **凸性** 的时候，我们可以高效的进行这个卷积运算，而本文只讲解最简单的情况——两者均有凸性时的运算.

### 2.预备知识

无特别需要的前置知识，只会讲解基础的动态规划.

### 3.凸数列

> [!note]
>
> **【定义 1】**
>
> 对于一个数列 $A=(A_0, A_1, \dots, A_N)$ 与任意的下标 $i\in [0, N - 1)$，都有不等式 $A_{i+1}- A_i \leq A_{i + 2} - A_{i + 1}$ 成立，我们就称 $A$ 是 **下凸（Convex Below）** 的；如果都有不等式 $A_{i+1}- A_i \ge A_{i + 2} - A_{i + 1}$ 成立，我们就称 $A$ 是 **上凸（Convex Above）** 的. 
>
> 上凸也被叫做凹，下凸也被叫做凸.

##### 3.1. 具体例子

如果对于数列 $A$，我们画出其散点相联结的 **折线图**.

下凸的条件其实就对应了折线图中 **斜率广义单增（单调不递减）** 的性质.

这里给出几组凸数列的例子，可以对照观看:

- $A=(0,0,0,1,2,4) $是下凸的，不是上凸的.
- $B=(4,1,0,1,4)$ 是下凸的，不是上凸的.
- $C=(0,2,4,5,5,4)$ 是上凸的，不是下凸的.
- $D=(4,3,2,1,0)$ 既是下凸的，也是上凸的.
- $E=(1)$ 既是下凸的，也是上凸的.
- $F=(3,1,3,0,2)$既不是下凸的，也不是上凸的.

![img](https://img.atcoder.jp/aal-image-library/d497019e37bca8837eb1da8f54b0273f.png)

![img](https://img.atcoder.jp/aal-image-library/e9aec0a6c254784a924923b9c64f30a3.png)

### 4. 凸数列的 `min-plus` 卷积

#### 4.1. 数列的 `min-plus` 卷积

> [!note]
>
> **【定义 2】**
>
> 对于两个整（实）数序列 $A=(A_0, A_1, \dots, A_N), \ \ B=(B_0, B_1, \dots, B_M)$, 由他们得到的新序列 $C = (C_0, C_1, \dots, C_{N + M})$ 满足：$ C_k = \min_{i+j=k} (A_i + B_j)$  被叫做 **A与B的 min-plus** 卷积   （**min-plus convolution**）.

例如，当 $A = (5,1,4,2,2)$ 与 $B = (1,3,2)$ 时，他们的 `min-plus` 卷积就是： $C=(6,2,4,3,3,4,4)$.

![image-20260603141002158](C:\Users\XK\Desktop\BLOG图片\image-20260603141002158.png)

也就是这个图片里面，斜着取每一斜线最小值. （当然对于第三个数，不取 (3,1) 位置的 4 而是取 (2, 2) 位置的 4 也是等价的，这里为了保证都先按照列优先取）

这也正是 `min-plus convolution` 用定义算的方法，复杂度显然是 $O(N \cdot M)$ 的.  根据参考文献，在一般情况下，我们认为很难实现大幅度的加速 （当 $\epsilon > 0$ 时，预计无法在 $O((N \cdot M)^{1-\epsilon})$ 时间内求解）.

#### 4.2. 下凸（凸）序列的 `min-plus` 卷积

不妨设 $A, B$ 是凸序列，我们旨在证明这些序列的 `min-plus` 卷积相关性质.

> [!IMPORTANT]
>
> **【定理 3】**
>
> 当 $A=(A_0,A_1,\dots,A_N), \ \  B=(B_0,B_1,\dots,B_N)$ 都是凸序列的时候，他们两个的 `min-plus` 卷积可以在 $O(N + M)$ 时间内计算.  此外，卷积得到的新序列也是凸的.

因为我们有序列的增量单调不递减，所以我们不妨设 $A_0=0, B_0=0$，如果证明在这个条件下成立，那么自然可以推广到首项不为 $0$ 的情况.

我们设 $A, B$ 的**增量序列**（也可称 **差分序列**）是 $a, b$.  也就是 $a_i=A_{i+1}-A_i, \ \ b_j = B_{j+1}-B_j$，我们也可以用一个形象的例子来解释 $A_i, B_j$ :

- 假设袋子 A 中有 $N$ 个物品，其价值为 $a_0, a_1, \dots, a_{N-1}$ 。 $A_i$ 是从这些物品中总共选择 $i$ 个时，总价值的最小值.

- 假设袋子 B 中有 $N$ 个物品，其价值为 $b_0, b_1, \dots, b_{N-1}$ 。 $B_i$ 是从这些物品中总共选择 $i$ 个时，总价值的最小值.

因为我们定义了 $A, B$ 是凸函数，所以这里 $a, b$ 是  **广义单增** 的，因此他们的 `min-plus` 卷积可以这样解释：

- $A_i + B_j$ 是从袋子 A 中选择 $i$ 个物品、从袋子 B 中选择 $j$ 个物品时候，总价值的最小值.
- $C_k = \min_{i+j=k} (A_i+B_j)$ 就是从袋子 A 与 B 总共选取 $k$ 个物品时候，总价值的最小值.

将 $A_0$,$B_0$ 一般化后，可以发现 `min-plus` 卷积可以按如下方式计算

- 设 $a_i=A_{i+1}-A_i, \ \ b_j = B_{j+1}-B_j$
- 把这些合并后升序排序，记为 $c_0, c_1, \dots, c_{N+M-1}$
- 这个时候就有 $C_k = (A_0+B_0) + \sum_{i=0}^{k-1} c_i$

这里有合并后升序排序的操作，但是因为 $a, b$ 都是广义单增的，所以可以用 $O(N + M)$ 算出来！通过取前缀和，$A, B$ 的 `min-plus` 卷积可以在 $O(N + M)$ 的时间内算出来.

同样地，$C$ 的凸性质也很好证明，因为 $C_k$ 的差分序列显然也是广义单增的. ■ 

##### 图解

$A = (2,0,0,1,2)$ 与 $B=(0,0,1,3)$ 做 `min-plus` 卷积的结果 $C = (2,0,0,0,1,2,3,5)$

![img](https://img.atcoder.jp/aal-image-library/14cad83469bb3d52d82cc153239d0c2c.png)

##### 提醒

同样地，如果两个序列都是凹序列，那么同样可以适用 `max-plus` 卷积， **【定理 3】** 也同样成立.

#### 4.3. 实现例子

可以在这里尝试这个模板： [Library Checker](https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex)

- 与上文相同的实现： https://judge.yosupo.jp/submission/347758

- 与上文本质相同的实现，但是隐式计算了差分序列： https://judge.yosupo.jp/submission/320371

```cpp
// maspy 的代码，即 [链接1] 中的代码
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a) for (int i = 0; i < (a); ++i)
template <typename T>
using vc = vector<T>;

void solve() {
  int N, M;
  cin >> N >> M;
  vc<int> A(N), B(M);
  FOR(i, N) cin >> A[i];
  FOR(j, M) cin >> B[j];

  int c0 = A[0] + B[0];
  vc<int> a(N - 1), b(M - 1);
  FOR(i, N - 1) a[i] = A[i + 1] - A[i];
  FOR(j, M - 1) b[j] = B[j + 1] - B[j];

  vc<int> c(N + M - 2);
  // also works:
  // merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
  {
    int i = 0, j = 0;
    for (int k = 0; k < (N + M - 2); ++k) {
      if (j == M - 1 || (i < N - 1 && a[i] < b[j])) {
        c[k] = a[i++];
      } else {
        c[k] = b[j++];
      }
    }
  }

  vc<int> C(N + M - 1);
  C[0] = c0;
  for (int k = 0; k < N + M - 2; ++k) C[k + 1] = C[k] + c[k];

  for (int i = 0; i < N + M - 1; ++i) {
    if (i) cout << " ";
    cout << C[i];
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
```

### 5. 利用差分序列加速 DP

在算法竞赛中，经常有可以用 `min-plus` 卷积表示的 DP.  此时，不仅需要理解 `min-plus` 卷积可以在线性时间内计算，还需要理解它相当于差分序列的合并，从而可能实现 DP 的加速.

让我们看看下面这个题：

>**【问题 4】**
>
>给定整数序列 $A = (A_1, A_2, \dots, A_N)$ ，对于每个 $k = 0, 1, \dots, N$，求出从 $A$ 中刚好取出 $k$ 个元素的时候，其总和可能的最小值.

诚然这个题很无聊，其实排个序然后前缀和就结束了，时间复杂度是 $O(N\cdot \log N)$ 的.

另一方面，这个题其实也可以考虑用 DP 来求解： 设 $dp[i] = $ 恰好选择 $i$ 个元素时候的最小总和，然后逐步添加新的 $A_i$ 来更新 DP 表，例如下面这个：

```cpp
vector<int> dp = {0};
const int INF = INT_MAX / 4;
for (int x : A) {
  vector<int> newdp(dp.size() + 1, INF);
  for (int i = 0; i < dp.size(); ++i) {
    newdp[i] = min(newdp[i], dp[i]);          // not use x
    newdp[i + 1] = min(newdp[i + 1], dp[i] + x);  // use x
  }
  swap(dp, newdp);
}
```

这是  $ Θ(N^2)$ 的，乍一看好像很难变成 $O(N \cdot \log N)$ 的.

实际上这个 DP 也是一个 `min-plus` 卷积，如果我们把数列 $B = (0, A[i])$ 的话，其实就会发现，$newdp$ 本质上就是 $dp$ 与 $B$ 的 `min-plus` 卷积.  所以说，如果理解了凸序列的 `min-plus` 卷积其实就是差分序列的合并，那么从这个 DP 解法中可以看出：

- DP 表始终是下凸的.
- 考虑差分序列的时候，DP 表的更新实际上就是插入 $A[i]$ （或者说代码里的 $x$）这个操作.

这样实际上可以推导出与贪心法相同的解法，从 DP 推导出的.

当然这个例子过于简单了，可能很难以理解 `min-plus` 卷积的用处，下面还有新的一些题目:

### 6.相关问题

1. https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
2. https://atcoder.jp/contests/abc407/tasks/abc407_e
3. https://atcoder.jp/contests/joisp2025/tasks/joisp2025_l
4. https://codeforces.com/contest/2179/problem/E
5. https://www.openjudges.com/p/P10641
6. https://codeforces.com/contest/2079/problem/B

### 7.总结

本文通过简单的贪心算法，推导了凸序列的 `min-plus` 卷积算法。理解其机制后，不仅能计算给定凸序列的 `min-plus` 卷积，还能通过巧妙管理序列，推导出更进阶的解法。特别是当动态规划解法呈现为 `min-plus` 卷积形式时，通过将数据存储方式改为保持差序列，可以实现加速，请留意这一点。

本文内容还与（以实数为定义域的）凸函数的卷积、`slope trick`、凸图形的 `Minkowski` 和等概念相关联。此外，关于仅单侧数列具有凸性时的 `min-plus` 卷积，也计划在未来进行讲解.

### 8.参考文献

1. errorgorn．[Tutorial] Knapsack, Subset Sum and the (max,+) Convolution．Codeforces Blog．https://codeforces.com/blog/entry/98663．（閲覧日: 2026-03-31）．
2. Marek Cygan, Marcin Mucha, Karol Węgrzycki, Michał Włodarczyk．On Problems Equivalent to (min,+)-Convolution．ACM Transactions on Algorithms．Vol. 15．No. 1．pp. 1–25．2019．DOI: 10.1145/3293465．https://doi.org/10.1145/3293465．



### 补充：

#### 习题2:  https://atcoder.jp/contests/abc407/tasks/abc407_e

考虑 $dp[i] =  $ 比目前至少需要的左括号数量多 $i$ 个左括号时候的最优解收益.

这样的话 

- $newdp[i] = \max(dp[i], dp[i - 1] + a)$
- 从 DP 表删除第一个元素，因为所至少需要的左括号会 $+ 1$

第一个操作就是下面这两个序列的 `max-plus` 卷积：

- $dp$
- $[0, a]$ （$a$就是当前的权值 $A_i$ ）

因为 DP 表始终是上凸的，所以考虑折线图，相当于

- 插入一条斜率为 $a$、$x$ 宽度为 $1$ 的线段. 
- 删除左边斜率最大的线段.

这样一来，使用 priority_queue 维护这一操作并不断更新就可以了.

```cpp
void Mainsol() {
	INT(N);
	priority_queue<ll> pq;
	VEC(ll, A, 2 * N);
	ll sum = 0;
	rep(i, 2 * N) {
		pq.push(A[i]);
		if(i % 2 == 0) { // 新的一组转移
			sum += pq.top();
			pq.pop();
		}
	}
	out(sum);
}
```

本质就是每两步不断取能取的最大增量，这样既可以保证串本身合法，也能保证增量前缀最大化，换句话说，整体满足凸性.

#### 习题3：https://atcoder.jp/contests/joisp2025/tasks/joisp2025_l

本题不能使用 `min-plus` 卷积取得满分，但也可以取得相对不错的分数





