#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, sy, sx, sd, a[54][54], ret;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> sy >> sx >> sd;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    q.push({sy, sx});

    while(!q.empty()) {
        pair<int, int> here = q.front(); 
        q.pop();

        if(a[here.first][here.second] == 0) {
            ret++;
            a[here.first][here.second] = -1;
        }

        int sum = 0;
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == 0) sum++;
        }

        if(sum) {
            for(int i = 0; i < 4; i++) {
                sd = (sd + 3) % 4;
                int ny = here.first + dy[sd];
                int nx = here.second + dx[sd];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(a[ny][nx] == 0) {
                    q.push({ny, nx});
                    break;
                }
            }
        }
        else {
            int ny = here.first + dy[(sd + 2) % 4];
            int nx = here.second + dx[(sd + 2) % 4];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 1) break;
            q.push({ny, nx});
            continue;
        }
    }

    cout << ret << "\n";

    return 0;
}