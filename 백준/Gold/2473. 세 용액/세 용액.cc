#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    ll best_sum = LLONG_MAX; // 최적 합(부호 포함)
    ll x = 0, y = 0, z = 0;  // 정답 트리플

    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            ll s = a[i] + a[l] + a[r];
            if (llabs(s) < llabs(best_sum)) {
                best_sum = s;
                x = a[i]; y = a[l]; z = a[r];
                if (best_sum == 0) { // 최적
                    // 더 나아질 수 없으므로 바로 종료해도 OK
                }
            }
            if (s < 0) ++l;
            else --r;
        }
        if (best_sum == 0) break; // 전역 종료(선택)
    }

    vector<ll> ans = {x, y, z};
    sort(ans.begin(), ans.end());
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    return 0;
}
