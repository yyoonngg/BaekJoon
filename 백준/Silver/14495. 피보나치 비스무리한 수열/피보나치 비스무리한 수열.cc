#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, dp[120];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    cout << dp[n] << "\n";
    return 0;
}