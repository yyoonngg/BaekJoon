#include <bits/stdc++.h>
using namespace std;
int l, r, visited[100004], ret;

void go(int x) {
    int xx = x;
    int s = 0, c = 1;
    while(xx / 10 > 0) {
        s += (xx % 10);
        c *= (xx % 10);
        xx /= 10;
    }

    s += xx; c *= xx;
    int _ret = atoi((to_string(s)+to_string(c)).c_str());

    // cout << x << " " << _ret << "\n";

    // 1. f(x) = x -> 1
    if(x == _ret) {
        ret += 1;
    }
    // 2. x > 100 000 -> -1
    else if(_ret > 100000) {
        ret -= 1;
    }
    else {
        if(visited[_ret]) {
            return;
        }
        visited[_ret]++;
        go(_ret);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
        memset(visited, 0, sizeof(visited));
        go(i);
    }

    cout << ret << "\n";
    return 0;
}