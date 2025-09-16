#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; 

class SegmentTree {
public:
    vector<int> tree;
    int size;

    SegmentTree(int s) : size(s), tree(4 * s + 4, INF) {}

    void update(int node, int start, int end, int idx, int val_id) {
        if (start == end) {
            tree[node] = min(tree[node], val_id);
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) { 
                update(2 * node, start, mid, idx, val_id);
            } else { 
                update(2 * node + 1, mid + 1, end, idx, val_id);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INF;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, L, R);
        int p2 = query(2 * node + 1, mid + 1, end, L, R);

        return min(p1, p2);
    }
};

struct Point {
    int a;   
    int b;    
    int id;   
};
bool work(const Point& p1, const Point& p2) {
    if (p1.a != p2.a) {
        return p1.a > p2.a; 
    }
    return p1.b < p2.b; 
}
signed main (){
	cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	cin >> t;  
	while(t --)
		solve();
}

void solve(){
	int n;
    cin >> n; 

    vector<Point> arr(n);
    vector<int> vals;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].a;
        arr[i].id = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].b;
        vals.push_back(arr[i].b);
    }

    sort(vals.begin(), vals.end());

    vals.erase(unique(vals.begin(), vals.end()), vals.end());

   
    map<int, int> mp;
    for (int i = 0; i < vals.size(); ++i) {
        mp[vals[i]] = i + 1; 
    }
    for (int i = 0; i < n; ++i) {
        arr[i].b = mp[arr[i].b];
    }

    sort(arr.begin(), arr.end(), work);

    SegmentTree st(vals.size());
    pair<int, int> isp = {-1, -1}; 
    bool fs = false;

    int ls = 0;
    while (ls < n && !fs) { 
        int nowv = arr[ls].a;
        int rl = ls;
        while (rl < n && arr[rl].a == nowv) {
            rl++;
        }

        for (int k = ls; k < rl; ++k) {
            int j_id = st.query(1, 1, vals.size(), 1, arr[k].b - 1);
            
            if (j_id != INF) { 
                isp = {arr[k].id, j_id};
                fs = true; 
                break; 
            }
        }
        if (fs) {
            break;
        }
        for (int k = ls; k < rl; ++k) {
            st.update(1, 1, vals.size(), arr[k].b, arr[k].id);
        }
        ls = rl; 
    }

    if (isp.first != -1) { 
        vector<int> ans(n, 0);
        ans[isp.first] = 1; 
        ans[isp.second] = -1; 
        cout << "Yes" << endl;
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << (i == n - 1 ? "" : " "); 
        }
        cout << endl; 
    } else {
        cout << "No" << endl;
    }
	
}
