#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, odd, even;

void go(ll a, ll b) {
    cout << a - b << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a;
        if(i % 2) odd += a;
        else even += a;
    }    


    if(odd == even) {
        cout << "0\n";
        return 0;
    }
    else if(n == 3 && odd > even) cout << "-1\n";
    else if(odd > even) go(odd, even);
    else go(even, odd);

    return 0;
}