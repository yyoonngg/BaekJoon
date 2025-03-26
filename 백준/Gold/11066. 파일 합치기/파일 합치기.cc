#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int t, k, psum[504], dp[504][504];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> k;
        vector<int> v(k + 4);

        for(int i = 1; i <= k; i++) {
            cin >> v[i];
            psum[i] = psum[i - 1] + v[i];
        }

        for(int len = 2; len <= k; len++) {
            for(int i = 1; i + len - 1 <= k; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;

                for(int mid = i; mid < j; mid++) {
                    dp[i][j] = min(dp[i][j], (dp[i][mid] + dp[mid + 1][j]) + (psum[j] - psum[i - 1]));
                }
            }
        }
        
        cout << dp[1][k] << "\n";
    }
    return 0;
}