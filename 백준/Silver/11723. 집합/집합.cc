#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {    
        cin >> s;
        if(s == "add") {
            cin >> m;
            ret = (ret | (1 << (m-1)));
        }
        else if(s == "remove") {
            cin >> m;
            ret = (ret & ~(1 << (m-1)));
        }
        else if(s == "check") {
            cin >> m;
            if(ret & (1 << (m-1))) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "toggle") {
            cin >> m;
            ret = (ret ^ (1 << (m - 1)));
        }
        else if(s == "all") {
            ret |= (1 << 20) - 1;
        }
        else if(s == "empty") {
            ret = 0;
        }
    }
    return 0;
}