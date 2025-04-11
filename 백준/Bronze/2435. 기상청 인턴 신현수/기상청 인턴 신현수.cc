#include <bits/stdc++.h>
using namespace std;
int n, k, a[104], psum[104], ret = -10004;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    for(int i = k; i <= n; i++) {
        int sum = psum[i] - psum[i - k];
        ret = max(ret, sum);
    }

    cout << ret << "\n";
    
    return 0;
}