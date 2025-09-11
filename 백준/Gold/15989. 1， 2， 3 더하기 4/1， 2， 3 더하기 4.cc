#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> qs(T);
    int maxN = 0;
    for (int i = 0; i < T; ++i) {
        cin >> qs[i];
        maxN = max(maxN, qs[i]);
    }

    const int K = 3;
    // ways[n][k] = 1..k만 사용해 n을 만드는 방법 수 (순서 무시)
    vector<array<long long, K + 1>> ways(maxN + 1, {0,0,0,0});

    // 0을 만드는 방법: 아무 것도 안 쓰기 -> 1가지
    for (int k = 1; k <= K; ++k) ways[0][k] = 1;

    for (int n = 1; n <= maxN; ++n) {
        // k = 1: 1만 사용 가능 -> 항상 1가지 (전부 1로 채우기)
        ways[n][1] = 1;

        // k = 2: 2를 쓰지 않는 경우(=ways[n][1]) + 2를 적어도 한 번 쓰는 경우(=ways[n-2][2])
        ways[n][2] = ways[n][1] + (n >= 2 ? ways[n - 2][2] : 0);

        // k = 3: 3을 쓰지 않는 경우(=ways[n][2]) + 3을 적어도 한 번 쓰는 경우(=ways[n-3][3])
        ways[n][3] = ways[n][2] + (n >= 3 ? ways[n - 3][3] : 0);
    }

    for (int n : qs) {
        cout << ways[n][3] << '\n';
    }
    return 0;
}
