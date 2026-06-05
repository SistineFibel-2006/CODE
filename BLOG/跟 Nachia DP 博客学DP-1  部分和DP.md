### 跟 Nachia DP 博客学DP-1 : 部分和DP

Nachia 原文： [DP 的俗称 | Mathenachia --- DP の俗称 | Mathenachia](https://www.mathenachia.blog/dp/)

> 给定序列 $A = (a_1, a_2, \dots, a_N)$ 与非负整数 $S$.
>
> 询问是否存在一个下标集合 $Set$，使得 $\sum_{i \in Set} a_i = S$

这个问题是**部分和DP**的标准形式！状态可以这样设计：

> [!tip]
>
> $ dp[n][s] = $ （当 $A = (a_1, a_2, \dots, a_N)$，$S = s$ 的时候的部分和问题的解.
>
> 其中 ($0 \leq n \leq N, 0 \leq s \leq S$)

通常这个二维数组的元素是布尔值，所以可以再添加维度，来扩展其额外信息！

转移过程往往是考虑从第 $i - 1$ 个数字的所有可达部分和转移到第$i$个数字的所有可达部分和的，这个部分并不难思考！



#### 例题：

这里先给出两个例题链接！想先思考一下的可以先不看下面的题解！

1 . [ATC abc286D - Money in Hand](https://atcoder.jp/contests/abc286/tasks/abc286_d)  **EASY** 板子题

2.[ATC abc275F - Erase Subarrays](https://atcoder.jp/contests/abc275/tasks/abc275_f)  **MID+**

------
------


### 题目讲解

1 . [ATC abc286D - Money in Hand](https://atcoder.jp/contests/abc286/tasks/abc286_d)

 其实就是部分和 DP 模板

考虑如何转移，对于第 $i$ 个数字，有两种情况，首先 $a_i$ 本身可以达到，所以 $dp[i][a_i] = true$，然后考虑从 $i - 1$ 个数字转移，对于每一个在 $i - 1$ 层是 $true$ 的点，都可以有转移 $dp[i][* + a_i] = true,\ \  \because dp[i - 1][*] = true$.

这样这道题的复杂度就是 $O(\sum B \cdot X)$

```cpp
void Mainsol() {
	INT(N, X);
	v<I> v;
	rep(i, N) {
		INT(A, B);
		rep(B) v.pb(A);
	}
	sor(v); // 排不排序无任何区别
	vv(bool, f, sz(v) + 1, X + 1 ,false);
	f[0][0] = 1;

	rep(i, 0, sz(v)) rep(j, 0, X + 1) {
		if(j < v[i]) {
			if(f[i][j]) f[i + 1][j] = 1;
			else f[i + 1][j] = 0;
		}
		if(j >= v[i]) {
			if(f[i][j] || f[i][j - v[i]]) f[i + 1][j] = 1;
			else f[i + 1][j] = 0;
		}
	}
    
	if(f[sz(v)][X]) Yes();
	else No();
}

```

2.[ATC abc275F - Erase Subarrays](https://atcoder.jp/contests/abc275/tasks/abc275_f)

考虑在部分和DP上加新的维度！

对于正常的部分和我们会发现，考虑第 $i$ 个元素的时候，有且仅有两种情况，选择第 $i$ 个元素与不选择第 $i$ 个元素.

题目要我们求删除的最小连续段数，所以如果我们把 **选择** 和 **不选择** 该元素作为维度加在部分和DP上，是不是就可以了呢？

现在让我们再考虑一下如何存储结果，对于如果选择这个数，那么最后一维是 $1$ ,反之是 $0$，然后考虑结果转移，如果前一个是 $0$，那么如果现在是 $1$ ，那么就需要贡献 $+1$ ，反之则不 $+1$ ，如果前一个是 $1$ 呢？其实都不添加贡献就可以了！

但是这里还要考虑初始值，因为还要确定能不能凑出 $S$，所以我们可以考虑把初始值都设置为 $\inf$，初始值$dp[0][0][0] = 0$ 即可！

这样复杂度也是 $O(N \cdot M)$ 的

```cpp
void Mainsol() {
	INT(N, M);
	VEC(I, a, N);
	vv(ll, f1, N + 1, M + 1, LINF);
	vv(ll, f0, N + 1, M + 1, LINF);
	f0[0][0] = 0;
	rep(i, N) {
		rep(j, M + 1) {
			chmin(f1[i + 1][j], f1[i][j]);
			chmin(f1[i + 1][j], f0[i][j] + 1);
			if(j + a[i] <= M) {
				chmin(f0[i + 1][j + a[i]], f0[i][j]);
				chmin(f0[i + 1][j + a[i]], f1[i][j]);
			}
		}
	}
	dbg(f1[N]); dbg(f0[N]);
	rep(i, 1, M + 1) {
		ll ans = min(f1[N][i], f0[N][i]);
		if(ans == LINF) ans = -1;
		out(ans);
	}
}
```

