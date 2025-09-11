#include <bits/stdc++.h>
using namespace std;
int dp[10004][4];
int t, n;

int go(int num, int m) {
    if(num == 0) return 1;
    if(num < 0 || m == 0) return 0;

    int &ret = dp[num][m];
    if(ret != -1) return ret;

    ret = go(num, m - 1) + go(num - m, m);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    memset(dp, -1, sizeof(dp));

    while(t--) {
        cin >> n;
        cout << go(n, 3) << "\n";
    }    
}