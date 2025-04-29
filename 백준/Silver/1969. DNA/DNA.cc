#include <bits/stdc++.h>
using namespace std;

int n, m, alpha[54][26], ret2;
char c;
string ret1;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;
            alpha[j][(int)(c - 'A')]++;
        }
    }
    for(int j = 0; j < m; j++) {
        int max_sum = 0;
        int max_idx = -1;
        for(int t = 0; t < 26; t++) {
            if(max_sum < alpha[j][t]) {
                max_sum = alpha[j][t];
                max_idx = t;
            }
        }   
        ret1 += (char)max_idx + 'A';
        ret2 += (n - max_sum);
    }
    cout << ret1 << "\n";
    cout << ret2 << "\n";
    
    return 0;
}