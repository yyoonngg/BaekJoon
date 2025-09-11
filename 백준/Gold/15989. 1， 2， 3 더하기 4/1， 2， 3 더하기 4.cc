#include <bits/stdc++.h>
using namespace std;
int dp[10004][4];
int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    dp[0][1] = 1; dp[0][2] = 1; dp[0][3] = 1;
    for(int i = 1; i <= 10000; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i][1] + (i >= 2 ? dp[i - 2][2] : 0);
        dp[i][3] = dp[i][2] + (i >= 3 ? dp[i - 3][3] : 0);
    }

    while(t--) {
        cin >> n;
        cout << dp[n][3] << "\n";
    }    
}