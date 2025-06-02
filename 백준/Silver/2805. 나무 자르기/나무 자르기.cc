#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[1000004], maxH, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        maxH = max(maxH, a[i]);
    }

    ll l = 0, r = maxH;
    while(l <= r) {
        ll mid = (l + r) / 2;
        ll sum = 0;
        for(ll i = 0; i < n; i++) {
            sum += max((a[i] - mid), (ll)0);
        }
        if(sum < m) r = mid - 1;
        else {
            l = mid + 1;
            ret = max(ret, mid);
        }
    }   
    cout << ret << "\n";

    return 0;   
}