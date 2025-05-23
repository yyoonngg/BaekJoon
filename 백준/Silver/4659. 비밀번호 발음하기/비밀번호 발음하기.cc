#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

// 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
// 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.

string s;
const char vowel[] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(1) {
        cin >> s;
        if(s == "end") return 0;
        
        bool isvcnt = false;
        int vcnt = 0;
        int ocnt = 0;
        char tmp = 'A';

        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) { isvcnt=true; vcnt++; ocnt=0; }
            else { ocnt++; vcnt=0; }

            if(ocnt == 3 || vcnt == 3) {
                isvcnt = false; 
                break;
            }
            if(s[i] == tmp && tmp != 'e' && tmp != 'o') {
                isvcnt = false;
                break;
            }
            tmp = s[i];
        }

        if(isvcnt) {
            cout << "<" << s << "> is acceptable.\n";
        }
        else {
            cout << "<" << s << "> is not acceptable.\n";
        }
    }

    return 0;
}