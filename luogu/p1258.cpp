#include <bits/stdc++.h>
using namespace std;

int main(){

    double s, v1, v2;
    scanf("%lf%lf%lf",&s,&v1,&v2);

    double l = 0.0, r = s;
    // 二分
    while (r - l > 1e-9) {
        double mid = (l + r) / 2.0;
        // 驾驶员先开车走 mid 距离所用时间
        double td = mid / v2;
        // 这段时间内步行者自己走的距离
        double dis = td * v1;
        // 汽车从终点折返回来与步行者相遇，closing speed = v1+v2
        double tb = (mid - dis) / (v1 + v2);
        // 驾驶员下车后自己剩余全程步行时间
        double t1 = td + (s - mid) / v1;
        // 折返接到步行者后，一起开车到终点的时间
        // 此时步行者在 td+tb 时间内走了 d_walk2 = (td+tb)*v1
        double d_walk2 = (td + tb) * v1;
        double t2 = td + tb + (s - d_walk2) / v2;
        // 谁慢谁决定边界
        if (t1 < t2)
            r = mid;
        else
            l = mid;
    }
    // 用最终的 p 再算一次到达时间
    double p = (l + r) / 2.0;
    double td = p / v2;
    double t1 = td + (s - p) / v1;

    printf("%.6lf", t1);
    return 0;
}
