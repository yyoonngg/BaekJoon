#include <bits/stdc++.h>
using namespace std;
int n, k, ret;
int a[8], r[6][8], m[6][8];

void go(int date, int sum) {
    if(date == k) {
        ret = max(ret, sum);
        return;
    }
    // 완탐
    for(int i = 0; i < n; i++) {
        if(a[i] <= 0) continue;

        a[i]--;
        
        for(int j = 0; j < n; j++) {
            if(a[j] <= 0) continue;

            a[j]--;
            go(date+1, sum+r[date][i]+m[date][j]);
            a[j]++;
        }
        a[i]++;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    // 각 캔의 갯수
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 각 k날마다 랑이의 각 캔에 대한 만족도
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> r[i][j];
        }
    }

    // 각 k날마다 메리의 각 캔에 대한 만족도
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    // 완탐
    go(0, 0);

    cout << ret << "\n";
}