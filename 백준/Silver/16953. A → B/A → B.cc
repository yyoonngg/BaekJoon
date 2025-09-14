#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 9999999999;
ll a, b, ret = MAX;
map<ll, ll> mp;

void go(ll n, ll cnt) {
    if(n == a) {
        ret = min(ret, cnt);
        return;
    }
    if(n < a) return;

    if(n % 2 == 0) go(n / 2, cnt + 1);
    else {
        string n1 = to_string(n);
        if(n1[n1.size() - 1] == '1') {
            go(atoi(n1.substr(0, n1.length() - 1).c_str()), cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;

    go(b, 1);

    if(ret == MAX) cout << -1 << "\n";
    else cout << ret << "\n";
}