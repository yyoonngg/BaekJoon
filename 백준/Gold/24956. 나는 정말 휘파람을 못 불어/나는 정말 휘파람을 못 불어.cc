#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll n, dp[4];
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        if(c == 'W') dp[0] += 1;
        else if(c == 'H') dp[1] += dp[0];
        else if(c == 'E') {
            dp[3] = (dp[3] % mod) + (dp[3] % mod);
            dp[3] = (dp[3] % mod) + (dp[2] % mod);
            dp[2] = (dp[2] % mod) + (dp[1] % mod);
        }
    }

    cout << dp[3] % mod << "\n";

    return 0;
}