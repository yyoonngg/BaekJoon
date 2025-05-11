#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, a[104][104], visited[104][104], ret;

int dfs(int y, int x) {
    visited[y][x] = 1;
    int _cnt = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] && !visited[ny][nx]) {
            _cnt += dfs(ny, nx);
        }
    }
    return _cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        a[--y][--x] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] && !visited[i][j]) {
                ret = max(ret, dfs(i, j));
            }
        }
    }

    cout << ret << "\n";
    return 0;
}