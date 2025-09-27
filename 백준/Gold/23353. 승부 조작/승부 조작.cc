#include <bits/stdc++.h>
using namespace std;

int n, a[1004][1004];

// 라인별 구간 길이 조회용 해시: end->len, start->len
vector<unordered_map<int, int>> row_end, row_st;
vector<unordered_map<int, int>> col_end, col_st;
vector<unordered_map<int, int>> d1_end, d1_st; // \ 대각선 (i - j = const), 인덱스: k = i-j + (n-1), 키는 i
vector<unordered_map<int, int>> d2_end, d2_st; // / 대각선 (i + j = const), 인덱스: s = i+j, 키는 i

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int,int>> white;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) white.push_back({i, j});
        }
    }

    row_end.assign(n, {});
    row_st.assign(n, {});
    col_end.assign(n, {});
    col_st.assign(n, {});
    d1_end.assign(2*n-1, {});
    d1_st.assign(2*n-1, {});
    d2_end.assign(2*n-1, {});
    d2_st.assign(2*n-1, {});

    int base_max = 1;

    // 1) 가로 구간 스캔
    for(int i = 0; i < n; i++){
        int j = 0;
        while(j < n){
            if(a[i][j] != 1){ j++; continue; }
            int s = j;
            while(j < n && a[i][j] == 1) j++;
            int e = j - 1;
            int len = e - s + 1;
            row_st[i][s] = len;
            row_end[i][e] = len;
            base_max = max(base_max, len);
        }
    }

    // 2) 세로 구간 스캔
    for(int j = 0; j < n; j++){
        int i = 0;
        while(i < n){
            if(a[i][j] != 1){ i++; continue; }
            int s = i;
            while(i < n && a[i][j] == 1) i++;
            int e = i - 1;
            int len = e - s + 1;
            col_st[j][s] = len;
            col_end[j][e] = len;
            base_max = max(base_max, len);
        }
    }

    // 3) \ 대각선 (i - j = k), 인덱스 idx = k + (n-1), 스캔은 i 증가 방향(키는 i)
    for(int k = -(n-1); k <= (n-1); k++){
        int idx = k + (n-1);
        int i = max(0, k), j = i - k;
        while(i < n && j < n){
            if(a[i][j] != 1){ i++; j++; continue; }
            int si = i;
            while(i < n && j < n && a[i][j] == 1){ i++; j++; }
            int ei = i - 1;
            int len = ei - si + 1;
            d1_st[idx][si] = len;
            d1_end[idx][ei] = len;
            base_max = max(base_max, len);
        }
    }

    // 4) / 대각선 (i + j = s), 인덱스 idx = s, 스캔은 i 증가 방향(키는 i)
    for(int s = 0; s <= 2*(n-1); s++){
        int i = max(0, s - (n-1));
        int j = s - i; // j는 감소하며 진행
        while(i < n && j >= 0){
            if(a[i][j] != 1){ i++; j--; continue; }
            int si = i;
            while(i < n && j >= 0 && a[i][j] == 1){ i++; j--; }
            int ei = i - 1;
            int len = ei - si + 1;
            d2_st[s][si] = len;
            d2_end[s][ei] = len;
            base_max = max(base_max, len);
        }
    }

    // 5) 백돌을 흑으로 바꿔 얻는 최대
    int best_with_flip = 1;
    for(auto &w : white){
        int y = w.first, x = w.second;

        // 가로: 왼쪽 끝이 x-1인 구간 + 1 + 오른쪽 시작이 x+1인 구간
        int left  = (x-1 >= 0 && row_end[y].count(x-1) ? row_end[y][x-1] : 0);
        int right = (x+1 <  n && row_st [y].count(x+1) ? row_st [y][x+1] : 0);
        best_with_flip = max(best_with_flip, left + 1 + right);

        // 세로
        int up    = (y-1 >= 0 && col_end[x].count(y-1) ? col_end[x][y-1] : 0);
        int down  = (y+1 <  n && col_st [x].count(y+1) ? col_st [x][y+1] : 0);
        best_with_flip = max(best_with_flip, up + 1 + down);

        // \ 대각선: 키 = i-j
        int k  = y - x, idx1 = k + (n-1);
        int ul = (d1_end[idx1].count(y-1) ? d1_end[idx1][y-1] : 0); // up-left 끝이 y-1
        int dr = (d1_st [idx1].count(y+1) ? d1_st [idx1][y+1] : 0); // down-right 시작이 y+1
        best_with_flip = max(best_with_flip, ul + 1 + dr);

        // / 대각선: 키 = i+j
        int s  = y + x, idx2 = s;
        int ur = (d2_end[idx2].count(y-1) ? d2_end[idx2][y-1] : 0); // up-right의 끝 i=y-1
        int dl = (d2_st [idx2].count(y+1) ? d2_st [idx2][y+1] : 0); // down-left의 시작 i=y+1
        best_with_flip = max(best_with_flip, ur + 1 + dl);
    }

    cout << max(base_max, best_with_flip) << '\n';
    return 0;
}
