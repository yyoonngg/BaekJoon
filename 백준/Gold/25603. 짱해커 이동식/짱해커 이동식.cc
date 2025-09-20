#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 9876543210;
ll n, k, a[100004], max_n, ret = MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        max_n = max(a[i], max_n);
    }

    ll low = 0, high = max_n;
    while(low <= high) {
        ll mid = (low + high) / 2;

        ll limit = 0, _ret = 0;
        for(ll i = 0; i < n; i++) {
            limit++;
            if(a[i] <= mid || limit >= k) {
                limit = 0;
                _ret = max(_ret, a[i]);
            }
        }

        if(_ret >= mid) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
        
        ret = min(ret, _ret);
    }

    cout << ret << "\n";
}