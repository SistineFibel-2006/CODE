#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
struct Math_2 {
    //变量定义部分
    using point = pair<int, int>;
    using Vec = point;
    struct circle {point o; int r;};
    struct polgon {vector<point> p;};
    struct segment {point a, b;};
    //向量 + - 法运算
    point plus(point a, point b) {return {a.X + b.X, a.Y + b.Y};};
    point minus(point a, point b) {return {a.X - b.X, a.Y - b.Y};};
    // 向量点乘和叉乘
    double dotp(point a, point b) { return a.X * b.X + a.Y * b.Y; };
    double cross(point a, point b) { return a.X * b.Y - a.Y * b.X; }; // 向量叉乘
    double cross(point a, point b, point c) { // 三点叉积 (AB × AC)
        Vec ab = minus(b, a);
        Vec ac = minus(c, a);
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
    
    
};


signed main () {
    puts("ok");
    return 0;
}