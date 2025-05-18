#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, D;
vector<pair<int, int>> shortcuts[10001]; // start -> {(end, cost)}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> D;
    for (int i = 0; i < N; ++i) {
        int start, end, cost;
        cin >> start >> end >> cost;
        if (end > D) continue;       // 도착점이 D보다 크면 무시
        if (end - start <= cost) continue; // 지름길이 아닌 경우 무시
        shortcuts[start].emplace_back(end, cost);
    }

    vector<int> dist(D + 1, INF);
    dist[0] = 0;

    for (int i = 0; i <= D; ++i) {
        if (i > 0) dist[i] = min(dist[i], dist[i - 1] + 1); // 직진

        for (auto [end, cost] : shortcuts[i]) {
            if (end <= D) {
                dist[end] = min(dist[end], dist[i] + cost); // 지름길
            }
        }
    }

    cout << dist[D] << '\n';
    return 0;
}
