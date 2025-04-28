#include <bits/stdc++.h>
using namespace std;
int n = 9, sum, ret1 = -1, ret2 = -1;
vector<int> v(n);

int main() {
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
        
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(sum - v[i] - v[j] == 100) {
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    cout << v[k] << "\n";
                }
                return 0;
            }
        }
    }
    return 0;
}