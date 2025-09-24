#include<bits/stdc++.h>
using namespace std;
int n, a, d, g, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> d >> g;
        int dg = d + g;
        if(a == dg) ret = max(ret, 2*a*a);
        else ret = max(ret, a*dg);
    }
    cout << ret << "\n";
}