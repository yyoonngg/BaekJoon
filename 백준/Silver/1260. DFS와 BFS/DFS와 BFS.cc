#include <bits/stdc++.h>
using namespace std;
int n, m, v, visited[1004];

vector<int> adj[1004];

void dfs(int here) {
    if(visited[here]) return;
    cout << here << " ";
    visited[here] = 1;

    for(int i : adj[here]) {
        dfs(i);
    }    
}

void bfs(int here) {
    queue<int> q;
    q.push(here);
    visited[here] = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i : adj[now]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
        cout << now << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(v);

    fill(visited, visited + 1004, 0);
    cout << "\n";

    bfs(v);

    return 0;
}