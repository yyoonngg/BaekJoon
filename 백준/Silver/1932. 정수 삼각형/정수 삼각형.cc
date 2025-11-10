#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[504][504], dp[504][504];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 1+i; j++) {
            cin >> a[i][j];
        }
    }    

    dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i+1; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j] + a[i][j];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
        }
    }

    vector<ll> ret;
    for(int i = 0; i <= n; i++) {
        ret.push_back(dp[n-1][i]);
    }
    sort(ret.begin(), ret.end());
    cout << ret[n] << "\n";

    return 0;
}