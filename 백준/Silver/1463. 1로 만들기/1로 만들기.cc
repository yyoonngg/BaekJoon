#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, dp[1000004];

int go(int num) {
    if(num == 1) {
        return 1;
    }
    int &ret = dp[num];
    if(ret != INF) return ret;
    
    if(num % 3 == 0) {
        ret = min(ret, go(num / 3) + 1);
    }
    if(num % 2 == 0) {
        ret = min(ret, go(num / 2) + 1);
    }
    return ret = min(ret, go(num - 1) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    if(n == 1) {
        cout << 0 << "\n";
        exit(0);
    }
    fill(dp, dp+1000004, INF);
    cout << go(n) - 1 << "\n";

    return 0;
}