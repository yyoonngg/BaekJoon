#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;
ll t, n;
ll dp[100004][2]; // n, k

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    // 초기화
    dp[0][0] = 0; dp[0][1] = 0;
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 1;
    dp[3][0] = 0; dp[3][1] = 2;
    dp[4][0] = 2; dp[4][1] = 1;
    dp[5][0] = 0; dp[5][1] = 3;
    dp[6][0] = 4; dp[6][1] = 2;

    for(int i = 7; i <= 100000; i++) {
        dp[i][0] = (dp[i-2][0] % MOD + dp[i-4][0] % MOD + dp[i-6][0] % MOD) % MOD;
        dp[i][1] = (dp[i-2][1] % MOD + dp[i-4][1] % MOD + dp[i-6][1] % MOD) % MOD;
    }

    while(t--) {
        cin >> n;
        ll sum = 0;
        for(int i = 0; i <= 1; i++) {
            sum = (sum + dp[n][i] % MOD) % MOD;
        }
        cout << sum << "\n";
    }
}