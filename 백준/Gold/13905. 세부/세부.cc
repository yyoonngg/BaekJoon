#include<bits/stdc++.h>
using namespace std;
int n, m, s, e, high, low, ret;
int visited[100004];
vector<pair<int, int>> adj[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> s >> e;
    for(int i = 0; i < m; i++) {
        int h1, h2, k;
        cin >> h1 >> h2 >> k;
        high = max(high, k);
        low = min(low, k);
        adj[h1].push_back({h2, k}), adj[h2].push_back({h1, k});
    }

    while(low <= high) {
        int mid = (low + high) / 2;

        queue<int> q;
        memset(visited, 0, sizeof(visited));
        q.push(s); visited[s] = 1;
        bool flag = false;

        while(!q.empty()) {
            int here = q.front(); q.pop();
            for(pair<int, int> next : adj[here]) {
                if(next.second >= mid && visited[next.first] == 0) {
                    if(next.first == e) {
                        flag = true;
                        break;
                    }
                    else {
                        q.push(next.first);
                        visited[next.first] = 1;
                    }
                }
            }
            if(flag) break;
        }

        if(flag) {
            low = mid + 1;
            ret = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ret << "\n";
}