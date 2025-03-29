#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, dp[50004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    fill(&dp[0], &dp[0] + 50004, INF);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}