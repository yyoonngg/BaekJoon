#include <bits/stdc++.h>
#define time fuxxx
using namespace std;

// 개강총회 시작하기 전
// 개강총회 끝내고, 스트리밍 끝날 때까지

string S, E, Q;
int s, e, q, ret;
string time, name;
unordered_set<string> unset;

int change(string s) {
    int ret = atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 5).c_str());

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> S >> E >> Q;
    s = change(S), e = change(E), q = change(Q);

    while(cin >> time >> name) {
        int t = change(time);
        if(t <= s) {
            unset.insert(name);
        }
        else if(e <= t && t <= q){
            if(unset.erase(name)) ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}