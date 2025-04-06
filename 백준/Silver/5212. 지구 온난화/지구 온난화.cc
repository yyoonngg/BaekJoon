#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int r, c;
char a[14][14];
queue<pair<int, int>> island;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'X') {
                island.push({i, j});
            }
        }
    }

    while(!island.empty()) {
        pair<int, int> here = island.front(); 
        island.pop();
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
                sum++;
                continue;
            }
            if(a[ny][nx] == '.') sum++;
        }

        if(sum >= 3) v.push_back({here.first, here.second});
    }

    for(auto here: v) a[here.first][here.second] = '.';

    int maxX = -1, maxY = -1, minX = 14, minY = 14;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] == 'X') {
                maxX = max(maxX, j);
                maxY = max(maxY, i);
                minX = min(minX, j);
                minY = min(minY, i);
            }
        }
    }

    for(int i = minY; i <= maxY; i++) {
        for(int j = minX; j <= maxX; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}