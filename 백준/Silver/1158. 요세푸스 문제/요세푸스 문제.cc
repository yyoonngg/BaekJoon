#include<bits/stdc++.h>
using namespace std;
int n, k, cnt;
queue<int> q;
vector<int> ret;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        cnt++;

        if(cnt == k) {
            cnt = 0;
            ret.push_back(here);
            continue;
        }

        q.push(here);
    }

    for(int i = 0; i < n; i++) {
        if(i == 0) cout << "<";
        cout << ret[i];
        if(i != n - 1) cout << ", ";
        else cout << ">";
    }

    return 0;
}