#include<bits/stdc++.h>
using namespace std;
int n, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;   
        stack<char> stk;
        for(int j = 0; j < (int)s.size(); j++) {
            char c = s[j];
            if(stk.empty()) stk.push(c);
            else {
                char t = stk.top();
                if(t == c) stk.pop();
                else stk.push(c);
            }
        }
        if(stk.empty()) ret++;
    }

    cout << ret << "\n";

    return 0;
} 