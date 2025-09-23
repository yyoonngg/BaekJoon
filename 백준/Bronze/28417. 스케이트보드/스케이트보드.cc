#include <bits/stdc++.h>
using namespace std;
int n, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a1, a2;
        cin >> a1 >> a2;

        int a3[5];
        for(int j = 0; j < 5; j++) {
            cin >> a3[j];
        }
        sort(a3, a3 + 5);

        int sum = max(a1, a2) + a3[3] + a3[4];
        ret = max(ret, sum);
    }
    cout << ret << "\n";
}