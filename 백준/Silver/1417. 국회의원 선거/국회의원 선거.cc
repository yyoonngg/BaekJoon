#include<bits/stdc++.h>
using namespace std;
int n, dasom, tmp, ret;
priority_queue<int> pq;

int main() {
    cin >> n >> dasom;
    for(int i = 0; i < n - 1; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    while(!pq.empty() && dasom <= pq.top()) {
        dasom++;
        int here = pq.top();
        pq.pop();
        pq.push(here - 1);
        ret++;
    }

    cout << ret << "\n";

    return 0;
}