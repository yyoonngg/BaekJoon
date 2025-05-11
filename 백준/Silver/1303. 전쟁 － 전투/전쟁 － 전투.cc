#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, visited[104][104], ret1, ret2;
char a[104][104];

int dfs(int y, int x, char oper) {
    int _cnt = 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] == oper) {
                _cnt += dfs(ny, nx, oper);
            }
        }
    }
    return _cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];

        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'W' && !visited[i][j]) {
               ret1 += pow(dfs(i, j, 'W'), 2);
            }
            else if(a[i][j] == 'B' && !visited[i][j]) {
               ret2 += pow(dfs(i, j, 'B'), 2);
            }
        }
    }

    cout << ret1 << " " << ret2 << "\n";

    return 0;
}