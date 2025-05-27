#include<bits/stdc++.h>
using namespace std;
const int MAX = 987654321;
int n, m, a[54][54], visited[54][54], chicken_max, ret = MAX;
vector<pair<int, int>> home_list, chicken_list;

void check(vector<pair<int, int>> &now) {
    int _ret = 0;
    for(auto home : home_list) {
        int demin = MAX;
        for(auto chicken : now) {
            demin = min(demin, (abs(home.first - chicken.first) + abs(home.second - chicken.second)));
        }
        _ret += demin;
    }
    ret = min(ret, _ret);
}

void go(int idx, vector<pair<int, int>> &now) {
    if(idx > chicken_max) return;
    if((int)now.size() == m) {
        check(now);
        return;
    }
    now.push_back({chicken_list[idx].first, chicken_list[idx].second});
    go(idx + 1, now);
    now.pop_back();
    go(idx + 1, now);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) {
                chicken_max++;
                chicken_list.push_back({i, j});
            }
            else if(a[i][j] == 1) {
                home_list.push_back({i, j});
            }
        }
    }
    
    vector<pair<int, int>> now;
    go(0, now);

    cout << ret << "\n";

    return 0;
}