#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string S;
    cin >> N >> M >> S;

    // 길이 len = 2N + 1 (P_N의 길이)
    int len = 2 * N + 1;
    int ret = 0;

    // 누적합 배열: IOI 패턴 매칭 여부 누적
    vector<int> psum(M + 1, 0);
    for (int i = 1; i < M; i++) {
        // IOI 중간 패턴이면 psum +1
        if (S[i-1] == 'I' && S[i] == 'O' && i + 1 < M && S[i+1] == 'I') {
            psum[i+1] = psum[i-1] + 1;
        } else {
            psum[i+1] = 0;
        }
    }

    // psum[i] == N이면 IOI가 N개 연속된 것
    for (int i = 0; i <= M; i++) {
        if (psum[i] >= N) ret++;
    }

    cout << ret << "\n";
    return 0;
}
