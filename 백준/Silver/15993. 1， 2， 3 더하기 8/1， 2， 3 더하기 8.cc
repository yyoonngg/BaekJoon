#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;
ll t, n;
ll dp[100004][2];
pair<ll, ll> ret;

pair<ll, ll> go(int num) {
    ll &ret1 = dp[num][0], &ret2 = dp[num][1];
    if(ret1 != -1 || ret2 != -1) return {ret1, ret2};
    
    ret1 = 0, ret2 = 0;
    ll temp_o, temp_e;

    for(int i = 1; i <= 3; i++) {
        if(num - i < 0) continue;
        tie(temp_o, temp_e) = go(num - i);
        ret1 = (ret1 + temp_e) % MOD; ret2 = (ret2 + temp_o) % MOD;
    }
    return {ret1 % MOD, ret2 % MOD};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 1; dp[0][0] = 0; dp[1][0] = 1; dp[1][1] = 0;

    while(t--) {
        cin >> n;
        ret = go(n);
        cout << ret.first << " " << ret.second << "\n";        
    }
}