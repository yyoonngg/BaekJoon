#include <bits/stdc++.h>
using namespace std;
int dp[10004][3];
int t, n;

int go(int num, int m) {
    if(num == 0) return 1;
    if(num < 0) return 0;

    int _ret = 0;

    for(int i = 1; i <= m; i++) {
        if(i != m && (num - m) == 0) continue;
        int &ret = dp[num - m][i];
        if(ret != -1) _ret += ret;
        else ret = go(num - m, i), _ret += ret;
    }

    return _ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    fill(&dp[0][0], &dp[0][0] + 10004 * 3, -1);
    dp[0][1] = 1; dp[0][1] = 1; dp[0][1] = 1;

    while(t--) {
        cin >> n;
        int sum = 0;

        for(int i = 1; i <= 3; i++) {
            sum += go(n, i);
        }
        cout << sum << "\n";
    }    
}