#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<vector<int>> stickers(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n, 0));
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> stickers[i][j];
            }
        }
        
        if (n == 1) {
            cout << max(stickers[0][0], stickers[1][0]) << '\n';
            continue;
        }
        
        // 초기값 설정
        dp[0][0] = stickers[0][0];
        dp[1][0] = stickers[1][0];
        dp[0][1] = stickers[1][0] + stickers[0][1];
        dp[1][1] = stickers[0][0] + stickers[1][1];
        
        for (int j = 2; j < n; j++) {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + stickers[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + stickers[1][j];
        }
        
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    
    return 0;
}