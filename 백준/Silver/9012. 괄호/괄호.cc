#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while(n--) {
        cin >> s;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            if(stk.size() == 0) { stk.push(s[i]); }
            else {
                char c = stk.top();
                if(c == '(' && s[i] == ')') stk.pop();
                else stk.push(s[i]); 
            }
        }
        if(stk.size() != 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}