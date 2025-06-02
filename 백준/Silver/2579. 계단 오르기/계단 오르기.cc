#include <bits/stdc++.h>
using namespace std;
int n, a[304], dp[3][304];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1][0] = 0;

    for(int i = 1; i <= n; i++) {
        if(i - 2 >= 0) {
            dp[1][i] = max(dp[1][i - 2], dp[2][i - 2]) + a[i];
        }
        else dp[1][i] = a[i];
        if(i - 1 >= 0) {
            dp[2][i] = dp[1][i - 1] + a[i];
        }
    }

    cout << max(dp[1][n], dp[2][n]) << "\n";

    return 0;   
}