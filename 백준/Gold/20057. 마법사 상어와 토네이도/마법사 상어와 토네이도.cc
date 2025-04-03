#include <bits/stdc++.h>
using namespace std;

int n, a[504][504], ret;
const int dx[] = {-1, 0, 1, 0}; 
const int dy[] = {0, 1, 0, -1};
struct MASK {
    int dirY, dirX, per;
};
vector<MASK> mask[4];

bool check(int y, int x) {
    return (y < 0 || y >= n || x < 0 || x >= n);
}

void makeMask() {
    mask[0] = {{-1, 1, 1}, {1, 1, 1}, {-2, 0, 2}, {2, 0, 2}, {-1, 0, 7}, {1, 0, 7}, {-1, -1, 10}, {1, -1, 10}, {0, -2, 5}};

    for (int i = 1; i < 4; i++) { 
        for (auto it : mask[i - 1]) {
            mask[i].push_back({-it.dirX, it.dirY, it.per}); 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    makeMask();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int temp_x = n / 2;
    int temp_y = n / 2;
    int dir = 0;

    for (int i = 1; i <= n; i++) {
        int num = (i == n ? 1 : 2);
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < i; k++) {
                int nx = temp_x + dx[dir % 4];
                int ny = temp_y + dy[dir % 4];

                // LOGIC
                if (check(ny, nx)) continue;
                int amount = a[ny][nx];
                int temp_amount = amount;

                for (auto it : mask[dir % 4]) {
                    int sand = (amount * it.per) / 100; 
                    if (check(ny + it.dirY, nx + it.dirX)) ret += sand; 
                    else a[ny + it.dirY][nx + it.dirX] += sand;
                    
                    temp_amount -= sand; 
                }

                int ax = nx + dx[dir % 4];
                int ay = ny + dy[dir % 4];
                if (check(ay, ax)) ret += temp_amount;
                else a[ay][ax] += temp_amount;

                temp_x = nx;
                temp_y = ny;
            }
            dir++;
        }
    }

    cout << ret << "\n";
    return 0;
}
