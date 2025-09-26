#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 250000 + 5;
static const int LOG = 20;

int n, q;
vector<int> adj[MAXN];

int up[LOG][MAXN];
int depth_[MAXN];
int tin[MAXN], tout[MAXN], timer_ = 0;

inline bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int k = LOG - 1; k >= 0; --k) {
        int pu = up[k][u];
        if (!is_ancestor(pu, v)) u = pu;
    }
    return up[0][u];
}

inline int dist(int a, int b) {
    int c = lca(a, b);
    return depth_[a] + depth_[b] - 2 * depth_[c];
}

void build_rooted_tree(int root = 1) {
    // Iterative DFS to fill depth, up, tin/tout
    for (int i = 1; i <= n; ++i) depth_[i] = -1;
    for (int k = 0; k < LOG; ++k) up[k][root] = root;
    depth_[root] = 0;

    vector<int> it(n + 1, 0);
    stack<int> st;
    st.push(root);

    while (!st.empty()) {
        int v = st.top();
        if (it[v] == 0) {
            tin[v] = ++timer_;
            // up[][] for v is already set if v == root or when discovered as child
        }
        if (it[v] < (int)adj[v].size()) {
            int to = adj[v][it[v]++];
            if (to == up[0][v]) continue;           // parent edge
            if (depth_[to] != -1) continue;         // already visited (shouldn't happen in tree)
            up[0][to] = v;
            for (int k = 1; k < LOG; ++k) up[k][to] = up[k - 1][up[k - 1][to]];
            depth_[to] = depth_[v] + 1;
            st.push(to);
        } else {
            tout[v] = ++timer_;
            st.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    build_rooted_tree(1);

    cin >> q;
    string out;
    out.reserve(q * 4);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, j, k; cin >> i >> j >> k;
            // 시작/도착이 공사 정점이면 불가
            if (i == k || j == k) {
                out += "NO\n";
                continue;
            }
            // 경로가 k를 지나면 불가
            bool through_k = (dist(i, k) + dist(k, j) == dist(i, j));
            out += (through_k ? "NO\n" : "YES\n");
        } else {
            int i, j, k, l; cin >> i >> j >> k >> l;
            if (i == j) { // 같은 건물은 도로 공사와 무관하게 가능
                out += "YES\n";
                continue;
            }
            // (k, l)가 트리의 간선: 부모-자식 방향 정하기
            int child;
            if (up[0][k] == l) child = k;
            else if (up[0][l] == k) child = l;
            else {
                // 안전장치: 입력이 보장되므로 도달하지 않음
                child = k;
            }
            bool inI = is_ancestor(child, i);
            bool inJ = is_ancestor(child, j);
            // child 서브트리에 한쪽만 속하면 해당 간선을 지나므로 단절
            out += ((inI ^ inJ) ? "NO\n" : "YES\n");
        }
    }

    cout << out;
    return 0;
}
