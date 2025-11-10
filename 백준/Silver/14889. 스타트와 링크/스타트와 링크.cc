#include <bits/stdc++.h>
using namespace std;

int n, a[24][24], bits, ret = 987654321;

int check(int _ret) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && (_ret & (1 << i)) && (_ret & (1 << j))) {
                sum += a[i][j];
            }
            if(i != j && !(_ret & (1 << i)) && !(_ret & (1 << j))) {
                sum -= a[i][j];
            }
        }
    }
    return abs(sum);
}

void go(int bit, int cnt, int last) {
    if(cnt == n/2) {
        ret = min(ret, check(bit));
        return;

    }   
    for(int i = last; i < (1 << n); i*=2) {
        if(!(bit & i)) {
            go((bit | i), cnt + 1, i*2);
        }
    }
    return;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0, 1);

    cout << ret << "\n";

    return 0;
}