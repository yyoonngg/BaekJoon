#include <bits/stdc++.h>
using namespace std;
int n, a[1004][3], dp[1004][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + a[i][j];
        }
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";
    return 0;
}