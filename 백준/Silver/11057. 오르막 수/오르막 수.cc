#include <bits/stdc++.h>
using namespace std;
int n, dp[10][1004], ret;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    // dp[0][1] ~ dp[9][1]
    for(int i = 0; i <= 9; i++) {
        dp[i][1] = 1;
    }

    // dp[0][2] ~ dp[9][n]
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= j; k++) {
                dp[j][i] = (dp[j][i] + dp[k][i - 1]) % 10007;  
            }
        }
    }

    for(int i = 0; i <= 9; i++) {
        ret = (ret + dp[i][n]) % 10007;
    }

    cout << ret << "\n";
    return 0;
}