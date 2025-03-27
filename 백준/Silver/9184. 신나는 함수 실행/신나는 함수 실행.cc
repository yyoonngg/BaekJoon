#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[54][54][54];

int go(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    int &ret = dp[a][b][c];
    if(ret != INF) return ret;

    if(a > 20 || b > 20 || c > 20) return ret = go(20, 20, 20);

    if(a < b && b < c) return ret = go(a, b, c - 1) + go(a, b - 1, c - 1) - go(a, b - 1, c);

    return ret = go(a - 1, b, c) + go(a - 1, b - 1, c) + go(a - 1, b, c - 1) - go(a - 1, b - 1, c - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&dp[0][0][0], &dp[0][0][0] + 54*54*54, INF);
    while(true) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << go(a, b, c) << '\n';
    }
    return 0;
}