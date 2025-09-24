#include<bits/stdc++.h>
using namespace std;
int n;
string a, b;
map<string, string> mp;
bool flag = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        mp[a] = b;
    }
    cin >> a >> b;
    string a1 = a, b1 = b;
    while(1) {
        string tmp = mp[a1];
        if(tmp == "") break;
        if(tmp == b1) {
            flag = true;
            break;
        }
        a1 = tmp;
    }
    if(flag) { cout << 1 << "\n"; return 0; }

    string a2 = a, b2 = b;
    while(1) {
        string tmp = mp[b2];
        if(tmp == "") break;
        if(tmp == a2) {
            flag = true;
            break;
        }
        b2 = tmp;
    }
    if(flag) { cout << 1 << "\n"; return 0; }
    
    cout << 0 << "\n";
}