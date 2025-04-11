#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, a[1000004], xsum[1000004], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        xsum[i] = xsum[i - 1] ^ a[i];
    }
    while(q--) {
        ll s, e;
        cin >> s >> e;
        ret ^= (xsum[e] ^ xsum[s - 1]);
    }
    cout << ret << "\n";
    return 0;
}
