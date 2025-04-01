#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s[14], b[14], ret = 1000000004;

void go(ll sSum, ll bSum, int cnt) {
    if(cnt == n) {
        if(sSum != 1 && bSum != 0) ret = min(ret, abs(sSum - bSum));
        return;
    }
    go(sSum * s[cnt], bSum + b[cnt], cnt + 1);
    go(sSum, bSum, cnt + 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }

    if(n == 1) {
        cout << abs(s[0] - b[0]) << "\n";
        exit(0);
    }
    
    go(1, 0, 0);

    cout << ret << "\n";
    return 0;
}