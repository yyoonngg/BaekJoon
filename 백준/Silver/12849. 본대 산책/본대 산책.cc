#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll D, prev_dp[8], cur_dp[8];
vector<int> adj[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> D;

    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1, 3, 4};
    adj[3] = {1, 2, 4, 6};
    adj[4] = {2, 3, 5, 6};
    adj[5] = {4, 7};
    adj[6] = {3, 4, 7};
    adj[7] = {5, 6};
    
    prev_dp[0] = 1;

    for(int i = 1; i <= D; i++) {
        fill(cur_dp, cur_dp + 8, 0);
        for(int j = 0; j < 8; j++) {
            for(int there : adj[j]) {
                cur_dp[there] = (cur_dp[there] + prev_dp[j]) % MOD;
            }
        }
        swap(prev_dp, cur_dp);
    }

    cout << prev_dp[0] << "\n";
    
    return 0;
}