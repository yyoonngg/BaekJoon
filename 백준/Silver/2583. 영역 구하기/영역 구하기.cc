#include <bits/stdc++.h>
using namespace std;

int m, n, k, ny, nx, xo, xt, yo, yt, cnt;
int a[104][104], visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> rv;

int dfs(int y, int x, int ret) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx]) continue;
        ret = dfs(ny, nx, ret);
    }
    return ++ret;
}

int main() {
    cin >> m >> n >> k;

    while(k--) {
        cin >> xo >> yo >> xt >> yt;
        for(int i = yo; i < yt; i++) {
            for(int j = xo; j < xt; j++) {
                a[i][j] = 1;
            }
        }
    }

    for(int i = 0 ; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && !a[i][j]) {
                rv.push_back(dfs(i, j, 0));
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    sort(rv.begin(), rv.end());
    for(int i : rv) cout << i << " ";
    return 0;


}