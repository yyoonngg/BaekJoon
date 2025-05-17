#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
const int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case = 1;

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<vector<int>> cave(N, vector<int>(N));
        vector<vector<int>> dist(N, vector<int>(N, INF));

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> cave[i][j];

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        dist[0][0] = cave[0][0];
        pq.emplace(cave[0][0], 0, 0);

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (cost > dist[x][y]) continue;

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    int next_cost = cost + cave[nx][ny];
                    if (next_cost < dist[nx][ny]) {
                        dist[nx][ny] = next_cost;
                        pq.emplace(next_cost, nx, ny);
                    }
                }
            }
        }

        cout << "Problem " << test_case++ << ": " << dist[N - 1][N - 1] << '\n';
    }

    return 0;
}
