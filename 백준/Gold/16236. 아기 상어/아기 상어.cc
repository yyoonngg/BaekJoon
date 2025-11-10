#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, a[24][24], visited[24][24], sss = 2, ret;
struct fish {
    int size, y, x;
};
fish shark;
vector<fish> fish_list;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 9) {
                shark = {2, i, j};
            }
            else if(a[i][j] != 0) fish_list.push_back({a[i][j], i, j});
        }
    }

    while(1) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> bucket;
        q.push({shark.y, shark.x});
        memset(visited, 0, sizeof(visited));
        visited[shark.y][shark.x] = 1;
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if(visited[ny][nx]) continue;
                if(shark.size < a[ny][nx]) continue;
                if(shark.size > a[ny][nx] && a[ny][nx] != 0) bucket.push_back({ny, nx});
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;  
            }
        }
        if(!(int)bucket.size()) break;
        else {
            pair<int, int> next;
            int next_dist = INT_MAX;
            for(auto b : bucket) {
                if(next_dist > visited[b.first][b.second] - 1) {
                    next = {b.first, b.second};
                    next_dist = visited[b.first][b.second] - 1;
                }
                else if(next_dist == visited[b.first][b.second] - 1) {
                    if(next.first > b.first) next = b;
                    else if(next.first == b.first && next.second > b.second) next = b; 
                }
            }
            ret += next_dist;
            sss--;
            a[shark.y][shark.x] = 0;
            shark = {(sss == 0 ? shark.size + 1 : shark.size), next.first, next.second};
            a[shark.y][shark.x] = 9;

            if(sss == 0) sss = shark.size;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}