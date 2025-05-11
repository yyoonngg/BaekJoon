#include <bits/stdc++.h>
using namespace std;
const int MAX = 100004;
int n, k, dist[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    fill(dist, dist + MAX, -1);
    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;

    while(!dq.empty()) {
        int curr = dq.front(); dq.pop_front();

        if(curr == k) break;

        if(curr * 2 < MAX && dist[curr * 2] == -1) {
            dist[curr * 2] = dist[curr] + 1;
            dq.push_front(curr * 2);
        }

        for(int next : {curr - 1, curr + 1}) {
            if(next >= 0 && next < MAX && dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                dq.push_back(next);
            }
        }
    }

    cout << dist[k] << "\n";

    return 0;
}