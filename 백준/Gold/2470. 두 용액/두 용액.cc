#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100004], l, r, ret = 9876543210, ret1, ret2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    l = 0, r = n - 1;

    while(l < r) {
        ll sum = a[l] + a[r];
        if(abs(sum) < abs(ret)) {
            ret = sum;
            ret1 = a[l];
            ret2 = a[r];
        }
        if(sum < 0) l++;
        else if(sum >= 0) r--;
    }

    if(ret1 < ret2) cout << ret1 << " " << ret2 << "\n";
    else cout << ret2 << " " << ret1 << "\n";
}