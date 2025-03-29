#include <bits/stdc++.h>
using namespace std;
int n, s, m, a[54], dp[54][1004], ret = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][s] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            if(dp[i][j]) {
                if(j + a[i] <= m) dp[i + 1][j + a[i]] = 1;
                if(j - a[i] >= 0) dp[i + 1][j - a[i]] = 1;
            }
        }
    }
    for(int i = 0; i <= m; i++) {
        if(dp[n][i]) ret = max(ret, i);
    }

    cout << ret << "\n";

    return 0;
}