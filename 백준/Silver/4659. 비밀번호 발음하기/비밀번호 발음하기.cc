#include <bits/stdc++.h>
using namespace std;
string s;
int lcnt, vcnt;
bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(cin >> s) {
        if(s == "end") break;
        lcnt = vcnt = 0;
        bool flag = 0;
        bool is_include_v = 0;
        int prev = -1;
        for(int i = 0; i < (int)s.size(); i++) {
            int idx = s[i];
            if(isVowel(idx)) vcnt++, lcnt = 0, is_include_v = 1;
            else vcnt = 0, lcnt++;
            if(vcnt == 3 || lcnt == 3) flag = 1;
            if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')) flag = 1;
            prev = idx;
        }
        if(is_include_v == 0) flag = 1;
        if(flag) cout << "<" << s << "> is not acceptable.\n";
        else cout << "<" << s << "> is acceptable.\n";
    }
    return 0;
}