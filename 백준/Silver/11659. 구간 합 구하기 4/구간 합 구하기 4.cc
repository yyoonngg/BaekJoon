#include <bits/stdc++.h>
using namespace std;
int n, m, a[100004], psum[100004], i, j;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }    
    while(m--) {
        cin >> i >> j;
        cout << psum[j] - psum[i - 1] << "\n";
    }
    return 0;
}