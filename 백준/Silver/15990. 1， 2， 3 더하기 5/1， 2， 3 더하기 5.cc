#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll SIZE = 1000000009;
ll t, n;
ll dp[100004][4]; // n, l

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    // 초기화
    dp[1][1] = 1; dp[2][2] = 1; dp[3][3] = 1;

    for(int i = 2; i <= 100000; i++) {
        dp[i][1] = (dp[i-1][2] % SIZE + dp[i-1][3] % SIZE) % SIZE;
        if(i > 2) dp[i][2] = (dp[i-2][1] % SIZE + dp[i-2][3] % SIZE) % SIZE;
        if(i > 3) dp[i][3] = (dp[i-3][1] % SIZE + dp[i-3][2] % SIZE) % SIZE;
    }

    while(t--) {
        cin >> n;
        ll sum = 0;
        for(int i = 1; i <= 3; i++) {
            sum = (sum + dp[n][i] % SIZE) % SIZE;
        }
        cout << sum << "\n";
    }
}