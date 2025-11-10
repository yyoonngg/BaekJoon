#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, dp[104];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    while(T--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }    
    return 0;
}