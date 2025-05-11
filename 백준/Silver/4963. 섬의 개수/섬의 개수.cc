#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int w, h, a[54][54], visited[54][54];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        int ret = 0;
        fill(&a[0][0], &a[0][0]+54*54, 0);
        fill(&visited[0][0], &visited[0][0]+54*54, 0);

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> a[i][j];
            }
            
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(visited[i][j] || a[i][j] == 0) continue;
                dfs(i, j);
                ret++;
            }
        }

        cout << ret << "\n";
    }

    return 0;
}