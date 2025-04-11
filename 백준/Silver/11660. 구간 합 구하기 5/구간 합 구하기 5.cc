#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[1028][1028], psum[1028][1028];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            psum[i][j] = psum[i][j - 1] + a[i][j];
        }
    }
    int x1, y1, x2, y2;
    while(m--) {
        cin >> y1 >> x1 >> y2 >> x2;
        ll sum = 0;
        for(int i = y1; i <= y2; i++) {
            sum += (psum[i][x2] - psum[i][x1 - 1]);
        }
        cout << sum << "\n";
    }
    return 0;
}
