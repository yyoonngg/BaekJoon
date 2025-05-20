#include <bits/stdc++.h>
using namespace std;
int n;
string s, first, last;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> s;
    int pos = s.find("*");
    first = s.substr(0, pos);
    last = s.substr(pos + 1);

    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s.size() < first.size() + last.size()) cout << "NE\n";
        else if(s.substr(0, first.size()) == first && s.substr(s.size() - last.size()) == last) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}