#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[1000004], psum[1000004], cnt[1001], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = (psum[i - 1] + a[i]) % m;
        cnt[psum[i]]++;
    }

    ret += cnt[0];

    for(int i = 0; i < m; i++) {
        if(cnt[i] >= 2) {
            ret += (cnt[i] * (cnt[i] - 1)) / 2;
        }
    }

    cout << ret << "\n";

    return 0;   
}