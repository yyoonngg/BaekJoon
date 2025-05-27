#include<bits/stdc++.h>
using namespace std;

int n, l, r, a[52][52], visited[52][52], _sum, _cnt, cnt;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> ret;

void dfs(int y, int x) {
    visited[y][x] = 1;
    ret.push_back({y, x});
    _sum += a[y][x];
    _cnt++;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while(1) {
        memset(visited, 0, sizeof(visited));
        bool flag = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) { 
                    ret.clear(); _sum = 0; _cnt = 0;
                    dfs(i, j);
                    if(ret.size() > 1) {
                        for(pair<int, int> it : ret) a[it.first][it.second] = (_sum/_cnt);
                        flag = true;
                    }
                }
            }
        }
        if(!flag) break;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}