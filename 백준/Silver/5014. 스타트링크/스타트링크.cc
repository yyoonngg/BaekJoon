#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int dist[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    fill(dist, dist + F + 1, -1);

    queue<int> q;
    q.push(S);
    dist[S] = 0;

    while(!q.empty()) {
        int cur = q.front(); 
        q.pop();

        if(cur == G) break;

        int up = cur + U;
        if(up <= F && dist[up] == -1) {
            dist[up] = dist[cur] + 1;
            q.push(up);
        }

        int down = cur - D;
        if(down >= 1 && dist[down] == -1) {
            dist[down] = dist[cur] + 1;
            q.push(down);
        }
    }

    if(dist[G] == -1) cout << "use the stairs\n";
    else cout << dist[G] << "\n";
}
