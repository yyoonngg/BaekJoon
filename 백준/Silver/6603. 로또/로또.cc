#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void go(int cnt, int sum, int num) {
    if(cnt > (int)v.size()) return;
    if(num == 6) {
        int _cnt = 0;
        for(int i = 0; i < (1 << cnt); i++) {
            if(sum & (1 << i)) {
                cout << v[i] << " ";
                _cnt++;
            }
            if(_cnt == 6) break;
        }
        cout << "\n";
        return;
    }

    go(cnt + 1, sum | (1 << cnt), num + 1);
    go(cnt + 1, sum, num);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    while(true) {
        string s;
        getline(cin, s);
        if(s == "0") break;
    
        v.clear();
        string temp = "";
        for(int i = 2; i < (int)s.size(); i++) {
            if(s[i] != ' ') {
                temp += s[i];
            }
            else if(temp != ""){
                v.push_back(atoi(temp.c_str()));
                temp = "";
            }
        }
        if(temp != "") v.push_back(atoi(temp.c_str()));

        go(1, 1, 1); // 0 & (1 << 0)
        go(1, 0, 0);
        cout << "\n";
    }
    return 0;
}