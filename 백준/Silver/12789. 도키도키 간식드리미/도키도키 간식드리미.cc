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

    while(true) {
        if(q.empty() && stk.empty()) break;

        int q_here, stk_here;

        if(!q.empty()) {
            q_here = q.front();
            if(q_here == turn) {
                q.pop();
                turn++;
                continue;
            }
            else {
                if(!stk.empty() && stk.top() == turn) {
                    stk.pop();
                    turn++;
                    continue;
                }
                else {
                    stk.push(q_here);
                    q.pop();
                    continue;
                }
            }
        }
        else {
            stk_here = stk.top();
            if(stk_here == turn) {
                stk.pop();
                turn++;
                continue;
            }
            else {
                cout << "Sad\n";
                return 0;
            }
        }
    }

    cout << "Nice\n";

    return 0;
}