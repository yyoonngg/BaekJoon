#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;
    
    int a_len = A.size();
    int b_len = B.size();

    for(int i = 1; i <= a_len; i++) {
        for(int j = 1; j <= b_len; j++) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[a_len][b_len] << "\n";
    return 0;
}