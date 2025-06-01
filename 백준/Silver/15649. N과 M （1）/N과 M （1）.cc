#include <bits/stdc++.h>
using namespace std;
int n, m, visited[10];
vector<int> v;

void go(int idx, int cnt) {
    if(cnt == m) {
        for(int vv: v) cout << vv << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        v.push_back(i);
        visited[i] = 1;
        go(i + 1, cnt + 1);
        v.pop_back();
        visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        v.push_back(i);
        visited[i] = 1;
        go(i + 1, 1);
        v.pop_back();
        visited[i] = 0;
    }
    return 0;
}