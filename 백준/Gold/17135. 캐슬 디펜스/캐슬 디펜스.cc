#include <bits/stdc++.h>
using namespace std;
int n, m, d, a[20][20], temp[20][20], ret;
vector<pair<int, int>> enemyList, tempList;

// 1. 궁수가 적을 죽인다.
// 2. 적이 움직인다.

int go(int x) {
    pair<int, int> _ret = {-1, m};
    int _dist = d;
    for(int i = 0; i < tempList.size(); i++) {
        pair<int, int> enemy = tempList[i];
        int dist = abs(enemy.first - n) + abs(enemy.second - x);
        if(dist <= d) {
            if(dist < _dist || (dist == _dist && enemy.second < _ret.second)) {
                _ret = enemy;
                _dist = dist;
            }
        }
    }

    // 아무도 못 죽이면 0 반환
    if(_ret.first == -1 && _ret.second == m) return 0;
    // 죽이면 1 반환
    if(temp[_ret.first][_ret.second]) {
        temp[_ret.first][_ret.second] = 0;
        return 1;
    } 
    // 이미 다른 궁수가 죽였으면 0 반환
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) {
                enemyList.push_back({i, j});
            }
        }
    }   

    // 3명 궁수 배치
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            for(int k = j + 1; k < m; k++) {
                int sum = 0;
                memcpy(&temp, &a, sizeof(a));
                tempList = enemyList;
                while(true) {
                    if(tempList.empty()) break;
                    // (n, i), (n, j), (n, k)
                    // 죽이기
                    sum += (go(i) + go(j) + go(k));
                    
                    // 적 이동하기
                    tempList.clear();
                    for(int j = 0; j < m; j++) {
                        for(int i = n - 1; i >= 0; i--) {
                            if(temp[i][j] == 1) {
                                if(i == (n - 1)) {
                                    temp[i][j] = 0;
                                }
                                else {
                                    temp[i + 1][j] = 1;
                                    temp[i][j] = 0;
                                    tempList.push_back({(i + 1), j});
                                }
                            }
                        }
                    }
                }   
                ret = max(ret, sum);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}