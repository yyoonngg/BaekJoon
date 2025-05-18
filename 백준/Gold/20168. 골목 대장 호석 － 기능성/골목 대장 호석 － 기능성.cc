#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N, M, A, B, C;
vector<tuple<int, int, int>> edges; // {u, v, cost}
vector<pair<int, int>> graph[11];   // graph[u] = {v, cost}

bool dijkstra(int maxCost) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[A] = 0;
    pq.push({0, A});

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost > dist[u]) continue;

        for (auto [v, toll] : graph[u]) {
            if (toll > maxCost) continue; // 수치심 한도 초과

            int nextCost = cost + toll;
            if (nextCost < dist[v]) {
                dist[v] = nextCost;
                pq.push({nextCost, v});
            }
        }
    }

    return dist[B] <= C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> A >> B >> C;

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.emplace_back(u, v, c);
    }

    int lo = 1, hi = 1000, result = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        // 그래프 초기화
        for (int i = 1; i <= N; ++i) graph[i].clear();
        for (auto [u, v, c] : edges) {
            if (c <= mid) {
                graph[u].emplace_back(v, c);
                graph[v].emplace_back(u, c);
            }
        }

        if (dijkstra(mid)) {
            result = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << result << '\n';
    return 0;
}
