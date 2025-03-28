#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NUM = 1000000007;
ll n, dp[1000004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % NUM;
    }
    cout << dp[n] << "\n";
    return 0;
}