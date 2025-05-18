#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, M, X;
vector<pair<int, int>> graph[1001];        // 원래 그래프
vector<pair<int, int>> reverse_graph[1001]; // 역방향 그래프

vector<int> dijkstra(int start, vector<pair<int, int>> g[]) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        if (dist[now] < cost) continue;

        for (auto [next, time] : g[now]) {
            if (dist[next] > dist[now] + time) {
                dist[next] = dist[now] + time;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].emplace_back(b, t);
        reverse_graph[b].emplace_back(a, t); // 역방향 간선 저장
    }

    // X -> i (가서 돌아오는 길)
    vector<int> from_X = dijkstra(X, graph);         // X -> 모든 정점
    vector<int> to_X   = dijkstra(X, reverse_graph); // 모든 정점 -> X

    int max_time = 0;
    for (int i = 1; i <= N; ++i) {
        int round_trip = to_X[i] + from_X[i];
        max_time = max(max_time, round_trip);
    }

    cout << max_time << '\n';
    return 0;
}
