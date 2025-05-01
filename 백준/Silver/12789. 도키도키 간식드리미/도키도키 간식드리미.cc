#include<bits/stdc++.h>
using namespace std;
int n, a[1004], turn = 1;
queue<int> q;
stack<int> stk;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int stu;
        cin >> stu;
        q.push(stu);
    }

    while(!q.empty() || !stk.empty()) {
        if(!q.empty() && q.front() == turn) {
            q.pop();
            turn++;
        }
        else if(!stk.empty() && stk.top() == turn) {
            stk.pop();
            turn++;
        }
        else if(!q.empty()) {
            stk.push(q.front());
            q.pop();
        }
        else {
            cout << "Sad\n";
            return 0;
        }
    }
    cout << "Nice\n";

    return 0;
}