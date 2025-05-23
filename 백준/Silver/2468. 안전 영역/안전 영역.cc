#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, a[104][104], visited[104][104], max_height, ret;

void dfs(int y, int x, int h) {
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(a[ny][nx] > h) {
            dfs(ny, nx, h);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            max_height = max(max_height, a[i][j]);
        }
    }

    for(int h = 0; h < max_height; h++) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        int sum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] > h && visited[i][j] == 0) {
                    dfs(i, j, h);
                    sum++;
                }
            }
        }
        ret = max(ret, sum);
    }

    cout << ret << "\n";

    return 0;
}