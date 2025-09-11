#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;
ll t, n, m;
ll dp[1004][1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    
    dp[0][0] = 1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = ((i >= 3 ? dp[i-3][j-1] % MOD: 0) + (i >= 2 ? dp[i-2][j-1] % MOD : 0) + dp[i-1][j-1] % MOD) % MOD;
        }
    }

    while(t--) {
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
}