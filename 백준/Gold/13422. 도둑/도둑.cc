#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, k, a[200004], psum[200004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        fill(a, a + 200004, 0);
        fill(psum, psum + 200004, 0);
        cin >> n >> m >> k;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            psum[i] = psum[i - 1] + a[i];
        }
        for(int i = n + 1; i < n + m; i++) {
            psum[i] = psum[i - 1] + a[i - n];
        }

        if(n == m) {
            if(psum[n] < k) cout << "1\n";
            else cout << "0\n";
            continue;
        }

        ll l = 1, r = m, ret = 0;
        while(r < n + m) {
            ll sum = psum[r] - psum[l - 1];
            if(sum < k) ret++;
            l++; r++;
        }
        cout << ret << "\n";
    }
    return 0;
}