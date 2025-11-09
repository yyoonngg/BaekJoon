#include <bits/stdc++.h>
using namespace std;
string s, ret;
stack<char> stk;

void make() {
    while(!stk.empty()) {
        char tmp = stk.top(); stk.pop();
        ret += tmp;
    }
}
int main() {
    getline(cin, s);
    
    bool pass = false;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '<') {
            pass = true;
            make();
        }
        else if(s[i] == '>') {
            pass = false;
            ret += s[i];
            continue;
        }

        if(pass) {
            ret += s[i];
            continue;
        }

        if(s[i] == ' ') {
            make();
            ret += ' ';
        }
        else {
            stk.push(s[i]);
        }
    }
    make();

    cout << ret << "\n";
    return 0;
}