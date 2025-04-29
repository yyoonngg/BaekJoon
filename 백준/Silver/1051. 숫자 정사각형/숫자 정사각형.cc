#include <bits/stdc++.h>
using namespace std;
int n, m, a[54][54], len;
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;
            a[i][j] = (int)(c -'0');
        }
    }

    len = min(n, m);
    while(len > 0) {
        for(int i = 0; i + len <= n; i++) {
            for(int j = 0; j + len <= m; j++) {
                if(a[i][j] == a[i][j + len - 1] && a[i][j] == a[i + len - 1][j] && a[i][j] == a[i + len - 1][j + len - 1]) {
                    cout << (len) * (len) << "\n";
                    return 0;
                }
            }
        }
        len--;
    }

    return 0;
}