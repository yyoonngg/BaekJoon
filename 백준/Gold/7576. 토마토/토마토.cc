#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[1004][1004];
int num0, ret;
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) num0++;
            if(a[i][j] == 1) q.push({i, j});
        }
    }    
    
    while(!q.empty()) {
        pair<int, int> here = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] != 0) continue;
            q.push({ny, nx}); 
            a[ny][nx] = a[here.first][here.second] + 1;
            num0--;
        }
    }
    
    if(num0 > 0) cout << -1 << "\n";
    else {
        int max_day = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                max_day = max(max_day, a[i][j]);
        cout << max_day - 1;
    }

    return 0;
}