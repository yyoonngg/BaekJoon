#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, A[304][304], ret = 987654321;

void go(int y, int x, int type) {
    int sum = 0;
    if(type == 1) {
        for(int i = y; i < y + a; i++) {
            for(int j = x; j < x + b + c; j++) {
                sum += A[i][j];
            }
        }
    }
    else if(type == 2) {
        for(int i = y; i < y + a; i++) {
            for(int j = x; j < x + c; j++) {
                sum += A[i][j];
            }
        }
        for(int i = y + a; i < y + a + b; i++) {
            for(int j = x + c; j < x + c + a; j++) {
                sum += A[i][j];
            }
        } 
    }
    else if(type == 3) {
        for(int i = y; i < y + a; i++) {
            for(int j = x; j < x + b; j++) {
                sum += A[i][j];
            }
        }
        for(int i = y + a; i < y + a + c; i++) {
            for(int j = x + b; j < x + b + a; j++) {
                sum += A[i][j];
            }
        }
    }
    ret = min(ret, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> a >> b >> c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 1번
            if(i + a <= n && j + b + c <= m) {
                go(i, j, 1);
            }
            // 2번
            if(i + a + b <= n && j + c + a <= m) {
                go(i, j, 2);
            }
            // 3번
            if(i + a + c <= n && j + b + a <= m) {
                go(i, j, 3);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}