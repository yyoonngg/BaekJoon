#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
unordered_set<string> memo;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    ret = n;

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        memo.insert(word);
    }

    for(int i = 0; i < m; i++) {
        string line;
        cin >> line;

        string s;
        for(char ch: line) {
            if(ch == ',') {
                if(memo.erase(s)) ret--;
                s.clear();
            }
            else {
                s += ch;
            }
        }
        if(!s.empty() && memo.erase(s)) ret--;
        cout << ret << "\n";
    }
    return 0;
}