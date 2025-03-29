#include <bits/stdc++.h>
using namespace std;
int n, m, k, ky, kx, dp[20][20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    if(k == 0) {
        ky = n - 1;
        kx = m - 1;
    }
    else {
        ky = (k - 1) / m;
        kx = (k - 1) % m;
    }
    fill(&dp[0][0], &dp[0][0] + 20 * 20, 1);

    for(int i = 1; i <= ky; i++) {
        for(int j = 1; j <= kx; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    if(k != 0) {
        fill(&dp[0][0], &dp[0][0] + 20 * 20, dp[ky][kx]);

        for(int i = ky + 1; i < n; i++) {
            for(int j = kx + 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}