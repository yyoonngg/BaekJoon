#include <bits/stdc++.h>
using namespace std;

int n, m, l, s[1004], q[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> l;
    for (int i = 0; i < m; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> q[i];

    for (int t = 0; t < n; t++) {
        int low = 1, high = l;      // mid=0은 항상 참이므로 1부터 시작
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            int last = 0;
            int pieces = 0;         // "조각 수"를 센다 (길이 >= mid 인 조각만)

            for (int i = 0; i < m; i++) {
                if (s[i] - last >= mid) {
                    pieces++;
                    last = s[i];
                }
            }
            if (l - last >= mid) pieces++;   // 마지막 조각도 mid 기준으로만 포함

            if (pieces >= q[t] + 1) {
                // mid 길이로 Q번 잘라 Q+1조각(모두 mid 이상) 가능 → 더 크게 도전
                ans = mid;          // 정답 후보는 mid 자체
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << '\n';
    }
}
