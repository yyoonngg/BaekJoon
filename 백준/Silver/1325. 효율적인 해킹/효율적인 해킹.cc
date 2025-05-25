#include <bits/stdc++.h>
using namespace std;
int n, m, visited[10004], mx;
vector<int> adj[10004], ret;

int go(int here) {
    int cnt = 1;

    for(int j: adj[here]) {
        if(visited[j]) continue;
        visited[j] = 1;
        cnt += go(j);
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        fill(&visited[0], &visited[0]+10004, 0);
        visited[i + 1] = 1;
        int cnt = go(i + 1);
        if(mx < cnt) {
            ret.clear();
            mx = cnt;
            ret.push_back(i + 1);
        }
        else if(mx == cnt) ret.push_back(i + 1);
    }
    sort(ret.begin(), ret.end());
    for(int r : ret) cout << r << " ";
    return 0;
}