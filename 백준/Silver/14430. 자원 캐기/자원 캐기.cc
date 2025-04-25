#include <bits/stdc++.h>
using namespace std;
int n, m, a[304][304], dp[304][304];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i][j] == 1) dp[i][j]++;
        }
    }

    cout << dp[n][m] << "\n";
    
    return 0;   
}