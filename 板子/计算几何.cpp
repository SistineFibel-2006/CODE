#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
struct Math_2 {
    //�������岿��
    using point = pair<int, int>;
    using Vec = point;
    struct circle {point o; int r;};
    struct polgon {vector<point> p;};
    struct segment {point a, b;};
    //���� + - ������
    point plus(point a, point b) {return {a.X + b.X, a.Y + b.Y};};
    point minus(point a, point b) {return {a.X - b.X, a.Y - b.Y};};
    // ������˺Ͳ��
    double dotp(point a, point b) { return a.X * b.X + a.Y * b.Y; };
    double cross(point a, point b) { return a.X * b.Y - a.Y * b.X; }; // �������
    double cross(point a, point b, point c) { // ������ (AB �� AC)
        Vec ab = minus(b, a);
        Vec ac = minus(c, a);
        return cross(ab, ac);
    }  
    //���벿��
    double Odis(point a, point b){ //ŷ�Ͼ���
        return sqrt(pow((a.X - b.X), 2) + pow((a.Y - b.Y), 2));
    }
    double Mdis(point a, point b){ //�����پ���
        return abs(a.X - b.X) + abs(a.Y - b.Y); 
    }
    double Cdis(point a, point b){ //�б�ѩ�����
        return max(abs(a.X - b.X), abs(a.Y - b.Y));
    }

    //Ƥ�˶������㶨���λ�ڸ���ϵļ򵥶������� 
                //������

    // ���ι�ϵ�ж�
    int pointWhichSide(segment seg, point o) {
        double cr = cross(seg.a, seg.b, o);
        if (cr < 0) return 1;      // �Ҳ�
        else if (cr == 0) return 0; // ������
        else return -1;             // ���
    };
    
    bool pointOnLine(segment seg, point o) { 
        return cross(seg.a, seg.b, o) == 0; 
    };
    
    bool pointOnSegment(segment seg, point o) {
        if (!pointOnLine(seg, o)) return false;
        // ���ͶӰ�Ƿ����߶η�Χ��
        return (min(seg.a.X, seg.b.X) <= o.X && o.X <= max(seg.a.X, seg.b.X)) &&
               (min(seg.a.Y, seg.b.Y) <= o.Y && o.Y <= max(seg.a.Y, seg.b.Y));
    }; 

    // ��ά͹���㷨��Andrew�㷨��
    
    
};


signed main () {
    puts("ok");
    return 0;
}