#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    if (m == 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long current_sum = 0, max_sum = 0;

    for (int i = 0; i < m; ++i) {
        current_sum += t[i];
    }
    max_sum = current_sum;

    for (int i = m; i < n; ++i) {
        current_sum += t[i] - t[i - m];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";
    return 0;
}
