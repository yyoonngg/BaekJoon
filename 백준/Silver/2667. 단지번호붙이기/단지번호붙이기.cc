#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, a[30][30], visited[30][30], ret1;
vector<int> ret2;

int go(int y, int x) {
    int _ret = 1;
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(a[ny][nx] == 1) _ret += go(ny, nx);
    }
    return _ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1 && !visited[i][j]) {
                int tmp = go(i, j);
                ret1++;
                ret2.push_back(tmp);
            }
        }
    }

    sort(ret2.begin(), ret2.end());
    cout << ret1 << "\n";
    for(int r : ret2) cout << r << "\n";
 
    return 0;
}