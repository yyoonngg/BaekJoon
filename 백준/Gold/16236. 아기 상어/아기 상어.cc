#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};

int n, a[24][24];
int ret, eat_cnt = 0;

struct Shark {
    int y, x, size = 2;
} shark;

int bfs() {
    queue<pair<int, int>> q;
    int visited[24][24] = {};
    q.push({shark.y, shark.x});
    visited[shark.y][shark.x] = 1;

    vector<pair<int,int>> candidates;
    int min_dist = INT_MAX;

    while(!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        int dist = visited[y][x] - 1;
        if(dist > min_dist) break;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] > shark.size) continue;
            visited[ny][nx] = visited[y][x] + 1;

            if(a[ny][nx] != 0 && a[ny][nx] < shark.size) {
                min_dist = dist;
                candidates.push_back({ny, nx});
            }
            q.push({ny, nx});
        }
    }

    if(candidates.empty()) return -1;

    sort(candidates.begin(), candidates.end()); // 자동으로 위→왼 정렬
    auto [fy, fx] = candidates[0];
    a[fy][fx] = 0;
    ret += visited[fy][fx] - 1;
    eat_cnt++;
    if(eat_cnt == shark.size) {
        shark.size++;
        eat_cnt = 0;
    }
    shark.y = fy; shark.x = fx;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 9) {
                shark.y = i;
                shark.x = j;
                a[i][j] = 0;
            }
        }

    while(bfs() != -1);
    cout << ret << "\n";
}
