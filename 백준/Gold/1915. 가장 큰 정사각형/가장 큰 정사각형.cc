#include <bits/stdc++.h>
using namespace std;
int n, m, a[1004][1004], dp[1004][1004], ret;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 1) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }
    }

    cout << ret * ret << "\n";
    

    return 0;
}