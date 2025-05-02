#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int ipt;
        cin >> ipt;
        if(ipt) {
            pq.push(ipt);
        }
        else if(!pq.empty()) {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}