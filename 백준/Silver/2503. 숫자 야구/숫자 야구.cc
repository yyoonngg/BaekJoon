#include <bits/stdc++.h>
using namespace std;

struct Query {
    string guess;
    int s, b;
};

pair<int,int> countSB(const string& cand, const string& guess) {
    int S = 0, B = 0;
    for (int i = 0; i < 3; ++i) {
        if (cand[i] == guess[i]) ++S;
        else if (cand.find(guess[i]) != string::npos) ++B;
    }
    return {S, B};
}

bool validDigits(int x) {
    // 세 자리, 각 자리 1~9, 모두 서로 다름
    int a = x / 100, b = (x / 10) % 10, c = x % 10;
    if (a == 0 || b == 0 || c == 0) return false;
    if (a == b || a == c || b == c) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<Query> q(N);
    for (int i = 0; i < N; ++i) {
        string g; int s, b;
        cin >> g >> s >> b;
        q[i] = {g, s, b};
    }

    int answer = 0;
    for (int x = 123; x <= 987; ++x) {
        if (!validDigits(x)) continue;
        string cand = to_string(x);

        bool ok = true;
        for (auto &qq : q) {
            auto [S, B] = countSB(cand, qq.guess);
            if (S != qq.s || B != qq.b) { ok = false; break; }
        }
        if (ok) ++answer;
    }

    cout << answer << '\n';
    return 0;
}
