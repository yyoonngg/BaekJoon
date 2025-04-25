#include <bits/stdc++.h>
using namespace std;
string s1, s2, lcs;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2;
    int n = (int)s1.size(), m = (int)s2.size();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << "\n";

    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            lcs += s1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());

    if(!lcs.empty()) cout << lcs << "\n";

    return 0;   
}