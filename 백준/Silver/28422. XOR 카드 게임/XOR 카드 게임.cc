#include <bits/stdc++.h>
using namespace std;
const int MIN = -987654321;
int n, a[100004], dp[100004];

int check(int tmp) {
    int s = 0;
    while(tmp > 1) {
        if(tmp % 2) s++;   
        tmp /= 2;
    }
    if(tmp) s++;
    return s;
}

int go(int x) {
    if(x == 1) return MIN;
    if(x == 0) return 0;
    int &ret = dp[x];
    if(ret != -1) return ret;

    ret = max(go(x-2)+check(a[x]^a[x-1]), go(x-3)+check(a[x]^a[x-1]^a[x-2]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];    

    int ret = go(n);
    if(ret == MIN) cout << 0 << "\n";
    else cout << ret << "\n";

    return 0;
}