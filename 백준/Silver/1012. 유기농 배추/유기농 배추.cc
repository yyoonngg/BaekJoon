#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, ny, nx, x, y;
int a[54][54], visited[54][54];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
string s;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> t;
    
    while(t--) {
        cin >> m >> n >> k;
        memset(a, 0, sizeof(a)); 
        memset(visited, 0, sizeof(visited)); 
        int ret = 0;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0 && a[i][j]) {
                    dfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }

    return 0;

}