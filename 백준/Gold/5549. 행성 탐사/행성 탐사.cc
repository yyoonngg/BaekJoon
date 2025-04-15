#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, K;
    cin >> M >> N >> K;
    
    // 1-indexed 배열로 사용 (인덱스 0은 0으로 채워짐)
    const int MAX_M = 1001, MAX_N = 1001;
    int psumJ[MAX_M][MAX_N] = {0};
    int psumO[MAX_M][MAX_N] = {0};
    int psumI[MAX_M][MAX_N] = {0};

    // 지도 입력 및 2차원 누적합 배열 계산
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            cin >> c;
            psumJ[i][j] = psumJ[i-1][j] + psumJ[i][j-1] - psumJ[i-1][j-1] + (c == 'J');
            psumO[i][j] = psumO[i-1][j] + psumO[i][j-1] - psumO[i-1][j-1] + (c == 'O');
            psumI[i][j] = psumI[i-1][j] + psumI[i][j-1] - psumI[i-1][j-1] + (c == 'I');
        }
    }
    
    // 각 쿼리에 대해 영역 내 각 지형의 개수를 O(1)에 계산
    while(K--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int cntJ = psumJ[c][d] - psumJ[a-1][d] - psumJ[c][b-1] + psumJ[a-1][b-1];
        int cntO = psumO[c][d] - psumO[a-1][d] - psumO[c][b-1] + psumO[a-1][b-1];
        int cntI = psumI[c][d] - psumI[a-1][d] - psumI[c][b-1] + psumI[a-1][b-1];
        cout << cntJ << " " << cntO << " " << cntI << "\n";
    }
    
    return 0;
}
