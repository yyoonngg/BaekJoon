#include <iostream>
using namespace std;

int n, m, q;

// rain[i][0] = i일까지 들어온 물의 총합 (누적합)
// rain[i][1] = i일까지 증발된 물의 총합 (누적합)
int rain[100010][2];

// last[i][0] = i일에 증발이 종료되는 상자의 개수
// last[i][1] = i일에 증발이 종료될 때 마지막으로 증발되는 물의 양 (a[i] % m)
int last[100010][2];

int idx = 0;  // 현재 증발 중인 상자의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        // 누적 비의 양 저장 (i일까지 비의 총합)
        rain[i][0] = rain[i - 1][0] + num;

        // 기본적으로 이전날까지의 증발량을 복사
        rain[i][1] = rain[i - 1][1];

        // 오늘 날짜 i에, 증발이 끝나는 상자가 있다면:
        // → idx 감소 (증발 대상 제거)
        // → 해당 상자의 마지막 증발량을 총 증발량에 추가
        if (last[i][0] > 0) {
            idx -= last[i][0];
            rain[i][1] += last[i][1];
        }

        // 오늘 현재 증발 중인 상자 idx개에서 m씩 증발됨
        rain[i][1] += idx * m;

        // 증발 종료일 계산:
        // num만큼 들어온 물은 하루에 m씩 증발됨
        // → (num / m)일 동안 증발하고,
        //    마지막으로 남은 물 (num % m)은 그 다음 날에 증발 종료됨
        int nxt = i + (num / m) + 1;
        if (nxt <= n) {
            last[nxt][0]++;             // 그날에 증발 종료될 상자 수 증가
            last[nxt][1] += num % m;    // 마지막 남은 증발량 등록
        }

        // 새로운 상자 하나 추가 (내일부터 증발 시작 대상)
        idx++;
    }

    // 쿼리 처리
    for (int i = 0; i < q; i++) {
        int command, t;
        cin >> command >> t;

        if (command == 1) {
            // type 1: 남아있는 물 = 비의 총합 - 증발량
            cout << rain[t][0] - rain[t][1] << "\n";
        } else {
            // type 2: 오늘 하루 동안 증발된 양 = 누적증발[t] - 누적증발[t-1]
            cout << rain[t][1] - rain[t - 1][1] << "\n";
        }
    }

    return 0;
}
