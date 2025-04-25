#include <bits/stdc++.h>
using namespace std;

int n;
bool dp[1004]; // true면 상근 승리, false면 창영 승리

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[0] = false; // 돌이 없으면 상근이 패배
    for (int i = 1; i <= n; i++) {
        // 돌 1개 또는 3개 가져갔을 때 상대방이 패배하는 경우가 있으면, 이김
        if (i - 1 >= 0 && !dp[i - 1]) dp[i] = true;
        else if (i - 3 >= 0 && !dp[i - 3]) dp[i] = true;
        else dp[i] = false; // 둘 다 아니면 패배
    }

    cout << (dp[n] ? "SK" : "CY") << "\n";
}