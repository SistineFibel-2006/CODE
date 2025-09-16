#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

// 用于扫描线建图的事件结构
struct Event {
    int coord;
    int type; // 1 for start, -1 for end
    int id;

    bool operator<(const Event& other) const {
        if (coord != other.coord) {
            return coord < other.coord;
        }
        return type > other.type; // start event first
    }
};

// 用于检测冲突的数据结构
struct Point {
    int x, y, type; // type 0: L-mover point, type 1: R-mover query start, type 2: R-mover query end
    int S, T; // For queries
    
    bool operator<(const Point& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return type < other.type;
    }
};

// 简单的 Fenwick Tree (Binary Indexed Tree)
vector<int> bit;
int bit_size;

void update(int idx, int val) {
    for (; idx <= bit_size; idx += idx & -idx) {
        bit[idx] += val;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> S(N + 1), T(N + 1);
    vector<Event> events;
    vector<Point> conflict_points;
    map<int, int> coord_compress;

    for (int i = 1; i <= N; ++i) {
        cin >> S[i] >> T[i];
        if (S[i] < T[i]) { // R-mover
            conflict_points.push_back({S[i], 0, 1, S[i], T[i]});
            conflict_points.push_back({T[i], 0, 2, S[i], T[i]});
        } else { // L-mover
            conflict_points.push_back({T[i], S[i], 0});
        }
        events.push_back({min(S[i], T[i]), 1, i});
        events.push_back({max(S[i], T[i]), -1, i});
        
        coord_compress[S[i]] = 0;
        coord_compress[T[i]] = 0;
    }

    // --- Part 1: Check for R-L deadlock ---
    int rank = 0;
    for(auto const& [coord, val] : coord_compress) {
        coord_compress[coord] = ++rank;
    }
    bit_size = rank;
    bit.assign(bit_size + 1, 0);

    sort(conflict_points.begin(), conflict_points.end());

    bool impossible = false;
    for(const auto& p : conflict_points) {
        if (p.type == 0) { // L-mover point (T_j, S_j)
            update(coord_compress[p.y], 1);
        } else if (p.type == 1) { // R-mover query start (S_i)
             int upper_bound = (coord_compress.count(p.T) ? coord_compress[p.T] : 0) -1;
             int lower_bound = coord_compress[p.S];
             if (upper_bound > lower_bound) {
                if (query(upper_bound) - query(lower_bound) > 0) {
                    impossible = true;
                    break;
                }
             }
        } else { // R-mover query end (T_i)
            // No action needed, but could remove points if memory is an issue
        }
    }
    
    // Reset BIT for R-L vs L-R checks
    fill(bit.begin(), bit.end(), 0);
    
    // Symmetrically check for L-movers crossing R-movers
    // L-mover i: [T_i, S_i], R-mover j: [S_j, T_j]
    // Conflict if S_j < T_i < T_j < S_i
    // L-movers are queries (T_i, S_i), R-movers are points (S_j, T_j)
    conflict_points.clear();
    for(int i = 1; i <= N; ++i) {
        if (S[i] > T[i]) { // L-mover
            conflict_points.push_back({T[i], 0, 1, T[i], S[i]});
            conflict_points.push_back({S[i], 0, 2, T[i], S[i]});
        } else { // R-mover
            conflict_points.push_back({S[i], T[i], 0});
        }
    }
    sort(conflict_points.begin(), conflict_points.end());
    for(const auto& p : conflict_points) {
        if (p.type == 0) { // R-mover point (S_j, T_j)
            update(coord_compress[p.y], 1);
        } else if (p.type == 1) { // L-mover query start (T_i)
             int upper_bound = (coord_compress.count(p.T) ? coord_compress[p.T] : 0) -1;
             int lower_bound = coord_compress[p.S];
             if (upper_bound > lower_bound) {
                if (query(upper_bound) - query(lower_bound) > 0) {
                    impossible = true;
                    break;
                }
             }
        }
    }


    if (impossible) {
        cout << "No" << endl;
        return 0;
    }

    // --- Part 2: Build Dependency Graph ---
    sort(events.begin(), events.end());
    
    vector<vector<int>> adj(N + 1);
    vector<int> in_degree(N + 1, 0);
    stack<int> st;

    for (const auto& event : events) {
        if (event.type == 1) { // Start
            if (!st.empty()) {
                int parent = st.top();
                // Add edge: event.id -> parent
                adj[event.id].push_back(parent);
                in_degree[parent]++;
            }
            st.push(event.id);
        } else { // End
            st.pop();
        }
    }

    // --- Part 3: Topological Sort ---
    vector<int> queue;
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            queue.push_back(i);
        }
    }

    vector<int> result;
    int head = 0;
    while(head < queue.size()){
        int u = queue[head++];
        result.push_back(u);
        for(int v : adj[u]){
            in_degree[v]--;
            if(in_degree[v] == 0){
                queue.push_back(v);
            }
        }
    }

    if (result.size() != N) {
        // This should not happen if the deadlock check is correct
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        // The result is in reverse topological order based on our graph construction
        // adj[child] -> parent, so parents have higher in-degrees.
        // We need child before parent, so this order is correct.
        for (int i = 0; i < N; ++i) {
            cout << result[i] << (i == N - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}