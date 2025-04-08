#include <bits/stdc++.h>
using namespace std;
const int dy[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
const int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int r, c, ix, iy, ret;
char a[104][104], temp[104][104];
string dir;
vector<pair<int, int>> michinList;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'I') ix = j, iy = i;
            if(a[i][j] == 'R') michinList.push_back({i, j});
        }
    }
    cin >> dir;

    // LOGIC
    bool die = false;
    for(int i = 0; i < dir.size(); i++) {
        // 이동 횟수
        ret++;

        // 다음 좌표 계산
        int d = (int)(dir[i] - '0') - 1;
        int ny = iy + dy[d];
        int nx = ix + dx[d];
        if(a[ny][nx] == 'R') { die = true; break; }
        a[iy][ix] = '.'; a[ny][nx] = 'I';
        iy = ny; ix = nx;

        // 아두이노 이동
        vector<pair<int, int>> bombList;
        fill(&temp[0][0], &temp[0][0] + 104*104, '.');
        temp[iy][ix] = 'I';
        for(auto michin: michinList) {
            int mnx, mny;
            if(michin.first - iy < 0) mny = 1;
            else if(michin.first - iy == 0) mny = 0;
            else mny = -1;

            if(michin.second - ix < 0) mnx = 1;
            else if(michin.second - ix == 0) mnx = 0;
            else mnx = -1;
            mny += michin.first; mnx += michin.second;

            if(a[mny][mnx] == 'I') { die = true; break; }
            if(temp[mny][mnx] == 'R') bombList.push_back({mny, mnx});
            temp[mny][mnx] = 'R';
        }

        if(die) break;

        // 겹친 아두이노 폭발
        for(auto bomb: bombList) {
            temp[bomb.first][bomb.second] = '.';
        }
        memcpy(&a, &temp, sizeof(temp));

        // michinList 업데이트
        michinList.clear();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(a[i][j] == 'R') michinList.push_back({i, j});
            }
        }
    }

    if(die) cout << "kraj " << ret << "\n";
    else {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}