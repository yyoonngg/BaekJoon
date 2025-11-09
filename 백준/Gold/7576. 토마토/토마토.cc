#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[1004][1004], visited[1004][1004];
int num0, ret;
queue<pair<int, int>> q, qq;

void clear_qq() {
    while(!qq.empty()) qq.pop();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) num0++;
            if(a[i][j] == 1) q.push({i, j});
        }
    }    
    
    qq = q;
    while(!qq.empty()) {
        q = qq;
        clear_qq();
        while(!q.empty()) {
            pair<int, int> here = q.front(); q.pop();
            visited[here.first][here.second] = 1;

            for(int i = 0; i < 4; i++) {
                int ny = here.first + dy[i];
                int nx = here.second + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(visited[ny][nx]) continue;
                if(a[ny][nx] == -1 || a[ny][nx] == 1) continue;
                qq.push({ny, nx}); a[ny][nx] = 1;
                num0--;
            }
        }
        if(!qq.empty()) ret++;
    }
    if(num0 > 0) ret = -1;
    cout << ret << "\n";

    return 0;
}