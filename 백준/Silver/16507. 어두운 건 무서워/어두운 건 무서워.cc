#include <bits/stdc++.h>
using namespace std;
int r, c, q, a[1004][1004], psum[1004][1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> q;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
            psum[i][j] = psum[i][j - 1] + a[i][j];
        }
    }

    int r1, r2, c1, c2;
    while(q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        int sum = 0;
        for(int i = r1; i <= r2; i++) {
            sum += (psum[i][c2] - psum[i][c1 - 1]);
        }
        cout << sum / ((r2 - r1 + 1) * (c2 - c1 + 1)) << "\n";
    }
    return 0;
}