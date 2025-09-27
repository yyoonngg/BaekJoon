#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[54][54], visited[54][54];

pair<int, int> go(int y, int x) {
    int _ret = visited[y][x];
    int ans = a[y][x];
    queue<pair<int, int>> q;
    q.push({y, x});

    while(!q.empty()) {
        pair<int, int> here = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[here.first][here.second] + 1;
            if(visited[ny][nx] > _ret) _ret = visited[ny][nx], ans = a[ny][nx];
            else if(visited[ny][nx] == _ret) ans = (ans < a[ny][nx] ? a[ny][nx] : ans);  
        }
    }
    return {_ret, ans};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }    

    pair<int, int> best = {0, 0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) continue;
            memset(visited, 0, sizeof(visited));
            visited[i][j] = 1;
            pair<int, int> tmp = go(i, j);
            pair<int, int> cand = {tmp.first, tmp.second + a[i][j]};
            best = max(best, cand);
        }
    }

    cout << best.second << "\n";
}