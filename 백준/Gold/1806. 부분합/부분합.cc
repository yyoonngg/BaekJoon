#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 987654321;
ll n, s, a[100004], psum[100004], l = 1, r = 1, ret = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    while(l <= r && r <= n) {
        ll sum = psum[r] - psum[l - 1];
        if(sum >= s) {
            ret = min(ret, (r - l + 1));
        }
        if(sum <= s) r++;
        else l++;
    }

    cout << (ret == INF ? 0 : ret) << "\n";
    return 0;
}