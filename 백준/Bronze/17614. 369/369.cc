#include <bits/stdc++.h>
using namespace std;

int n, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s = to_string(i);
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '3' || s[j] == '6' || s[j] == '9') ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}