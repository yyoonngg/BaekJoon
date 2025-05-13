#include <bits/stdc++.h>
using namespace std;
int n, m, visited[104], ret;
vector<int> adj[104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()) {
        int here = q.front();
        q.pop();

        for(int i : adj[here]) {
            if(!visited[i]) {
                visited[i] = 1;
                ret++;
                q.push(i);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}