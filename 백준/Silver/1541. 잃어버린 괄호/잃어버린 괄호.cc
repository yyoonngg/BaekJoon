#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;

    vector<string> tokens;
    string temp;

    for(int i = 0; i <= s.size(); i++) {
        if(s[i] == '-' || s[i] == '\0') {
            tokens.push_back(temp);
            temp = "";
        }
        else {
            temp += s[i];
        }
    }

    int result = 0;
    for(int i = 0; i < tokens.size(); i++) {
        int part_sum = 0;
        string num = "";
        for(int j = 0; j <= tokens[i].size(); j++) {
            if(tokens[i][j] == '+' || j == tokens[i].size()) {
                if(!num.empty()) {
                    part_sum += stoi(num);
                    num = "";
                }
            }
            else {
                num += tokens[i][j];
            }
        }
        if(i == 0) result += part_sum;
        else result -= part_sum;
    }

    cout << result << "\n";

    return 0;   
}