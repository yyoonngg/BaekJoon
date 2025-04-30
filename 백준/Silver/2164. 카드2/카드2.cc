#include<bits/stdc++.h>
using namespace std;
int n;
queue<int> q;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(q.size() > 1) {
        q.pop();
        int here = q.front();
        q.pop();
        q.push(here);
    }

    cout << q.front() << "\n";
    return 0;
}