#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b;
    int m = n / a;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < m; i++) pq.push(k);

    int t = 0;
    int days = 0;

    while(true) {
        days++;

        int s = pq.top(); pq.pop();

        if(s - t <= 0) {
            cout << (days - 1) << "\n";
            return 0;
        }

        s += b;
        pq.push(s);

        int mn = pq.top();
        if(mn - t == 1) {
            cout << days << "\n";
            return 0;
        }

        t++;
    }
}