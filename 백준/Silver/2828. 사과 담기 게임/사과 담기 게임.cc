#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

int n, m, j, pos, ret;
int s, e;

void go(int p) {
    if(p > s && p <= e) return;

    if(p <= s) {
        s--; e--;
        go(p);
        ret++;
    }
    else if(p > e) {
        s++; e++;
        go(p);
        ret++;
    }
    return;
}

int main() {
    cin >> n >> m >> j;
    s = 0;
    e = m;

    while(j--) {
        cin >> pos;
        go(pos);
    }

    cout << ret;
    
    return 0;
}