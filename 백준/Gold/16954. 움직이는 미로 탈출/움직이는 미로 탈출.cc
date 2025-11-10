#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

char a[10][10];
vector<pair<int, int>> wall_list;
queue<pair<int, int>> q, qq;
bool flag = false;

void clear_qq() {
    while(!qq.empty()) qq.pop();
}

void move() {
    vector<pair<int, int>> new_wall_list;
    // 모든 벽을 아래로 한 칸 이동
    for (auto &wall : wall_list) {
        a[wall.first][wall.second] = '.';
    }
    for (auto &wall : wall_list) {
        if (wall.first + 1 < 8) {
            a[wall.first + 1][wall.second] = '#';
            new_wall_list.push_back({wall.first + 1, wall.second});
        }
    }
    wall_list = new_wall_list;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> a[i][j];
            if(a[i][j] == '#') wall_list.push_back({i, j});
        }
    }

    qq.push({7, 0});

    for (int t = 0; t < 64 && !flag; t++) {
        q = qq;
        clear_qq();

        while(!q.empty() && !flag) {
            auto [y, x] = q.front(); q.pop();
            if(a[y][x] == '#') continue;

            for(int i = 0; i < 9; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
                if(a[ny][nx] == '#') continue;
                if (ny - 1 >= 0 && a[ny - 1][nx] == '#') continue;
                if(ny == 0 && nx == 7) { flag = true; break; }
                qq.push({ny, nx});
            }
        }

        move();
    }

    if(flag) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}