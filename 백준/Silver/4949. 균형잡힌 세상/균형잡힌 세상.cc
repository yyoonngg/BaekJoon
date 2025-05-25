#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true) {
        getline(cin, s);
        if(s == ".") return 0;
        stack<char> stk;
        bool flag = true;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[') {
                stk.push(s[i]);
            }   
            else if(s[i] == ')') {
                if(stk.size() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if(s[i] == ']') {
                if(stk.size() && stk.top() == '[') {
                    stk.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(stk.size()) flag = false;

        if(flag) cout << "yes\n";
        else cout << "no\n";

    }
    return 0;
}