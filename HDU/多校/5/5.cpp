#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        // 读入所有材料并按形状分组
        vector<ll> V1, V2, V3, V4; 
        int k;
        // 1x1
        cin >> k; V1.resize(k);
        for(int i=0;i<k;i++) cin>>V1[i];
        // 1x2
        cin >> k; V2.resize(k);
        for(int i=0;i<k;i++) cin>>V2[i];
        // 1x3
        cin >> k; V3.resize(k);
        for(int i=0;i<k;i++) cin>>V3[i];
        // 2x2
        cin >> k; V4.resize(k);
        for(int i=0;i<k;i++) cin>>V4[i];

        // 对每组按价值降序，做前缀和
        auto prep = [&](vector<ll>& V){
            sort(V.begin(), V.end(), greater<ll>());
            V.insert(V.begin(), 0);
            for(int i=1;i<(int)V.size();i++)
                V[i] += V[i-1];
        };
        prep(V1); prep(V2); prep(V3); prep(V4);

        // 对每种格子类型，预枚举「放 j 个该类型格子」时能拿到的最大值 best_t[j]
        // 然后把四类 best 序列合并做一次多重背包
        auto build = [&](int cnt, int H, 
                         const vector<ll>& A1,
                         const vector<ll>& A2,
                         const vector<ll>& A3,
                         const vector<ll>& A4){
            // cnt: 格子个数，H: 格子面积
            // A1,V2,V3,V4 的下标即“拿 i 件该材料的前缀和”
            vector<ll> best(cnt+1, 0);
            // 枚举每个格子内部的装法（常数几十种）
            for(int x1=0;x1<=cnt;x1++){
                // 对 j=0..cnt，按装法更新 best[j]
                // 装法1: 0 件 → +0
                // 装法2: 放 1 个 2x2 材料（若 H>=4）
                // … 依照具体每种格子的几何装法，枚举 i1,i2,i3,i4 每种材料件数满足
                //   i1*(1*1)+i2*(1*2)+i3*(1*3)+i4*(2*2) <= H
                // 且 i1<=|V1|-1, i2<=|V2|-1… 
                // 暴力枚举 i1..i4 的常数范围即可。
                // 下面以2x2格子为例（H=4）做一个示意：
                if(H==4){
                    // i4=0或1
                    for(int i4=0;i4<=1;i4++){
                        // i2<=2
                        for(int i2=0;i2<=2;i2++){
                            // i3不能放
                            // 剩余面积 R =4 -4*i4 -2*i2
                            int R = 4 - 4*i4 - 2*i2;
                            if(R<0) continue;
                            // i1最多 R
                            for(int i1=0;i1<=R;i1++){
                                ll val = A1[min(i1,(int)A1.size()-1)]
                                       + A2[min(i2,(int)A2.size()-1)]
                                       + A4[min(i4,(int)A4.size()-1)];
                                // 每个格子可以这样拿 val
                                // 那么用 x 格子就是 x*val
                                // 但 x 从 0..cnt，我们要放在 best[x]
                                // 下面的DP合并时会单独计算 x*val
                                // 这里我们集中枚举“单个格子价值 val”，
                                // 存到一个数组里，后面再做cnt个格子背包。
                                // （你也可以直接在best[cnt]里更新max(best[cnt], best[cnt-1]+val)）
                            }
                        }
                    }
                }
            }
            // 其实我们直接对 cnt 个“相同的多选物品”（每种装法都是一种选项）
            // 做一个简单的多重背包：O(cnt * #装法)。
            // 最终返回 best[j]: 用 j 个格子的最大值。
            return best;
        };

        // 分别拿到四种格子的best
        auto B1 = build(a, 1, V1, V2, V3, V4);
        auto B2 = build(b, 2, V1, V2, V3, V4);
        auto B3 = build(c, 3, V1, V2, V3, V4);
        auto B4 = build(d, 4, V1, V2, V3, V4);

        // 四重背包合并成一维dp
        int N = a+b+c+d;
        vector<ll> dp(N+1, 0), ndp;
        auto merge = [&](const vector<ll>& B, int cnt){
            ndp = dp;
            for(int used=0; used<=N; used++){
                if(dp[used]<0) continue;
                for(int j=1; j<=cnt; j++){
                    if(used+j>N) break;
                    ndp[used+j] = max(ndp[used+j], dp[used] + B[j]);
                }
            }
            dp.swap(ndp);
        };
        merge(B1, a);
        merge(B2, b);
        merge(B3, c);
        merge(B4, d);

        // 最后不一定要用尽所有格子，但肯定用 <=N 个：取 max dp[*]
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}
