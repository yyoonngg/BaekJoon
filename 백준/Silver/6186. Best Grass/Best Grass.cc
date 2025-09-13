#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, visited[104][104], ret;
char a[104][104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!visited[i][j] && a[i][j] == '#') {
                for(int d = 0; d < 4; d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if(a[ny][nx] == '#') {
                        visited[ny][nx] = 1;
                        break;
                    }
                }
                visited[i][j] = 1;
                ret++;
            }
        }
    }
     
    cout << ret << "\n";
}