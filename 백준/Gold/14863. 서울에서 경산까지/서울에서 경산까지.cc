#include <bits/stdc++.h>
using namespace std;

int n, k, w1, w2, b1, b2, ret;
int dp[101][100001];
vector<pair<int, int>> walk, bicycle;

int go(int here, int _time) {
    if(here == n) return 0;
    int &ret = dp[here][_time];
    if(ret) return ret;
    ret = -1e6;
    if(_time - walk[here].first >= 0) ret = max(ret, go(here + 1, _time - walk[here].first) + walk[here].second);
    if(_time - bicycle[here].first >= 0) ret = max(ret, go(here + 1, _time - bicycle[here].first) + bicycle[here].second);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w1 >> w2 >> b1 >> b2;
        walk.push_back({w1, w2});
        bicycle.push_back({b1, b2});        
    }

    cout << go(0, k) << "\n";

    return 0;
}