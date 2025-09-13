#include <bits/stdc++.h>
using namespace std;
const int MAX = 987654321;
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int t, n, y, x, visited[304][304], ret;

void go(int yy, int xx) {
    if(yy == y && xx == x) {
        ret = 0;
        return;
    }
    queue<pair<int, int>> q;
    q.push({yy, xx});

    while(!q.empty()) {
        pair<int, int> here = q.front(); q.pop();
        
        for(int i = 0; i < 8; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
            if(ny == y && nx == x) {
                ret = min(ret, visited[here.first][here.second] + 1);
                continue;
            }
            visited[ny][nx] = visited[here.first][here.second] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        memset(visited, 0, sizeof(visited));
        ret = MAX;

        int here_y, here_x;
        cin >> here_y >> here_x;
        cin >> y >> x;

        go(here_y, here_x);

        cout << ret << "\n";
    }
}