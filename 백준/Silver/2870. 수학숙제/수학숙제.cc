#include<bits/stdc++.h>
using namespace std;

int n;
string s, tmp;
char c;
vector<string> v;

void go() {
    while(true) {
        if(tmp.size() && tmp.front() == '0') tmp.erase(tmp.begin());
        else break;
    }
    if(tmp.size() == 0) tmp = "0";
    v.push_back(tmp);
    tmp = "";
}

bool cmp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while(n--) {
        cin >> s;
        tmp = "";
        for(int i = 0; i < s.size(); i++) {
            c = s[i];
            if((int)(s[i]-'0') < 10) {
                tmp += s[i];
            }
            else if(tmp.size()) {
                go();
            }
        }
        if(tmp.size()) go();
    }

    sort(v.begin(), v.end(), cmp);
    for(string i : v) cout << i << "\n";
    return 0;
}