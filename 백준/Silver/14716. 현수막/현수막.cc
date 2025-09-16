#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, a[250][250], visited[250][250], ret;

void go(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if(visited[ny][nx] || a[ny][nx] == 0) continue;
        go(ny, nx);
    }
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 0 && a[i][j] == 1) {
                go(i, j);
                ret++;
            }
        }
    }

    cout << ret << '\n';

}