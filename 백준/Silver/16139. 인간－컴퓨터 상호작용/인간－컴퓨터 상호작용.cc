#include <bits/stdc++.h>
using namespace std;
int q, l, r, psum[200004][30];
char a;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> q;
    for(int i = 0; i < (int)s.size(); i++) {
        int alpha = (int)(s[i] - 'a');
        for(int j = 0; j < 26; j++) {
            if(j == alpha) {
                psum[i + 1][j] = psum[i][j] + 1;
            }
            else {
                psum[i + 1][j] = psum[i][j];
            }
        }
    }
    while(q--) {
        cin >> a >> l >> r;
        l++; r++;
        int alpha = (int)(a - 'a');
        cout << psum[r][alpha] - psum[l - 1][alpha] << "\n";
    }

    return 0;
}
