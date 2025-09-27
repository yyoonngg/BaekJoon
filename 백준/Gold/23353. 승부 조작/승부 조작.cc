#include <bits/stdc++.h>
using namespace std;

int n, a[1004][1004], ret;
vector<pair<int, int>> white;

// 연속 길이 DP
int L[1004][1004], R_[1004][1004];
int U[1004][1004], D_[1004][1004];
int UL[1004][1004], UR[1004][1004];
int DL[1004][1004], DR[1004][1004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) white.push_back({i, j});
        }
    }

    // 왼쪽, 위, \위왼, /위오 (좌->우, 상->하)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                L[i][j]  = (j ? L[i][j-1] : 0) + 1;
                U[i][j]  = (i ? U[i-1][j] : 0) + 1;
                UL[i][j] = (i && j ? UL[i-1][j-1] : 0) + 1;
                UR[i][j] = (i && j+1 < n ? UR[i-1][j+1] : 0) + 1;
            }else{
                L[i][j] = U[i][j] = UL[i][j] = UR[i][j] = 0;
            }
        }
    }

    // 오른쪽, 아래, \아래오, /아래왼 (우->좌, 하->상)
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(a[i][j] == 1){
                R_[i][j] = (j+1 < n ? R_[i][j+1] : 0) + 1;
                D_[i][j] = (i+1 < n ? D_[i+1][j] : 0) + 1;
                DR[i][j] = (i+1 < n && j+1 < n ? DR[i+1][j+1] : 0) + 1;
                DL[i][j] = (i+1 < n && j-1 >= 0 ? DL[i+1][j-1] : 0) + 1;
            }else{
                R_[i][j] = D_[i][j] = DR[i][j] = DL[i][j] = 0;
            }
        }
    }

    // 기존 보드 최장 (참고용)
    int base_max = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                base_max = max(base_max, L[i][j]);
                base_max = max(base_max, R_[i][j]);
                base_max = max(base_max, U[i][j]);
                base_max = max(base_max, D_[i][j]);
                base_max = max(base_max, UL[i][j]);
                base_max = max(base_max, DR[i][j]);
                base_max = max(base_max, UR[i][j]);
                base_max = max(base_max, DL[i][j]);
            }
        }
    }

    // 백돌 하나를 흑돌로 바꿀 때의 최장
    int best_with_flip = 1;
    for(auto &w : white){
        int y = w.first, x = w.second;

        // 가로
        int left  = (x-1 >= 0 ? L[y][x-1] : 0);
        int right = (x+1 < n ? R_[y][x+1] : 0);
        best_with_flip = max(best_with_flip, left + 1 + right);

        // 세로
        int up   = (y-1 >= 0 ? U[y-1][x] : 0);
        int down = (y+1 < n ? D_[y+1][x] : 0);
        best_with_flip = max(best_with_flip, up + 1 + down);

        // 대각선 
        int uleft = (y-1 >= 0 && x-1 >= 0 ? UL[y-1][x-1] : 0);
        int dright= (y+1 < n && x+1 < n ? DR[y+1][x+1] : 0);
        best_with_flip = max(best_with_flip, uleft + 1 + dright);

        // 대각선 /
        int uright= (y-1 >= 0 && x+1 < n ? UR[y-1][x+1] : 0);
        int dleft = (y+1 < n && x-1 >= 0 ? DL[y+1][x-1] : 0);
        best_with_flip = max(best_with_flip, uright + 1 + dleft);
    }

    ret = max(base_max, best_with_flip);
    cout << ret << '\n';
    return 0;
}
