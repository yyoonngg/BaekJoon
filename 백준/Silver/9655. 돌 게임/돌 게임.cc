#include <bits/stdc++.h>
using namespace std;
int n, dp[1004], turn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    fill(dp, dp + 1004, -1);
    for(int i = 0; i < n; i++) {
        if(dp[i] != -1) continue;
        dp[i] = turn;
        dp[i + 2] = turn;
        turn ^= 1;
    }
    if(dp[n - 1] == 0) cout << "SK\n";
    else cout << "CY\n";
    return 0;
}