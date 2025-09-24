#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l, r, visited[100004], dp[100004];

int go(int x) {
    int &_ret = dp[x];
    if(_ret != -2) return _ret;
    if(visited[x] == 1) return _ret = 0;
    visited[x] = 1;

    int xx = x;
    int s = 0, c = 1;
    while(xx / 10 > 0) {
        s += (xx % 10);
        c *= (xx % 10);
        xx /= 10;
    }
    s += xx; c *= xx;
    int tmp = atoi((to_string(s)+to_string(c)).c_str());

    int res;
    if(x == tmp) res = 1;
    else if(tmp > 100000) res = -1;
    else res = go(tmp);

    visited[x] = 2;
    return _ret = res;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> l >> r;
    fill(dp, dp+100004, -2);

    ll ret = 0;
    for(int i = l; i <= r; i++) {
        ret += go(i);
    }

    cout << ret << "\n";
    return 0;
}