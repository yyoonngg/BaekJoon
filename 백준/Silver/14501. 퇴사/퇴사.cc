#include<bits/stdc++.h>
using namespace std;
int n, dp[20], t[20], p[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for(int i = n; i >= 1; i--) {
        int next = i + t[i];
        if(next > n + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], p[i] + dp[next]);
        }
    }

    cout << dp[1] << "\n";

    return 0;
}