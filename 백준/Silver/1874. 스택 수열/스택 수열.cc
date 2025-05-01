#include<bits/stdc++.h>
using namespace std;
int n, a[100004], idx;
queue<int> q;
stack<int> stk;
vector<int> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        q.push(i + 1);
    }

    while(!q.empty() || !stk.empty()) {
        int here = a[idx];
        
        // pop
        if(!stk.empty() && here == stk.top()) {
            stk.pop();
            idx++;
            v.push_back(-1);
        }
        // push
        else if(!q.empty()) {
            stk.push(q.front());
            q.pop();
            v.push_back(1);
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for(int i : v) {
        if(i > 0) cout << "+\n";
        else cout << "-\n";
    }

    return 0;
}