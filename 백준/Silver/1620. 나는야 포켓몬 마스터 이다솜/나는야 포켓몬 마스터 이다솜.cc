#include<bits/stdc++.h>
using namespace std;
int n, m;
map<int, string> mp1;
map<string, int> mp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp1[i] = s;
        mp2[s] = i;
    }
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if((int)(s[0] -'0') > 9) {
            cout << mp2[s] << "\n";
        }
        else {
            cout << mp1[atoi(s.c_str())] << "\n";
        }
    }
    return 0;
}