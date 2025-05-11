#include <bits/stdc++.h>
using namespace std;
int n, k, visited[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    int cnt = 0;
    bool flag = true;


    while(flag) {
        queue<int> temp_q;

        while(!q.empty()) {
            int here = q.front();
            q.pop();
            visited[here] = 1;

            if(here == k) {
                flag = false;
                cout << cnt << "\n";
                break;
            }

            if(here - 1 >= 0 && here - 1 < 100004 && !visited[here - 1]) temp_q.push(here - 1);
            if(here + 1 >= 0 && here + 1 < 100004 && !visited[here + 1]) temp_q.push(here + 1);
            if(here * 2 >= 0 && here * 2 < 100004 && !visited[here * 2]) temp_q.push(here * 2);
        }
        if(!flag) break;
        q = temp_q;
        cnt++;
    }


    return 0;
}