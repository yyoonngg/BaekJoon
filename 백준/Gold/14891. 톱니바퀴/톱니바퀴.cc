#include<bits/stdc++.h>
using namespace std;
int a[4][8], visited[4], n, ret;
// 0 1 2 3 4 5 6 7 -> [2, 6]

void turn(int n, int d) {
    if(d == 1) { // 시계방향
        int last = a[n][7];
        for(int i = 7; i >= 1; i--) {
            a[n][i] = a[n][i - 1];
        }
        a[n][0] = last;
    }

    else { // 반시계방향
        int first = a[n][0];
        for(int i = 0; i < 7; i++) {
            a[n][i] = a[n][i + 1];
        }
        a[n][7] = first;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 8; j++) {
            a[i][j] = (int)s[j]-'0';
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num, dir;
        cin >> num >> dir;
        queue<pair<int, int>> q;
        q.push({--num, dir});
        memset(visited, 0, sizeof(visited));

        while(!q.empty()) {
            int n, d;
            tie(n, d) = q.front(); q.pop();

            visited[n] = 1;
            if((n - 1) >= 0 && a[n - 1][2] != a[n][6] && !visited[n - 1]) {
                q.push({(n - 1), (d * -1)});
            }

            if((n + 1) < 4 && a[n + 1][6] != a[n][2] && !visited[n + 1]) {
                q.push({(n + 1), (d * -1)});
            }

            turn(n, d);
        }
    }

    for(int i = 0; i < 4; i++) {
        if(a[i][0] == 1) ret += pow(2, i);
    }

    cout << ret << "\n";

    return 0;
}