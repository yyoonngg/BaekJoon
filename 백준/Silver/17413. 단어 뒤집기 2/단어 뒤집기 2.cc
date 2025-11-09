#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, ret, buffer;
    getline(cin, s);

    bool in_tag = false;

    for (char c : s) {
        if (c == '<') {
            // 단어가 끝났다면 먼저 뒤집어서 추가
            if (!buffer.empty()) {
                reverse(buffer.begin(), buffer.end());
                ret += buffer;
                buffer.clear();
            }
            in_tag = true;
            ret += c;
        }
        else if (c == '>') {
            in_tag = false;
            ret += c;
        }
        else if (in_tag) {
            // 태그 내부는 그대로 출력
            ret += c;
        }
        else if (c == ' ') {
            // 단어 경계 → 현재 단어 뒤집고 공백 추가
            reverse(buffer.begin(), buffer.end());
            ret += buffer + ' ';
            buffer.clear();
        }
        else {
            // 태그 밖의 단어일 때만 버퍼에 쌓기
            buffer += c;
        }
    }

    // 마지막 단어 flush
    if (!buffer.empty()) {
        reverse(buffer.begin(), buffer.end());
        ret += buffer;
    }

    cout << ret << '\n';
    return 0;
}
