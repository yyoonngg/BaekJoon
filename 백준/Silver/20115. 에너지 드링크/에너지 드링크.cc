#include <bits/stdc++.h>
using namespace std;
int n;
double a[100004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    double sum = a[n-1];
    for(int i = n - 2; i >= 0; i--) {
        sum += (double)(a[i] / 2);
    }
    cout << sum << "\n";
    return 0;
}