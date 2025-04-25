#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[4004][4004], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2;
    int n = (int)s1.size(), m = (int)s2.size();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, 1);
            }
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret << "\n";
    return 0;   
}