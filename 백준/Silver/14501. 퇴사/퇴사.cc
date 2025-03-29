#include <bits/stdc++.h>
using namespace std;

int n;
int t[16], p[16], dp[16];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    // DP 배열 초기화 (안 하면 쓰레기 값이 들어갈 수도 있음)
    memset(dp, 0, sizeof(dp));

    // 뒤에서부터 DP 계산
    for (int i = n; i >= 1; i--) {
        int nextDay = i + t[i];  // 현재 상담을 끝낸 다음 날

        if (nextDay > n + 1) {   // 퇴사일을 넘어가면 상담 불가능
            dp[i] = dp[i + 1]; 
        } else {
            // 상담을 안 하는 경우 vs 상담을 하는 경우 중 최댓값 선택
            dp[i] = max(dp[i + 1], p[i] + (nextDay <= n ? dp[nextDay] : 0));
        }
    }

    cout << dp[1] << "\n";  // 1일부터 시작했을 때 최대 이익 출력
    return 0;
}
