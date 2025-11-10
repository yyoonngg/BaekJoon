#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, dp[104][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    dp[1][0] = 1; dp[2][1] = 1; dp[3][0] = 1;
    dp[4][1] = 2; dp[5][0] = 2;
    for(int i = 6; i <= 100; i++) {
        int f = (i % 2) ^ 1;
        dp[i][f] = dp[i-1][(f^1)] + dp[i-5][(f^1)];
    }

    while(T--) {
        int n;
        cin >> n;
        cout << dp[n][(n % 2 ? 0 : 1)] << "\n";
    }    
    return 0;
}