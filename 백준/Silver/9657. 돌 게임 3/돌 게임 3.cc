#include <bits/stdc++.h>
using namespace std;
int n;
bool dp[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(i - 1 >= 0 && !dp[i - 1]) dp[i] = true;
        else if(i - 3 >= 0 && !dp[i - 3]) dp[i] = true;
        else if(i - 4 >= 0 && !dp[i - 4]) dp[i] = true;
        else dp[i] = false;
    }

    if(dp[n]) cout << "SK\n";
    else cout << "CY\n";
     
    return 0;
}