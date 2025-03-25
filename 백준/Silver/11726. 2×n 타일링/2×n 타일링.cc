#include <bits/stdc++.h>
using namespace std;
int n, a[1004];

int main() {
    cin >> n;
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] % 10007 + a[i - 2] % 10007) % 10007;
    }

    cout << a[n] << "\n";
    return 0;
}