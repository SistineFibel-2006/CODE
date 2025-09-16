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
    //�������岿��
    using point = pair<int, int>;
    using Vec = point;
    struct circle {point o; int r;};
    struct polgon {vector<point> p;};
    struct segment {point a, b;};
    //���� + - ������
    point plus(point a, point b) {return {a.X + b.X, a.Y + b.Y};};
    point minus1(point a, point b) {return {a.X - b.X, a.Y - b.Y};};
    // ������˺Ͳ��
    double dotp(point a, point b) { return a.X * b.X + a.Y * b.Y; };
    double cross(point a, point b) { return a.X * b.Y - a.Y * b.X; }; // �������
    double cross(point a, point b, point c) { // ������ (AB �� AC)
        Vec ab = minus1(b, a);
        Vec ac = minus1(c, a);
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
    vector<point> convexHull(vector<point>& points) {
        int n = points.size();
        if (n <= 3) return points; // ������3ֱ�ӷ���
        
        // 1. ����������x����x��ͬ��y����
        sort(points.begin(), points.end());
        
        vector<point> hull; // �洢͹������
        
        // 2. ������͹��
        for (int i = 0; i < n; ++i) {
            // ɾ��������ת�ĵ㣨�����0��ʾ����ʱ�룩
            while (hull.size() >= 2 && 
                   cross(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        // 3. ������͹��
        int down_size = hull.size(); // ��͹����С
        for (int i = n - 2; i >= 0; --i) { // �ӵ����ڶ����㿪ʼ
            // ɾ��������ת�ĵ�
            while (hull.size() > down_size && 
                   cross(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        // 4. �Ƴ��ظ���㣨��β��ͬ��
        if (hull.size() > 1) hull.pop_back();
        return hull;
    };
 

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��




signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
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
1. С���ݣ��������ݣ��� n = 1?
2. ��Сֵ�����ֵȡ���٣��Ƿ�������
3. ��ʼֵ��û�и�ֵ����û�н�����
4. �����С���Ƿ�Խ�磿
5. ˼��������ʱ�򣬿����Ƿ�����Ƕ�������Σ������Ǹ�����ȷ���޷��������Ƿ���Է��α�����
6. ������ϸ�ķ�������?
7. ѡ��������Ƿ����Ϊ�գ�

Trick:
1.
2.
3.

About implementation skills:
1. ȫ�ֳ�������д��ĸ�����ֲ���������ʱ�������ͺ������ݵĲ���ʹ��Сд��ĸ��
2. ��ģ�⾡����ѭ����ô������ôд��
3. ����һЩ���ݺ�С����Ҫά������������Ҫ��������ʱ�����Կ��ǰ����������ɱ�����
4. д�ɶ��������
*/
