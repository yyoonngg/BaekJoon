#include <bits/stdc++.h>
using namespace std;
int n, a[10], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    do {
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += abs(a[i] - a[i + 1]);
        }
        ret = max(ret, sum);
    } while(next_permutation(a, a + n));

    cout << ret << "\n";

    return 0;
}
