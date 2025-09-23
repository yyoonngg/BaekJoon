#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, a[100004];
map<int, int> mp;

void check(int x) {
    if(x == 0) {
        int zero = mp[0];
        int nonzero = n - zero;
        cout << ((zero >= 2) || (zero >= 1 && nonzero >= 1)) << "\n";
        return;
    } 

    for(int d = 1; d <= 10000; d++) {
        if(x % d) continue;
        int e = x / d;

        if(d == e) {
            if(mp[d] >= 2) { cout << 1 << "\n"; return; }
        }
        else {
            if(mp[d] >= 1 && mp[e] >= 1) { cout << 1 << "\n"; return; }
        }
    }
    cout << 0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    while(q--) {
        int b, c;
        cin >> b >> c;
        if(b == 1) {
            check(c);
        }
        else {
            int idx = c - 1;
            if(a[idx] != 0) {
                mp[a[idx]]--;
                mp[0]++;
                a[idx] = 0;
            }
        }
    }

    return 0;
}