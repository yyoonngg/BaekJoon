#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, M;
vector<pair<int, int>> graph[1001];  // graph[u] = {{v, cost}, ...}

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        if (dist[now] < cost) continue;

        for (auto [next, weight] : graph[now]) {
            if (dist[next] > dist[now] + weight) {
                dist[next] = dist[now] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].emplace_back(v, cost);
    }

    int A, B;
    cin >> A >> B;

    vector<int> dist = dijkstra(A);
    cout << dist[B] << '\n';

    return 0;
}
