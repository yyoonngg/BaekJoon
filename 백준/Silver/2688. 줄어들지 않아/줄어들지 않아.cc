#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, dp[68][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 10; i++) dp[0][i] = 1;
    for(int i = 1; i < 64; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    while(T--) {
        cin >> n;
        ll ret = 0;
        for(int i = 0; i < 10; i++) {
            ret += dp[n - 1][i];
        }
        cout << ret << "\n";
    }    
    return 0;
}