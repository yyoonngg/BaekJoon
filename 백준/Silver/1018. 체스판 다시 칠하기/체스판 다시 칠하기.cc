#include <bits/stdc++.h>
using namespace std;
int n, m, ret = 987654321;
int a[54][54], temp[54][54];
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;
            if(c == 'W') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    for(int y = 0; y + 8 <= n; y++) {
        for(int x = 0; x + 8 <= m; x++) {
            // 맨 왼쪽 위칸이 흰색 or 검정
            for(int color = 0; color < 2; color++) {
                memcpy(temp, a, sizeof(a));
                int sum = 0;
                int here = color;
                for(int i = y; i < y + 8; i++) {
                    for(int j = x; j < x + 8; j++) {
                        if(temp[i][j] != here) {
                            sum++;
                            temp[i][j] ^= 1;     
                        }
                        here ^= 1;
                    }
                    here ^= 1;
                }
                ret = min(ret, sum);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}