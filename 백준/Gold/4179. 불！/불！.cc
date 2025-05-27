#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, fire_visited[1004][1004], jihun_visited[1004][1004], ret;
char a[1004][1004];
queue<pair<int, int>> fire, jihun;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'F') {
                fire.push({i, j});
                fire_visited[i][j] = 1;
            }
            else if(a[i][j] == 'J') {
                jihun.push({i, j});
                jihun_visited[i][j] = 1;
            }
        }
    }

    while(!jihun.empty()) {
        ret++;

        int fire_size = fire.size();
        while(fire_size--) {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if (fire_visited[ny][nx] || a[ny][nx] == '#') continue;

                fire_visited[ny][nx] = 1;
                a[ny][nx] = 'F';
                fire.push({ny, nx});
            }
        }

        int jihun_size = jihun.size();
        while(jihun_size--) {
            int y = jihun.front().first;
            int x = jihun.front().second;
            jihun.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
                    cout << ret << "\n";
                    return 0;
                }

                if (jihun_visited[ny][nx] || a[ny][nx] == '#' || a[ny][nx] == 'F') continue;

                jihun_visited[ny][nx] = 1;
                jihun.push({ny, nx});
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}