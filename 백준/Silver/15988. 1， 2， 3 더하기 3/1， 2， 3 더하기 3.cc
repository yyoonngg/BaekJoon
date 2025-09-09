#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
typedef long long ll;
ll d[1000010];
int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i  = 4; i <= 1000000; i++) {
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % MOD;
    }

    while(t --) {
        cin >> n;
        cout << d[n] << "\n";
    }
}