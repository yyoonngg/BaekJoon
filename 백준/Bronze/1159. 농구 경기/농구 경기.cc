#include<bits/stdc++.h>
using namespace std;
int n, a[26];
string s;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        a[(int)s[0]-'a']++;
    }

    bool flag = true;
    for(int i = 0; i < 26; i++) {
        if(a[i] >= 5) {
            cout << (char)('a' + i);
            flag = false;
        } 
    }
    if(flag) cout << "PREDAJA\n";
    
    return 0;
}