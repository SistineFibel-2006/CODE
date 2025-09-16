#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

#define X first
#define Y second
    //变量定义部分
    using point = pair<int, int>;
    using Vec = point;
    struct circle {point o; int r;};
    struct polgon {vector<point> p;};
    struct segment {point a, b;};
    //向量 + - 法运算
    point plus(point a, point b) {return {a.X + b.X, a.Y + b.Y};};
    point minus1(point a, point b) {return {a.X - b.X, a.Y - b.Y};};
    // 向量点乘和叉乘
    double dotp(point a, point b) { return a.X * b.X + a.Y * b.Y; };
    double cross(point a, point b) { return a.X * b.Y - a.Y * b.X; }; // 向量叉乘
    double cross(point a, point b, point c) { // 三点叉积 (AB × AC)
        Vec ab = minus1(b, a);
        Vec ac = minus1(c, a);
        return cross(ab, ac);
    }  
    //距离部分
    double Odis(point a, point b){ //欧氏距离
        return sqrt(pow((a.X - b.X), 2) + pow((a.Y - b.Y), 2));
    }
    double Mdis(point a, point b){ //曼哈顿距离
        return abs(a.X - b.X) + abs(a.Y - b.Y); 
    }
    double Cdis(point a, point b){ //切比雪夫距离
        return max(abs(a.X - b.X), abs(a.Y - b.Y));
    }

    //皮克定理，计算定点均位于格点上的简单多边形面积 
                //待补充

    // 几何关系判断
    int pointWhichSide(segment seg, point o) {
        double cr = cross(seg.a, seg.b, o);
        if (cr < 0) return 1;      // 右侧
        else if (cr == 0) return 0; // 在线上
        else return -1;             // 左侧
    };
    
    bool pointOnLine(segment seg, point o) { 
        return cross(seg.a, seg.b, o) == 0; 
    };
    
    bool pointOnSegment(segment seg, point o) {
        if (!pointOnLine(seg, o)) return false;
        // 检查投影是否在线段范围内
        return (min(seg.a.X, seg.b.X) <= o.X && o.X <= max(seg.a.X, seg.b.X)) &&
               (min(seg.a.Y, seg.b.Y) <= o.Y && o.Y <= max(seg.a.Y, seg.b.Y));
    }; 

    // 二维凸包算法（Andrew算法）
    vector<point> convexHull(vector<point>& points) {
        int n = points.size();
        if (n <= 3) return points; // 点数≤3直接返回
        
        // 1. 按坐标排序（x升序，x相同则y升序）
        sort(points.begin(), points.end());
        
        vector<point> hull; // 存储凸包顶点
        
        // 2. 构建下凸包
        for (int i = 0; i < n; ++i) {
            // 删除导致右转的点（叉积≤0表示非逆时针）
            while (hull.size() >= 2 && 
                   cross(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        // 3. 构建上凸包
        int down_size = hull.size(); // 下凸包大小
        for (int i = n - 2; i >= 0; --i) { // 从倒数第二个点开始
            // 删除导致右转的点
            while (hull.size() > down_size && 
                   cross(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        // 4. 移除重复起点（首尾相同）
        if (hull.size() > 1) hull.pop_back();
        return hull;
    };
 

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数




signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
    int n;
    cin >> n;
    vector<point> a;
    for(int i = 0; i < n; i ++){
        point x;
        cin >> x.X >> x.Y;
        a.push_back(x);
    }
    double ans = 0;
    if(n < 4){
        for(int i = 0; i < n - 1; i ++)
            ans += Odis(a[i], a[i + 1]);
        printf("%.2llf", ans);
        return;
    }
    auto b = convexHull(a);
    for(int i = 0; i < sizeof(b); i ++)
        ans += Odis(b[i], b[i + 1]);
    printf("%.2llf", ans);
}
//test
/*
?
// ? (?????) ?
*/

/*
What's wrong with my code?
1. 小数据？特殊数据？如 n = 1?
2. 最小值，最大值取多少？是否会溢出？
3. 初始值有没有赋值？有没有建树？
4. 数组大小？是否越界？
5. 思考暴力的时候，考虑是否可能是多个连续段？或者是个数不确定无法暴力？是否可以分治暴力？
6. 进行详细的分类讨论?
7. 选择的区间是否可以为空？

Trick:
1.
2.
3.

About implementation skills:
1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。
*/
