#include<bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104], y, x, ny, nx, ret, cnt;
queue<pair<int, int>> q, tempQ;

void swap() {
    swap(q, tempQ);
    for(int i = 0; i < tempQ.size(); i++) tempQ.pop(); 
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    q.push({0, 0});
    visited[0][0] = 1;
    while(1) {
        while(q.size()) {
            tie(y, x) = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                ny = y + dy[i];
                nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(visited[ny][nx]) continue; 
                if(a[ny][nx] == 1) {
                    visited[ny][nx] = 1;
                    tempQ.push({ny, nx});
                    continue;
                }
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
        if(tempQ.size() == 0) break;
        ret = tempQ.size();
        swap();
        cnt++;
    } 

    cout << cnt << "\n";
    cout << ret << "\n";

    return 0;
}