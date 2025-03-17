#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[44][44], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> t;
    for(int i = 0; i <= n - 3; i++) {
        for(int j = 0; j <= m - 3; j++) {
            vector<int> v;
            for(int x = i; x < i + 3; x++) {
                for(int y = j; y < j + 3; y++) {
                    v.push_back(a[x][y]);
                }
            }
            sort(v.begin(), v.end());
            if(v[4] >= t) ret++;
        }
    }
    cout << ret << "\n";

    return 0;
}