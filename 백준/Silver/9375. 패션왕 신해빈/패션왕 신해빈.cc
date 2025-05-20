#include<bits/stdc++.h>
using namespace std;
int m, n;
string s1, s2;

int main() {
    cin >> m;
    while(m--) {
        cin >> n;
        map<string, int> mp;

        for(int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            mp[s2]++;
        }

        int ret = 1;
        for(auto it: mp) {
            ret *= (it.second + 1);
        }

        ret--;
        cout << ret << "\n";
    }
    return 0;
}