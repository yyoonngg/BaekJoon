#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int ret;

int main() {
    getline(cin, s1); getline(cin, s2);

    for(int i = 0; i < (int)s1.size() - (int)s2.size() + 1; i++) {
        bool flag = false;
        for(int j = 0; j < (int)s2.size(); j++) {
            if(s1[i+j] == s2[j]) {
                flag = true;
            }   
            else {
                flag = false;
                break;
            } 
        }
        if(flag) {
            ret++;
            i += ((int)s2.size() - 1);
        }
    }

    cout << ret << "\n";


    return 0;
}