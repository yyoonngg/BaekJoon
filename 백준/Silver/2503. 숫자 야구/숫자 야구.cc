#include <bits/stdc++.h>
using namespace std;
int n;
struct Query {
    string guess;
    int s, b;
};
vector<Query> q;

pair<int, int> countSB(const string& cand, const string& guess) {
    int S = 0, B = 0;
    for(int i = 0; i < 3; i++) {
        if(cand[i] == guess[i]) S++;
        else if(cand.find(guess[i]) != string::npos) B++;
    }
    return {S, B};
}
bool valid(int x) {
    int a = x / 100, b = (x / 10) % 10, c = x % 10;
    if(a == 0 || b == 0 || c == 0) return false;
    if(a == b || a == c || b == c) return false;
    return true;
}

int main() {
    cin >> n;
    q.resize(n);

    for(int i = 0; i < n; i++) {
        string g; int s, b;
        cin >> g >> s >> b;
        q[i] = {g, s, b};
    }

    int answer = 0;
    for(int x = 123; x <= 987; x++) {
        if(!valid(x)) continue;
        string cand = to_string(x);

        bool ok = true;
        for(auto &qq: q) {
            auto [S, B] = countSB(cand, qq.guess);
            if(S != qq.s || B != qq.b) { ok = false; break; }
        }
        if(ok) answer++;
    } 

    cout << answer << "\n";
    return 0;
}