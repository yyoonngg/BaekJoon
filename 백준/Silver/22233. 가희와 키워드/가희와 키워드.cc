#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<string> memo;
    int ret = n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        memo.insert(word);
    }

    for (int i = 0; i < m; i++) {
        string line;
        cin >> line;

        string s;
        for (char ch : line) {
            if (ch == ',') {
                if (memo.erase(s)) ret--; // 존재하면 삭제 및 카운트 감소
                s.clear();
            } else {
                s += ch;
            }
        }

        if (!s.empty() && memo.erase(s)) ret--; // 마지막 키워드
        cout << ret << "\n";
    }

    return 0;
}
