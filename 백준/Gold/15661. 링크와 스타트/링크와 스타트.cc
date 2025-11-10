#include <bits/stdc++.h>
using namespace std;

int N;
int S[21][21];
long long ans = LLONG_MAX;

vector<int> A, B;          // 현재 팀 구성
long long sumA = 0, sumB = 0; // 각 팀 시너지 합(쌍 합)

void dfs(int i) {
    if (i == N) {
        if (!A.empty() && !B.empty()) {
            ans = min(ans, llabs(sumA - sumB));
        }
        return;
    }

    // i를 A팀에 넣기: 기존 A의 모든 j와 쌍 시너지 더함
    long long addA = 0;
    for (int j : A) addA += S[i][j] + S[j][i];
    A.push_back(i);
    sumA += addA;
    dfs(i + 1);
    sumA -= addA;
    A.pop_back();

    // i를 B팀에 넣기
    long long addB = 0;
    for (int j : B) addB += S[i][j] + S[j][i];
    B.push_back(i);
    sumB += addB;
    dfs(i + 1);
    sumB -= addB;
    B.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> S[i][j];

    // 대칭 가지 절반으로 줄이기: 0번을 A팀에 고정
    A.push_back(0);
    dfs(1);

    cout << ans << "\n";
    return 0;
}
