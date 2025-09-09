#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
string str = "";

void go(int x) {
    if(x > n) return;
    if(x == n) {
        ret++;
        if(ret == k) {
            for(int i = 0; i < (int)str.size(); i++) {
                cout << str[i];
                if(i != (int)str.size() - 1) cout << "+";
            }
            cout << "\n";
            exit(0);
        }
        return;
    }

    str += '1';
    go(x + 1);
    str = str.substr(0, (int)str.size() - 1);

    str += '2';
    go(x + 2);
    str = str.substr(0, (int)str.size() - 1);

    str += '3';
    go(x + 3);
    str = str.substr(0, (int)str.size() - 1);


    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    go(0);
    cout << "-1\n";
}