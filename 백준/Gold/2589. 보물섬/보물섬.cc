#include<bits/stdc++.h>
using namespace std;

int n, m, a[52][52], visited[52][52], ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
string s;

int bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    int depth = 0;

    while(q.size()) {
        pair<int, int> here = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] == 0) continue;
            visited[ny][nx] = visited[here.first][here.second] + 1;
            depth = visited[ny][nx]-1;
            q.push({ny, nx});
        }
    }
    return depth;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'W') a[i][j] = 0;
            else if(s[j] == 'L') a[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 1) { 
                memset(visited, 0, sizeof(visited));
                ret = max(ret, bfs(i, j));
            }
        }
    }

    cout << ret << "\n";

    return 0;
}