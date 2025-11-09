#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
string s1, s2;

void ready() {
    s2 = "I";
    for(int i = 0; i < n; i++) s2 += "OI";
}

int main() {
    cin >> n >> m;
    cin >> s1;
    ready();

    for(int i = 0; i < m; i++) {
        bool flag = false;
        for(int j = 0; j < (int)s2.size(); j++) {
            if(s1[i+j] == s2[j]) flag = true;
            else { flag = false; break; }
        }
        if(flag) ret++;
    }

    cout << ret << "\n";
    
    return 0;
}