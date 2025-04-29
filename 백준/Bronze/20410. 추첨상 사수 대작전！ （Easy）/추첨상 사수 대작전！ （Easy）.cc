#include <bits/stdc++.h>
using namespace std;
int m, seed, x1, x2, a, c;

int main() {
    cin >> m >> seed >> x1 >> x2;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            int xx1 = (i * seed + j) % m;
            int xx2 = (i * xx1 + j) % m;
            if(xx1 == x1 && xx2 == x2) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    return 0;
}