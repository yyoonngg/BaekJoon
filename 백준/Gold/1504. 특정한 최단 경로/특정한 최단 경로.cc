#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int N, E;
vector<pair<int, int>> graph[801];  // (node, cost)

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

    cin >> N >> E;
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 1 -> v1 -> v2 -> N
    // 1 -> v2 -> v1 -> N
    auto dist_from_1 = dijkstra(1);
    auto dist_from_v1 = dijkstra(v1);
    auto dist_from_v2 = dijkstra(v2);

    long long path1 = (long long)dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[N];
    long long path2 = (long long)dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[N];

    long long result = min(path1, path2);
    if (result >= INF) cout << -1 << '\n';
    else cout << result << '\n';

    return 0;
}
