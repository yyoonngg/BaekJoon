#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, k, l;
int board[101][101];
int visited[101][101];
vector<pair<int, char>> dirInfo;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = 1; // 0-indexed
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int t; char d;
        cin >> t >> d;
        dirInfo.push_back({t, d});
    }

    int y = 0, x = 0, dir = 1, time = 0, idx = 0;
    deque<pair<int, int>> snake;
    snake.push_back({y, x});
    visited[y][x] = 1;

    while (true) {
        time++;
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) break;

        if (board[ny][nx] == 1) {
            board[ny][nx] = 0;
        } else {
            auto tail = snake.back(); snake.pop_back();
            visited[tail.first][tail.second] = 0;
        }

        snake.push_front({ny, nx});
        visited[ny][nx] = 1;
        y = ny; x = nx;

        if (idx < l && time == dirInfo[idx].first) {
            if (dirInfo[idx].second == 'D') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            idx++;
        }
    }

    cout << time << "\n";
}
