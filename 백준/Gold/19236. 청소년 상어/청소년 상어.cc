#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int ret = 0;
struct Fish {
    int y, x, d;
    bool alive;
};

void moveFish(int a[4][4], Fish fish[17], int shark_y, int shark_x) {
    for(int i = 1; i <= 16; i++) {
        if(!fish[i].alive) continue;
        int y = fish[i].y;
        int x = fish[i].x;
        int d = fish[i].d;

        for(int t = 0; t < 8; t++) {
            int nd = (d + t) % 8;
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
            if(ny == shark_y && nx == shark_x) continue;

            int target = a[ny][nx];
            if(target != 0) {
                swap(fish[i].y, fish[target].y);
                swap(fish[i].x, fish[target].x);
                a[y][x] = target;
                a[ny][nx] = i;
            }
            else {
                a[y][x] = 0;
                a[ny][nx] = i;
                fish[i].y = ny;
                fish[i].x = nx;
            }
            fish[i].d = nd;
            break;
        }
    }
}

void dfs(int a[4][4], Fish fish[17], int sy, int sx, int score) {
    int b[4][4];
    Fish newFish[17];

    memcpy(b, a, sizeof(b));
    memcpy(newFish, fish, sizeof(newFish));

    int eat = b[sy][sx];
    score += eat;
    int dir = newFish[eat].d;
    newFish[eat].alive = false;
    b[sy][sx] = 0;

    moveFish(b, newFish, sy, sx);

    bool moved = false;
    for(int step = 1; step <= 3; step++) {
        int ny = sy + dy[dir] * step;
        int nx = sx + dx[dir] * step;
        if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4) break;
        if(b[ny][nx] == 0) continue;

        moved = true;
        dfs(b, newFish, ny, nx, score);
    }

    if(!moved) {
        ret = max(ret, score);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a[4][4];
    Fish fish[17];

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int num, d;
            cin >> num >> d;
            a[i][j] = num;
            fish[num] = {i, j, d - 1, true};
        }
    }

    dfs(a, fish, 0, 0, 0);

    cout << ret << "\n";

    return 0;
}