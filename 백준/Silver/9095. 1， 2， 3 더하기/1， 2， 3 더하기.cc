#include <bits/stdc++.h>
using namespace std;
int t, n, ret;

void go(int m) {
    if(m > n) return;
    if(m == n) {
        ret++;
        return;
    }
    go(m + 1);
    go(m + 2);
    go(m + 3);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        ret = 0;
        go(0);
        cout << ret << "\n";
    }
    return 0;   
}