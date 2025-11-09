#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1000004], b, c, ret;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> b >> c;

    for(int i = 0; i < n; i++) {
        ll tmp = a[i];
        tmp -= b;
        ret++;
        if(tmp > 0) {
            ret += (ll)(tmp / c);
            if(tmp % c != 0) ret++;
        }
    }

    cout << ret << "\n";
 
    return 0;
}