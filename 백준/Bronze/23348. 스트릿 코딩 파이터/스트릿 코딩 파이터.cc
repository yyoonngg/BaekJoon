#include <bits/stdc++.h>
using namespace std;
int a, b, c, n, ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> n;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            int aa, bb, cc;
            cin >> aa >> bb >> cc;
            sum += (a*aa + b*bb + c*cc);
        }
        ret = max(ret, sum);
    }
    cout << ret << "\n";
}