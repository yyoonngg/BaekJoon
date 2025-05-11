#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[504][504], visited[504][504], ret1, ret2;

int dfs(int y, int x) {
    int _cnt = 1;
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx] == 1) _cnt += dfs(ny, nx);
    }
    return _cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 1 && !visited[i][j]) {
                ret1++;
                ret2 = max(ret2, dfs(i, j));
            }
        }
    }

    cout << ret1 << "\n";
    cout << ret2 << "\n";

    return 0;
}